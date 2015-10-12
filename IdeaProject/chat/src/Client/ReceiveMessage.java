package Client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

/**
 * Created by 보운 on 2015-10-06.
 */
public class ReceiveMessage implements Runnable {
    private Socket s;
    private BufferedReader br;
    private String str1;
    //private Scanner in = new Scanner(System.in);
    public static Integer udpPort;

    public ReceiveMessage(Socket s) {
        try {
            this.s = s;
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            Thread ctr = new Thread(this);
            ctr.start();
        } catch (Exception e) {
            System.out.println("소켓 생성 실패!!");
        }
    }

    public synchronized void whisper() {
        try {
            udpPort = Integer.valueOf(str1.substring(2, str1.length()));
            System.out.println(udpPort);
            DatagramSocket ds = new DatagramSocket(udpPort);
            DatagramPacket dp = new DatagramPacket(new byte[1024], 1024);

            while (true) {
                ds.receive(dp);
                if (dp.getLength() > 0) {

                    System.out.println("메시지 받음");
                    String str1 = new String(dp.getData()).trim();
                    System.out.println(str1);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            while ((str1 = br.readLine()) != null) {
                if (str1.charAt(0) == '/' && str1.charAt(1) == 'w') {
                    whisper();
                } else {
                    System.out.println(str1);
                }
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                s.close();
            } catch (Exception ea) {
                ea.getMessage();
            }
        }
    }
}