package Server;

import Client.ClientInfo;
import Client.ClientVector;

import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

/**
 * Created by 보운 on 2015-10-06.
 */
public class ChatServer {
    private ServerSocket ss;
    private Socket s;
    private Vector<Thread> v;
    private ClientVector cv;

    public ChatServer(ClientVector cv) {
        v = new Vector<Thread>();
        this.cv = cv;
        System.out.println("서버가 시작되었습니다.");

        try {
            ss = new ServerSocket(9190);
            ss.setReuseAddress(true);
            while (true) {
                s = ss.accept();
                ServerSocketThread svrth = new ServerSocketThread(this, s, cv);
                addClient(svrth);
                svrth.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void printClient() {
        System.out.println("<--현재 접속중인 사용자 목록-->");
        for (int i = 0; i < cv.vectorSize(); i++) {
            System.out.println("NAME : " + cv.getClientInfos().get(i).getName());
            System.out.println("IP : " + cv.getClientInfos().get(i).getIp());
            System.out.println("PORT : " + cv.getClientInfos().get(i).getPort());
            System.out.println("UDPPORT : " + cv.getClientInfos().get(i).getUdpPort());
        }
    }

    public synchronized void addClient(Socket s, String name, String udpPort) {
        ClientInfo c = new ClientInfo(name, s.getInetAddress().getHostAddress(), s.getPort(), udpPort);
        cv.getClientInfos().add(c);
        printClient();
    }

    public synchronized void addClient(Thread tr) {
        v.add(tr);
        System.out.println("Client 1명 입장, 총 " + v.size() + "명");
    }

    public synchronized void removeClient(Thread tr) {
        v.remove(tr);
        System.out.println("Client 1명 퇴장 총 " + v.size() + "명");
    }

    public synchronized void broadCasting(String sbc) {
        for (int i = 0; i < v.size(); i++) {
            ServerSocketThread svtr = (ServerSocketThread) v.get(i);
            svtr.sendMessage(sbc);
        }
    }
}