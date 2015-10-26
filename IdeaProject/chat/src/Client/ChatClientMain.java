package Client;

/**
 * Created by 보운 on 2015-10-06.
 */

import java.io.IOException;
import java.net.Socket;

public class ChatClientMain {
    private static Socket s;

    public static void main(String[] args) {
        try {
            s = new Socket("192.168.0.15", 9190);

            ReceiveMessage bp = new ReceiveMessage(s);
            SendMessage send = new SendMessage(s);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}