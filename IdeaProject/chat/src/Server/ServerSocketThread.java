package Server;

import Client.ClientVector;
import Client.ReceiveMessage;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
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

    public synchronized void sendMessage(String str) {
        pw.println(str);
        pw.flush();
    }

    public synchronized void printClient() {
        for (int i = 0; i < cv.vectorSize(); i++)
            sendMessage((i + 1) + " " + cv.getClientInfos().get(i).getName());
    }

    public synchronized void sendUDPPORT() {
        try {
            sendMessage("귓속말 상대방을 입력하세요 : ");
            user = Integer.valueOf(br.readLine());
            DatagramSocket ds = new DatagramSocket();
            InetAddress ia = InetAddress.getByName(cv.getClientInfos().get(user - 1).getIp());
            while (true) {
                sendMessage("귓속말 메시지 입력 : ");
                String wstr = br.readLine();
                if ((wstr.charAt(0) == 'q' || wstr.charAt(0) == 'Q') && wstr.length() == 1) {
                    sendMessage("귓속말 종료");
                    DatagramPacket dp = new DatagramPacket("q".getBytes(), "q".getBytes().length, ia,
                            Integer.valueOf(cv.getClientInfos().get(user - 1).getUdpPort()));
                    ds.send(dp);
                    break;
                }
                wstr = "Whisper : [" + name + "] " + wstr;
                DatagramPacket dp = new DatagramPacket(wstr.getBytes(), wstr.getBytes().length, ia,
                        Integer.valueOf(cv.getClientInfos().get(user - 1).getUdpPort()));
                ds.send(dp);
            }
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
            sendMessage("/w" + udpPort);
            sendMessage("대화자 이름을 넣으세요 : ");
            name = br.readLine();
            cs.broadCasting("[" + name + "]" + "님이 입장 하셨습니다.");
            cs.addClient(s, name, udpPort);
            while (true) {
                String strin = br.readLine();
                if (strin.charAt(0) == '/' && strin.charAt(1) == 'w') {
                    printClient();
                    sendUDPPORT();
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