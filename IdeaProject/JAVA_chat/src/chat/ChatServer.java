package chat;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ChatServer {
    int port = 7070;
    ServerSocket server;
    Socket socket;

    public ChatServer(int port) {
        this.port = port;
        System.out.println(">> 서버를 시작합니다.");
        try {
            server = new ServerSocket(port);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        int port = 7070;
        ChatServer myServer = new ChatServer(port);
        myServer.communicate();
    }

    public void communicate() {
        System.out.println(">> 클라이언트가 접속하길 기다리고 있습니다.");
        try {
            // 클라이언트 접속때까지 대기
            socket = server.accept();
            printInfo();
            //서버 소켓에 입력과 출력을 위한 sender와 receiver를 연결
            MsgSender sender = new MsgSender("서버", socket);
            MsgReceiver receiver = new MsgReceiver("서버", socket);
            //sender와 receiver의 스레드를 실행
            receiver.start();
            sender.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void close() {
        try {
            // 클라이언트 소켓 종료
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void printInfo() {
        System.out.println(">> 클라이언트가 접속에 성공했습니다.");
        //서비스 포트 번호와 클라이언트 주소와 포트번호 출력
        System.out.println("     서버 포트번호: " + socket.getLocalPort());
        System.out.println("     클라이언트 주소: " + socket.getInetAddress());
        System.out.println("     클라이언트 포트번호: " + socket.getPort() + '\n');
        System.out.println(">> 클라이언트에 전달할 메시지를 쓰고 Enter를 누르세요." + '\n');
    }
}