package Chat;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

import javax.swing.*;
import java.awt.*;

/*
 * 
 * 리스트 만들기, 입장, 퇴장 메세지 전하기 완료
 * 리스트 이벤트 핸들러 구현하기 
 * 
 */

/**
 * A simple Swing-based client for the chat server.  Graphically
 * it is a frame with a text field for entering messages and a
 * textarea to see the whole dialog.
 *
 * The client follows the Chat Protocol which is as follows.
 * When the server sends "SUBMITNAME" the client replies with the
 * desired screen name.  The server will keep sending "SUBMITNAME"
 * requests as long as the client submits screen names that are
 * already in use.  When the server sends a line beginning
 * with "NAMEACCEPTED" the client is now allowed to start
 * sending the server arbitrary strings to be broadcast to all
 * chatters connected to the server.  When the server sends a
 * line beginning with "MESSAGE " then all characters following
 * this string should be displayed in its message area.
 */
public class ChatClient implements ActionListener,MouseListener{

    BufferedReader in;
    PrintWriter out;
    JFrame mainFrame = new JFrame("Chatter");
    JTextField textField = new JTextField(40);
    JTextArea messageArea = new JTextArea(25, 40);
    
    String name = null;
    List guestList;   
    MenuItem menuItem;
    PopupMenu popUpMenu;
    JDialog dialog;
    Button secretMsgButton;
    JTextField secretTextField;

    /**
     * Constructs the client by laying out the GUI and registering a
     * listener with the textfield so that pressing Return in the
     * listener sends the textfield contents to the server.  Note
     * however that the textfield is initially NOT editable, and
     * only becomes editable AFTER the client receives the NAMEACCEPTED
     * message from the server.
     */
    public ChatClient() {
    	
    	menuItem = new MenuItem("whisper");
    	popUpMenu = new PopupMenu();
    	popUpMenu.add(menuItem);
    	dialog = new JDialog();  	
    	secretMsgButton = new Button("Whisper");
    	guestList = new List(); 
    	secretTextField = new JTextField();
    	
    	guestList.add(popUpMenu);
    	guestList.setBackground(Color.PINK);  	
    	textField.setBackground(Color.LIGHT_GRAY);
    	messageArea.setSelectedTextColor(Color.blue);  	
    	messageArea.setAutoscrolls(true);
    
    	Panel northPanel = new Panel();
        Panel southPanel = new Panel();
        
        JScrollPane sPane = new JScrollPane(messageArea);
        
        northPanel.setLayout(new BorderLayout());
		southPanel.setLayout(new BorderLayout());		
		northPanel.add(sPane, "West");		
		northPanel.add(guestList, "East");
		southPanel.add(textField);
		mainFrame.add(northPanel, "Center");
		mainFrame.add(southPanel, "South");
		
		
		guestList.addMouseListener(this);
		secretTextField.addActionListener(this);
		secretMsgButton.addActionListener(this);		
		menuItem.addActionListener(this);

        // Layout GUI
        textField.setEditable(false);
        messageArea.setEditable(false);       
        mainFrame.pack();

        // Add Listeners
        textField.addActionListener(new ActionListener() {
            /**
             * Responds to pressing the enter key in the textfield by sending
             * the contents of the text field to the server.    Then clear
             * the text area in preparation for the next message.
             */
            public void actionPerformed(ActionEvent e) {
                out.println(textField.getText());
                textField.setText("");
            }
        });
    }

    /**
     * Prompt for and return the address of the server.
     */
//    private String getServerAddress() {
//        return JOptionPane.showInputDialog(
//            mainFrame,
//            "Enter IP Address of the Server:",
//            "Welcome to the Chatter",
//            JOptionPane.QUESTION_MESSAGE);
//    }

    /**
     * Prompt for and return the desired screen name.
     */
    private String getName() {
        return JOptionPane.showInputDialog(
            mainFrame,
            "Choose your nickname:",
            "Screen name selection",
            JOptionPane.PLAIN_MESSAGE);
    }
    
    private void whisperError() {
    	JOptionPane.showMessageDialog(
    			mainFrame,
    			"You can't whisper to yourself.",
    			"Whisper Error",
                JOptionPane.ERROR_MESSAGE
                );
    }
    
