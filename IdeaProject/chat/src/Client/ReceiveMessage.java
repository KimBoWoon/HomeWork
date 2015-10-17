package Client;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * Created by 보운 on 2015-10-06.
 */
public class ReceiveMessage implements Runnable {
    private Socket s;
    private BufferedReader br;
    private String str1;
    private int udpPort;

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

    public synchronized void createWhisperThread(int udpPort) {
        ReceiveWhisper rw = new ReceiveWhisper(udpPort);
        rw.start();
    }

    @Override
    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            while ((str1 = br.readLine()) != null) {
                if (str1.charAt(0) == '/' && str1.charAt(1) == 'w') {
                    udpPort = Integer.valueOf(str1.substring(2, str1.length()));
                    createWhisperThread(udpPort);
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