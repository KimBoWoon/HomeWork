import java.net.ServerSocket;
import java.net.Socket;

public class message_flow_server_20113259_김보운 {
    public static void main(String[] args) {
        try {
            int port = 9190;

            ServerSocket server = new ServerSocket(port);
            Socket socket = server.accept();
            message_flow_receiver_20113259_김보운 receiver = new message_flow_receiver_20113259_김보운(socket);
            receiver.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}