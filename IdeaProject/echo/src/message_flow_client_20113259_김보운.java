import java.net.Socket;

public class message_flow_client_20113259_김보운 {
    public static void main(String[] args) {
        try {
            int port = 9190;
            String ip = "127.0.0.1";

            Socket socket = new Socket(ip, port);
            message_flow_sender_20113259_김보운 sender = new message_flow_sender_20113259_김보운(socket);

            sender.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}