import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class message_flow_receiver_20113259_김보운 extends Thread {
    private Socket socket;
    private BufferedReader in;

    public message_flow_receiver_20113259_김보운(Socket socket) {
        this.socket = socket;
        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public void run() {
        try {
            while (in != null) {
                try {
                    System.out.println(in.readLine());
                } catch (IOException e) {
                    System.out.println(e.toString());
                }
            }
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
