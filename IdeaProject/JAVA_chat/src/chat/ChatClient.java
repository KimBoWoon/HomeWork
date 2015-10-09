package chat;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;

public class ChatClient {
    Socket socket;
    BufferedReader in;
    PrintWriter out;

    public ChatClient(String ip, int port) {
        try {
            socket = new Socket(ip, port);
            printInfo();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        //서버 주소와 포트번호를 지정하여 서버에 접속
        ChatClient client = new ChatClient("127.0.0.1", 7070);
        //서버와 통신
        client.communicate();
    }

    public void communicate() {
        //클라이언트 소켓에 입력과 출력을 위한 sender와 receiver를 연결
        MsgSender sender = new MsgSender("클라이언트", socket);
        MsgReceiver receiver = new MsgReceiver("클라이언트", socket);
        //sender와 receiver의 스레드를 실행
        sender.start();
        receiver.start();
    }

    public void close() {
        try {
            // 클라이언트 소켓 종료
            socket.close();
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public void printInfo() {
        System.out.println(">> 서버 접속에 성공했습니다.");
        //서비스 포트 번호와 클라이언트 주소와 포트번호 출력
        System.out.println("     클라이언트 포트번호: " + socket.getLocalPort());
        System.out.println("     서버 주소: " + socket.getInetAddress());
        System.out.println("     서버 포트번호: " + socket.getPort() + '\n');
        System.out.println(">> 서버에 전달할 메시지를 쓰고 Enter를 누르세요." + '\n');
    }
}