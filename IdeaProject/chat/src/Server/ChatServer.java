package Server;

import Client.ClientInfo;

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
    private Vector<ClientInfo> clientInfos;

    public ChatServer() {
        v = new Vector<Thread>();
        clientInfos = new Vector<ClientInfo>();
        System.out.println("서버가 시작되었습니다.");

        try {
            ss = new ServerSocket(9190);
            ss.setReuseAddress(true);
            while (true) {
                s = ss.accept();
                ServerSocketThread svrth = new ServerSocketThread(this, s);
                addClient(svrth);
                svrth.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void printClient() {
        for (int i = 0; i < clientInfos.size(); i++) {
            System.out.println("NAME : " + clientInfos.get(i).getName());
            System.out.println("IP : " + clientInfos.get(i).getIp());
            System.out.println("PORT : " + clientInfos.get(i).getPort());
            System.out.println("UDPPORT : " + clientInfos.get(i).getUdpPort());
        }
    }

    public synchronized void addClient(Socket s, String name, String udpPort) {
        ClientInfo c = new ClientInfo(name, s.getInetAddress().getHostAddress(), s.getPort(), udpPort);
        clientInfos.add(c);
        for (int i = 0; i < clientInfos.size(); i++) {
            System.out.println("NAME : " + clientInfos.get(i).getName());
            System.out.println("IP : " + clientInfos.get(i).getIp());
            System.out.println("PORT : " + clientInfos.get(i).getPort());
            System.out.println("UDPPORT : " + clientInfos.get(i).getUdpPort());
        }
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