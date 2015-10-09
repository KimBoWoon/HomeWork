package socket;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class MyServerSocket {
    int port = 7070;
    ServerSocket server;
    Socket socket;
    BufferedReader in;
    PrintWriter out;

    public MyServerSocket(int port) {
        this.port = port;
        System.out.println(">> ������ �����մϴ�.");
        try {
            server = new ServerSocket(7070);
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public static void main(String[] args) {
        int port = 7070;
        MyServerSocket myServer = new MyServerSocket(port);
        myServer.waitForClient();
        myServer.receive();
        myServer.send("������ �����Ͻ� ���� ȯ���մϴ�!");
        myServer.close();
    }

    public void waitForClient() {
        System.out.println(">> Ŭ���̾�Ʈ�� �����ϱ� ��ٸ��� �ֽ��ϴ�.");
        try {
            // Ŭ���̾�Ʈ ���Ӷ����� ���
            socket = server.accept();
            printInfo();
            //Ŭ���̾�Ʈ ���Ͽ� ��Ʈ���� ����
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public void receive() {
        try {
            //Ŭ���̾�Ʈ �������κ��� ���� �޽����� ȭ�鿡 ���
            System.out.println("[Ŭ���̾�Ʈ] " + in.readLine());
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public void send(String msg) {
        // Ŭ���̾�Ʈ ���Ͽ� �޽��� ����
        out.println(msg);
        out.flush();
        System.out.println("[����] " + msg);
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
        System.out.println(">> Ŭ���̾�Ʈ�� ���ӿ� �����߽��ϴ�.");
        //���� ��Ʈ ��ȣ�� Ŭ���̾�Ʈ �ּҿ� ��Ʈ��ȣ ���
        System.out.println("     ���� ��Ʈ��ȣ: " + socket.getLocalPort());
        System.out.println("     Ŭ���̾�Ʈ �ּ�: " + socket.getInetAddress());
        System.out.println("     Ŭ���̾�Ʈ ��Ʈ��ȣ: " + socket.getPort() + '\n');
    }
}