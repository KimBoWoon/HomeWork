import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class message_flow_sender_20113259_김보운 extends Thread {
    private Socket socket;
    private PrintWriter out;

    public message_flow_sender_20113259_김보운(Socket socket) {
        this.socket = socket;
        try {
            out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println(e.toString());
        }
    }

    public void run() {
        try {
            int n = 1;

            while (out != null) {
                out.println("sequence no = " + n++);
                out.flush();
                sleep(10);
            }
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
