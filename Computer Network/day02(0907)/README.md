Chapter 1 Problems – Sep 6

1. Why do we use packets in the network, and what is a packet header?

packet은 데이터 조각의 단위로, 네트워크 상에서 데이터를 전송할 때 데이터를 한꺼번에 보내는 것이 아니라 패킷 단위로 쪼개서 보내게 된다. 그 이유는 혹시 모를 데이터 손실에 유연하게 대응하기 위해서이다. packet header은 각 패킷이 전송 후에 위치할 곳으로 갈 수 있는 주소를 갖고 있는 곳이다.

2. Explain each role of the Link layer and Network layer.

Link Layer은 48비트의 MAC address을 사용하여 device to device 소통 방식을 사용한다. 이러한 방식은, 네트워크 범위 내의 모든 이웃한 네트워크 디바이스에게 가서 그곳이 내가 찾는 주소가 맞는지 찾아봐야 하는 broadcasting을 해줘야 한다. 이는 작은 네트워크 범위 내에서는 괜찮을지 모르지만, 네트워크 범위가 커지면 시간도 오래 걸리고 비용도 많이 들게 되는 단점이 된다. 이를 해결하기 위해 사용되는 것이 Network layer 이며, 이는 32비트의 IP address을 사용하여 router을 통해 packet의 목적지로 갈 수 있게 하는 방식으로 해결할 수 있다.

3. Suppose users share a 2 Mbps link. Also suppose each user transmits continuously at 1 Mbps when transmitting, but each user transmits only 20 percent of the time.A. When circuit switching is used, how many users can be supported?

circuut switching 은, 반드시 사용하려는 link의 circuit을 예약해야만 한다. 이때 link의 속도가 2Mb/s 이고, 사용자는 1Mb/s 이므로 최대 두명까지 해당 링크를 사용 가능하다.

B. Suppose now there are three users. Find the probability that at any given time, all three users are transmitting simultaneously.

0%. 불가능하다. 세 명의 유저가 동시에 전송을 하게 되면, 공유하는 Link의 속도를 넘어서게 된다.

4. Consider the link between A and B as shown below. Host A wants to send a 1000-bit packet to B. What is the transmission delay and propagation delay? Assume that the bit propagation speed is 10^6 m/s.

A ----- B (100m, 1Mb/s)

1Mb = 8 \* 10^6 bit

Transmission delay = L(L-bit packet) / R(R-bps) second
= 10^3 / 8 _ 10^6 sec
= 1 / 8 _ 10^3 sec
= 1 / 8 msec
= 0.125 msec

propagation delay = length of physical link(m) / propagation speed(m/sec)
= 100 / 10^6 sec
= 1 / 10^4 sec
= 1/ 10 msec
= 0.1 msec

5. Explain each role of Tier-1, Regional and Access ISP.

Tier-1 = one global ISP가 불가능하기 때문에, several semi-global ISP가 전체 Access ISP를 연결해 주는데, 이를 Tier-1 ISP라고 부른다. Sprint, AT&T, NTT 등이 있다.
Regional = Tier-1 ISP들은 너무 크기 때문에 Access ISP 하나하나를 관리할 수 없다. 따라서 Access ISP들과 Tier-1 ISP들을 연결해 주는 것이 Reigional ISP이다.
Access ISP = End Systems, 즉 사용자들은 Internet Service Providers을 통해 인터넷에 연결한다. Internet structure 에서 가장 사용자와 밀접하게 연관되어 있다.
