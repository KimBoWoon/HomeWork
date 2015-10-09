package socket;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class MyClientSocket {
    Socket socket;
    BufferedReader in;
    PrintWriter out;

    public MyClientSocket(String ip, int port) {
        try {
            socket = new Socket(ip, port);

            //���� ���Ͽ� ��Ʈ���� ����
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
            printInfo();
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public static void main(String[] args) {
        //���� �ּҿ� ��Ʈ��ȣ�� �����Ͽ� ������ ����
        MyClientSocket client = new MyClientSocket("127.0.0.1", 7070);

        System.out.print("�������� ���� �޽��� �Է� >> ");
        Scanner s = new Scanner(System.in);
        String msg = s.nextLine();
        client.send(msg);
        client.receive();
        client.close();
    }

    public void receive() {
        try {
            //���� �������κ��� ���� �޽����� ȭ�鿡 ���
            System.out.println("[����] " + in.readLine());
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public void send(String msg) {
        //���� ���Ͽ� �޽��� ����
        out.println(msg);
        out.flush();
        System.out.println("[Ŭ���̾�Ʈ] " + msg);
    }

    public void close() {
        try {
            // Ŭ���̾�Ʈ ���� ����
            socket.close();
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public void printInfo() {
        System.out.println(">> ���� ���ӿ� �����߽��ϴ�.");
        //���� ��Ʈ ��ȣ�� Ŭ���̾�Ʈ �ּҿ� ��Ʈ��ȣ ���
        System.out.println("     ���� �ּ�: " + socket.getInetAddress());
        System.out.println("     ���� ��Ʈ��ȣ: " + socket.getPort());
        System.out.println("     Ŭ������Ʈ ��Ʈ��ȣ: " + socket.getLocalPort() + '\n');
    }
}