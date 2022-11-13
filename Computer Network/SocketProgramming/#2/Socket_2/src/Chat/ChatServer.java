package Chat;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/**
 * A multithreaded chat room server.  When a client connects the
 * server requests a screen name by sending the client the
 * text "SUBMITNAME", and keeps requesting a name until
 * a unique one is received.  After a client submits a unique
 * name, the server acknowledges with "NAMEACCEPTED".  Then
 * all messages from that client will be broadcast to all other
 * clients that have submitted a unique screen name.  The
 * broadcast messages are prefixed with "MESSAGE ".
 *
 * Because this is just a teaching example to illustrate a simple
 * chat server, there are a few features that have been left out.
 * Two are very useful and belong in production code:
 *
 *     1. The protocol should be enhanced so that the client can
 *        send clean disconnect messages to the server.
 *
 *     2. The server should do some logging.
 */
public class ChatServer {

    /**
     * The port that the server listens on.
     */
    private static final int PORT = 8080;

    /**
     * The set of all names of clients in the chat room.  Maintained
     * so that we can check that new clients are not registering name
     * already in use.
     */
    private static HashSet<String> names = new HashSet<String>();
    /**
     * The set of all the print writers for all the clients.  This
     * set is kept so we can easily broadcast messages.
     */
    private static HashSet<PrintWriter> writers = new HashSet<PrintWriter>();
    
    // 귓속말을 위한 매핑
    private static Map<String, PrintWriter> map = new HashMap<String, PrintWriter>();
    
    // 현재 컴퓨터의 로컬IP주소 가져오기
    private static String getServerIp() {
		
    	InetAddress local = null;
    	try {
    		local = InetAddress.getLocalHost();
    	}
    	catch ( UnknownHostException e ) {
    		e.printStackTrace();
    	}
    		
    	if( local == null ) {
    		return "";
    	}
    	else {
    		String ip = local.getHostAddress();
    		return ip;
    	}  		
    }

    /**
     * The appplication main method, which just listens on a port and
     * spawns handler threads.
     */
    public static void main(String[] args) throws Exception {
        System.out.println("The chat server is running.");
        
        // serverinfo.txt 에 로컬 IP 주소와 포트넘버를 작성한다. 
        PrintWriter pw = new PrintWriter(new FileWriter("serverinfo.txt"));
		pw.println(getServerIp() + "/" + PORT);
		pw.close();
		
        ServerSocket listener = new ServerSocket(PORT);
        try {
            while (true) {
                new Handler(listener.accept()).start();
            }
        } finally {
            listener.close();
        }
    }

    /**
     * A handler thread class.  Handlers are spawned from the listening
     * loop and are responsible for a dealing with a single client
     * and broadcasting its messages.
     */
    private static class Handler extends Thread {
        private String name;
        private Socket socket;
        private BufferedReader in;
        private PrintWriter out;

        /**
         * Constructs a handler thread, squirreling away the socket.
         * All the interesting work is done in the run method.
         */
        public Handler(Socket socket) {
            this.socket = socket;
        }

        /**
         * Services this thread's client by repeatedly requesting a
         * screen name until a unique one has been submitted, then
         * acknowledges the name and registers the output stream for
         * the client in a global set, then repeatedly gets inputs and
         * broadcasts them.
         */
        public void run() {
            try {

                // Create character streams for the socket.
                in = new BufferedReader(new InputStreamReader(
                    socket.getInputStream()));
                out = new PrintWriter(socket.getOutputStream(), true);

                // Request a name from this client.  Keep requesting until
                // a name is submitted that is not already used.  Note that
                // checking for the existence of a name and adding the name
                // must be done while locking the set of names.
                while (true) {
                    out.println("SUBMITNAME");
                    // out.println 으로 클라이언트에게 메세지를 보낸다. 
                    
                    name = in.readLine();
                    if (name == null) {
                        return;
                    }
                    synchronized (names) {
                        if (!names.contains(name)) {
                            names.add(name);
                            break;
                        }
                    }
                }

                // Now that a successful name has been chosen, add the
                // socket's print writer to the set of all writers so
                // this client can receive broadcast messages.
                out.println("NAMEACCEPTED");              
                writers.add(out);
                // 귓속말을 위한 매핑
                map.put(name, out);
                
                // 여기에다 ~님 입장 멘트를 치자
                for (PrintWriter writer : writers) {
                    writer.println("ENTER " + name + " has entered");                 
                    String buffer = new String();
                 // 누군가 입장했으면, 모든 클라이언트에 대하여 리스트를 업데이트 해줘야 한다. 
                    for(String user : names) {
                    	buffer += user + "/";
                    }
                    writer.println("LISTUPDATE " + buffer);
                }
                
                // Accept messages from this client and broadcast them.
                // Ignore other clients that cannot be broadcasted to.
                while (true) {
                    String input = in.readLine();
                    if (input == null) {
                        return;
                    }
                    // 여기에서 귓속말 이벤트를 관리해야한다. 
                    if (input.startsWith("WHISPER")) {
                    	// 귓속말이 온다는 것은, 그 해당 이름을 가진 클라이언트의 PrintWriter이 무엇인지 알아야 한다는 것이다. 
                    	String arr[] = input.substring(8).split("&");
                    	// arr[0] = 보낸 사람
                    	// arr[1] = 받는 사람
                    	// arr[2] = 메세지내용                	                                   	
                    	map.get(arr[1]).println(input);                    
                    }
                    else {
                    	for (PrintWriter writer : writers) {
                            writer.println("MESSAGE " + name + ": " + input);
                        }
                    }
                    
                }
            } catch (IOException e) {
                System.out.println(e);                                          
            } finally {
                // This client is going down!  Remove its name and its print
                // writer from the sets, and close its socket.
                if (name != null) {
                	// 여기서, ~님 퇴장 메세지를 전하자. 
                	for (PrintWriter writer : writers) {
                        writer.println("EXIT " + name);
                    }              	
                    names.remove(name);
                    map.remove(name);
                }
                if (out != null) {
                    writers.remove(out);
                }                           
                try {
                    socket.close();
                } catch (IOException e) {
                }
            }
        }
    }
}