    private void addMsg(String msg)
    {
      LocalTime now = LocalTime.now();
      DateTimeFormatter DTF = DateTimeFormatter.ofPattern("HH:mm:ss");
      String Now = now.format(DTF);
         
      messageArea.append("(" + Now + ") " + msg);  
      messageArea.setCaretPosition(messageArea.getDocument().getLength());  
    }

    /**
     * Connects to the server then enters the processing loop.
     */
    private void run() throws IOException {   	
        // Make connection and initialize streams
        String serverAddress = null;     
        int port = 0;
        BufferedReader br = new BufferedReader(new FileReader("serverinfo.txt"));
        while(true) {
            String line = br.readLine();
            if (line==null) break;
            
            String[] linebuffer = line.split("/");
            serverAddress = linebuffer[0];
            port = Integer.parseInt(linebuffer[1]);
        }
        
        Socket socket = new Socket(serverAddress, port);
        in = new BufferedReader(new InputStreamReader(
            socket.getInputStream()));
        out = new PrintWriter(socket.getOutputStream(), true);

        // Process all messages from server, according to the protocol.
        while (true) {
            String line = in.readLine();
            // in.readLine으로 서버에서 전송한 정보를 받는다.  
            
            if (line.startsWith("SUBMITNAME")) {
            	name = getName(); 
                out.println(name);
                // out으로 서버에게 이름을 보낸다.                               
            } else if (line.startsWith("NAMEACCEPTED")) {
                textField.setEditable(true);
                mainFrame.setTitle(name + "'s chat room");
            } else if (line.startsWith("MESSAGE")) {
            	addMsg(line.substring(8) + "\n");              
            }  else if (line.startsWith("ENTER")) {           	
            	addMsg(line.substring(6) + "\n");
            } else if (line.startsWith("LISTUPDATE")) {   
            	guestList.removeAll();
            	String array[] = line.substring(11).split("/");
            	int len = array.length;
            	for (int i = 0; i < len; i++) {
            		guestList.add(array[i]);          
            	}
            } else if (line.startsWith("EXIT")) {  
            	String leaveUser = line.substring(5);
            	addMsg(line.substring(5) + " has left\n");
                guestList.remove(leaveUser);
            } else if (line.startsWith("WHISPER")) {  
            	String arr[] = line.substring(8).split("&");
            	// arr[0] = 보낸 사람
            	// arr[1] = 받는 사람
            	// arr[2] = 메세지내용
            	
            	addMsg("[Whisper Message FROM] " + arr[0] + " : " + arr[2] + "\n");                     
            }
           
        }
    }

    /**
     * Runs the client as an application with a closeable frame.
     */
    public static void main(String[] args) throws Exception {
        ChatClient client = new ChatClient();
        client.mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        client.mainFrame.setVisible(true);
        client.run();
    }

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(java.awt.event.MouseEvent e) {
		if(e.getButton()==3 && guestList.getSelectedItem() != null ){
			popUpMenu.show(guestList, e.getX(), e.getY());
		}
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == secretMsgButton){
			try {
				addMsg("[Whisper Message TO] "+guestList.getSelectedItem()+ " : "+secretTextField.getText()+"\n");	
				out.println("WHISPER "+name+"&"+guestList.getSelectedItem()+"&"+secretTextField.getText());
				dialog.setVisible(false);
				dialog.dispose();
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		else if(e.getSource() == menuItem){
			
			// 자신한테 whisper msg를 보내는 건 의미없으므로
			if(name.equals(guestList.getSelectedItem())) {
				whisperError();
				return;
			}
			
			dialog.add(secretTextField);
			secretTextField.setBackground(Color.LIGHT_GRAY);
			dialog.add(secretMsgButton);
			dialog.setTitle("Whisper to "+ guestList.getSelectedItem());
			dialog.setSize(230, 105);
			dialog.setLayout(new GridLayout(2,0));
			dialog.setLocationRelativeTo(mainFrame);
			
			dialog.setVisible(true);
		}	
		
	}
}