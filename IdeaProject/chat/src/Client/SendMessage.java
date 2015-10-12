package Client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

/**
 * Created by 보운 on 2015-10-01.
 */
public class SendMessage implements Runnable {
    private PrintWriter pw;
    private BufferedReader br;
    private Socket s;
    private Scanner in = new Scanner(System.in);

    public SendMessage(Socket s) {
        try {
            this.s = s;
            pw = new PrintWriter(s.getOutputStream(), true);
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            Thread thread = new Thread(this);
            thread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public synchronized void whisper() {
        try {
            while (true) {
                if (ReceiveMessage.udpPort != null) {
                    System.out.println("귓속말 메시지 입력 : ");
                    //String wstr = br.readLine();
                    String wstr = in.nextLine();
                    wstr = "//" + wstr;
                    DatagramSocket ds = new DatagramSocket();
                    InetAddress ia = InetAddress.getByName("127.0.0.1");
                    DatagramPacket dp = new DatagramPacket(wstr.getBytes(), wstr.getBytes().length, ia, ReceiveMessage.udpPort);
                    System.out.println("메시지 전송");
                    ds.send(dp);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (true) {
            Scanner in = new Scanner(System.in);
            String str = in.nextLine();
            if (str.charAt(0) == '/' && str.charAt(1) == 'w') {
                pw.println("/w");
                whisper();
            } else {
                pw.println(str);
            }
            pw.flush();
        }
    }
}
