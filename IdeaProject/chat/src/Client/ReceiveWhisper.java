package Client;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

/**
 * Created by bw on 15. 10. 12.
 */
public class ReceiveWhisper extends Thread {
    private DatagramSocket ds;
    private DatagramPacket dp;

    public ReceiveWhisper(int udpPort) {
        try {
            ds = new DatagramSocket(udpPort);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        super.run();

        try {
            while (true) {
                dp = new DatagramPacket(new byte[1024], 1024);
                ds.receive(dp);
                if (dp.getLength() > 0) {
                    String str1 = new String(dp.getData());
                    if (str1.charAt(0) == 'q' || str1.charAt(0) == 'Q') {
                        break;
                    }
                    System.out.println(str1);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
