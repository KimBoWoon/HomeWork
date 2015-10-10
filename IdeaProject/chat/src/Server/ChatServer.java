package Server;

import Client.ClientInfo;

import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

public class ChatServer {
    private ServerSocket ss;
    private Socket s;
    private Vector<Thread> v;

    public ChatServer() {
        v = new Vector<Thread>();
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