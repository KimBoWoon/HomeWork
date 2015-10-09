package socket;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class BasicServerSocket {
    public static void main(String[] args) {
        try {
            System.out.println(">> ������ �����մϴ�.");
            ServerSocket myServerSocket = new ServerSocket(7070);
            System.out.println(">> Ŭ���̾�Ʈ�� �����ϱ� ��ٸ��� �ֽ��ϴ�.");

            // Ŭ���̾�Ʈ ���Ӷ����� ���
            Socket mySocket = myServerSocket.accept();
            System.out.println(">> Ŭ���̾�Ʈ�� ���ӿ� �����߽��ϴ�.");

            //Ŭ���̾�Ʈ ���Ͽ� ��Ʈ���� ����
            BufferedReader in = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
            PrintWriter out = new PrintWriter(new OutputStreamWriter(mySocket.getOutputStream()));

            //Ŭ���̾�Ʈ �������κ��� ���� �޽����� ȭ�鿡 ���
            System.out.println("[Ŭ���̾�Ʈ] " + in.readLine());

            // Ŭ���̾�Ʈ ���Ͽ� �޽��� ����
            String msg = "������ �����Ͻ� ���� ȯ���մϴ�!";
            out.println(msg);
            out.flush();
            System.out.println("[����] " + msg);

            // Ŭ���̾�Ʈ ���� ����
            mySocket.close();
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
}