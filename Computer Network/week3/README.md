Chapter 2 Problems – Sep. 20

1. Explain what IP address and Port numbers are.

Addressing processes 을 위해, 프로세스는 반드시 자신이 누구인지를 드러내는 identifier, id가 필요하다. 이때 프로세스의 host device가 갖는 주소가 32비트의 IP adress이다. 그런데 디바이스 하나에 여러 프로세스가 있기 때문에, 같은 IP 주소로 들어온 각기 다른 메세지들이 어느 프로세스로 가야 하는지 알 수 없게 된다. 이때 사용되는 것이 port number이다. 예를들어 HTTP는 80번 포트를 주로 사용한다.

마치 음식점에서 주문번호가 없으면 여러 음식이 나왔는데 어느 것이 내 음식인지 바로 알 수 없는 것처럼 생각하면 편할 것 같다.

2. Explain the difference between application and application layer protocol.

Application layer: The application layer of the OSI model provides the first step of getting data onto the network.

Application: Applications are the software programs used by people to communicate over the network. Examples of application software, including HTTP, FTP, e-mail, and others, are used to explain the differences between these two concepts.

=== 3. Explain the typical response time to load a Web page using HTTP in terms of “RTT and file transmission time”

4. Explain why HTTP is stateless.
   만약 HTTP가 stateful할 경우, 클라이언트가 어떤 상품 정보를 로드하기 위한 요청이 서버에 들어왔다고 가정해보자. 이후 클라이언트가 상품을 2개 주문한 것을 서버에 보냈다고 가정해보자. 그러면 서버는 클라이언트가 어떤 상품을 2개 주문했는지, 이전에 상품 정보를 로드해준 서버를 찾아야 한다. 이는 서버 개수가 늘어날수록 성능이 하락하는 상태가 된다. 따라서, HTTP는 stateless 방식을 채택하고, 클라이언트에서 이전에 자신이 요청한 정보를 저장해놓고 해당 메세지를 함께 보내는 식으로 하여 각 서버가 메세지를 독립적으로 처리할 수 있게 되면서 서버의 개수에 비례해 성능이 상승하게 된다.

5. Explain the Web cache (proxy) server and how it gives benefit.

프록시 서버는 웹 사용자가 빈번히 요청하는 데이터를 사용자와 지리적으로 가까운 웹캐시 서버에 보관해 빠른 서비스를 가능하게 하여 원래 웹서버를 대신해 HTTP request를 충족시켜준다. 이러한 서버의 장점은 응답시간을 줄여주고, access link 트래픽을 줄여주며 웹 서버의 부담을 줄여준다.

6. When you send an E-mail using Gmail, how does the E-mail reach to your friend?

1. User Agent가 자신의 mail server에게 메일을 전달한다.
1. 클라이언트 쪽의 Simple Mail Transfer Protocol이 이메일을 받는 사람의 mail server에 TCP connection을 연다.
1. SMTP client가 TCP connection을 통해 msg를 보낸다.
1. receiver's mail server places the msg in Bog's mailbox
1. when receiver wants to read a msg, receiver's UA searches msg from his mailbox

1. (1) Give the operation of DNS when you type in “www.google.com” in your web browser (assume cache in local DNS server is empty).

host -> local -> root -> local -> TLD(Top Level Domain ex) .com, .net, .kr etc..) -> local -> authoritative(ex) google, Naver etc..) -> local -> host

(2) Next, when you type in “www.naver.com” what is the operation of DNS?

Now local DNS(Domain Name System) server knows where is the .com TLD DNS server. So...

host -> local -> TLD -> local -> authoritative -> local -> host

8. Explain client-side buffering and DASH.
   영상을 스트리밍 할 때, network delay가 항상 일정하지 않기 때문에 미리 어느정도 영상을 다운받은 후에 영상을 재생한다. 그것이 client side buffering 이다.

DASH는 Dynamic, Adaptive Streaming over HTTP 의 줄임말이다. 이것은 영상을 여러 개의 chunk로 조각내고, 각 chunk를 받아 영상을 재생하는 방법이다. 이때, chunk에는 영상의 정보가 담긴 url 이 담겨있으며 이 url은 각 청크 당 하나가 아니라, network 사정에 따라 유연하게 대처하기 위해 여러 화질을 갖는 url이 있다. DASH를 위해 가장 중요한 것은 manifest file 인데, 이것은 각 청크의 url 정보를 담은 file이다. 그러니까 사용자는 결국 이 파일을 받아서, chunk의 url 정보를 모두 받아놓고, 네트워크 상황에 맞춰서 각 화질에 따른 url을 받고 비디오 서버에게 HTTP request를 보낸다. 거기에 해당하는 chunk, url을 마치 웹페이지 다운받듯이 video streaming이 가능해진다.

9. When you play a video from Netflix, explain how CDN operates.
