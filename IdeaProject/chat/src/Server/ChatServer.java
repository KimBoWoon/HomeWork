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

    public ChatServer(ClientVector cv) {
        v = new Vector<Thread>();
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

    public static void printClient() {
        System.out.println("Print Client");
        System.out.println(ClientVector.getClientVector().size());
        for (int i = 0; i < ClientVector.getClientVector().size(); i++) {
            System.out.println("NAME : " + ClientVector.getClientVector().get(i).getName());
            System.out.println("IP : " + ClientVector.getClientVector().get(i).getIp());
            System.out.println("PORT : " + ClientVector.getClientVector().get(i).getPort());
            System.out.println("UDPPORT : " + ClientVector.getClientVector().get(i).getUdpPort());
        }
    }

    public synchronized void addClient(Socket s, String name, String udpPort) {
        ClientInfo c = new ClientInfo(name, s.getInetAddress().getHostAddress(), s.getPort(), udpPort);
        ClientVector.getClientVector().add(c);
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