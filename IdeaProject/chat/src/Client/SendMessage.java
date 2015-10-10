package Client;

import Server.ChatServer;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;
import java.util.Vector;

/**
 * Created by 보운 on 2015-10-01.
 */
public class SendMessage implements Runnable {
    private PrintWriter pw;
    private Socket s;
    private DatagramPacket dp;
    private InetAddress ia;
    private DatagramSocket ds;

    public SendMessage(Socket s) {
        try {
            this.s = s;
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
            Scanner in = new Scanner(System.in);
            String str = in.nextLine();
            if (str.charAt(0) == '/' && str.charAt(1) == 'w') {
                pw.println("Asfasfefa");
            } else {
                pw.println(str);
                pw.flush();
            }
        }
    }
}
