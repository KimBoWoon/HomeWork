package Client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Socket;

public class ReceiveMessage implements Runnable {
    private Socket s;
    private BufferedReader br;
    private String str1;
    private DatagramSocket ds;
    private DatagramPacket dp;

    public ReceiveMessage(Socket s, DatagramSocket ds) {
        try {
            this.s = s;
            this.ds = ds;
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            Thread ctr = new Thread(this);
            ctr.start();
        } catch (Exception e) {
            System.out.println("소켓 생성 실패!!");
        }
    }

    @Override
    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            while ((str1 = br.readLine()) != null) {
                System.out.println(str1);
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