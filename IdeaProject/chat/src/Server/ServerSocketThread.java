package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ServerSocketThread extends Thread {
    private Socket s;
    private ChatServer cs;
    private PrintWriter pw;
    private BufferedReader br;
    private String name;

    public ServerSocketThread(ChatServer cs, Socket s) {
        this.s = s;
        this.cs = cs;
        System.out.println(s.getInetAddress() + " 님이 입장하였습니다.");
    }

    public void sendMessage(String str) {
        pw.println(str);
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            pw = new PrintWriter(s.getOutputStream(), true);
            sendMessage("대화자 이름을 넣으세요 : ");
            name = br.readLine();
            cs.broadCasting("[" + name + "]" + "님이 입장 하셨습니다.");
            while (true) {
                String strin = br.readLine();
                cs.broadCasting("[" + name + "] " + strin);
            }
        } catch (Exception e) {
            cs.removeClient(this);
        } finally {
            try {
                s.close();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }
}