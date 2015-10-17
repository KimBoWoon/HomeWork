package Client;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 * Created by 보운 on 2015-10-01.
 */
public class SendMessage implements Runnable {
    private PrintWriter pw;
    private Scanner in;
    private String str;

    public SendMessage(Socket s) {
        try {
            str = in.nextLine();
            in = new Scanner(System.in);
            pw = new PrintWriter(s.getOutputStream(), true);
            Thread thread = new Thread(this);
            thread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (true) {
            if (str.charAt(0) == '/' && str.charAt(1) == 'w') {
                pw.println("/w");
            } else {
                pw.println(str);
            }
            pw.flush();
        }
    }
}
