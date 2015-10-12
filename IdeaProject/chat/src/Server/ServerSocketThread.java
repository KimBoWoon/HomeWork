package Server;

import Client.ClientVector;

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
    private ClientVector cv;
    private int user;

    public ServerSocketThread(ChatServer cs, Socket s, ClientVector cv) {
        this.s = s;
        this.cs = cs;
        this.cv = cv;
        System.out.println(s.getInetAddress() + " 님이 입장하였습니다.");
    }

    public void sendMessage(String str) {
        pw.println(str);
        pw.flush();
    }
    public void printClient() {
        for (int i = 0;i < cv.vectorSize();i++)
            sendMessage((i + 1) + " " +  cv.getClientInfos().get(i).getName());
    }

    public void sendUDPPORT() {
        try {
            sendMessage("귓속말 상대방을 입력하세요 : ");
            user = Integer.valueOf(br.readLine());
            sendMessage("/w" + cv.getClientInfos().get(user - 1).getUdpPort());
        } catch (Exception e) {
            e.printStackTrace();
        }
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
                if (strin.charAt(0) == '/' && strin.charAt(1) == 'w') {
                    printClient();
                    sendUDPPORT();
                } else if (strin.charAt(0) == '/' && strin.charAt(1) == '/') {

                } else {
                    cs.broadCasting("[" + name + "] " + strin);
                }
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