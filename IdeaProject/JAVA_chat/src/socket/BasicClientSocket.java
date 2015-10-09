package socket;

import java.io.*;
import java.net.Socket;

public class BasicClientSocket {
    public static void main(String[] args) {
        try {
            //���� �ּҿ� ��Ʈ��ȣ�� �����Ͽ� ������ ����
            Socket mySocket = new Socket("127.0.0.1", 7070);
            System.out.println(">> ���� ���ӿ� �����߽��ϴ�.");

            //���� ���Ͽ� ��Ʈ���� ����
            BufferedReader in =
                    new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
            PrintWriter out =
                    new PrintWriter(new OutputStreamWriter(mySocket.getOutputStream()));

            //���� ���Ͽ� �޽��� ����
            String msg = "�ȳ��ϼ���? Ŭ���̾�Ʈ�Դϴ�.";
            out.println(msg);
            out.flush();
            System.out.println("[Ŭ���̾�Ʈ] " + msg);

            //���� �������κ��� ���� �޽����� ȭ�鿡 ���
            System.out.println("[����] " + in.readLine());

            //���� ���� ����
            mySocket.close();
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
}