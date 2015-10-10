package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 * Created by 보운 on 2015-10-06.
 */
public class ServerSocketThread extends Thread {
    private Socket s;
    private ChatServer cs;
    private PrintWriter pw;
    private BufferedReader br;
    private String name;
    private String udpPort;
    private Scanner in = new Scanner(System.in);

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
            sendMessage("귓속말에 사용할 포트번호를 입력해주세요 : ");
            udpPort = br.readLine();
            sendMessage("대화자 이름을 넣으세요 : ");
            name = br.readLine();
            cs.broadCasting("[" + name + "]" + "님이 입장 하셨습니다.");
            cs.addClient(s, name, udpPort);
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