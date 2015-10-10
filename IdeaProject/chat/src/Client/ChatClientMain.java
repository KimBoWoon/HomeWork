package Client;

import Server.ChatServer;
import Server.ChatServerMain;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.Socket;
import java.util.Scanner;

public class ChatClientMain {
    private static Socket s;
    private static DatagramSocket ds;
    private static Scanner in;

    public static void main(String[] args) {
        try {
            int udpPort;
            in = new Scanner(System.in);

            System.out.print("귓속말에 사용할 포트번호를 입력해주세요 : ");
            udpPort = in.nextInt();

            s = new Socket("127.0.0.1", 9190);
            ds = new DatagramSocket(udpPort);

            ChatServerMain.clientInfos.add(new ClientInfo("127.0.0.1", 9190, udpPort));

            ReceiveMessage bp = new ReceiveMessage(s, ds);
            SendMessage send = new SendMessage(s, ds);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}