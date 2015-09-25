import java.io.FileWriter;
import java.io.PrintWriter;

/**
 * Created by º¸¿î on 2015-09-25.
 */
public class FileWrite {
    public void fileWrite(byte[] ciphertext) {
        try {
            PrintWriter out = new PrintWriter(new FileWriter("output.txt"));

            out.print(ciphertext);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("File Write Exception");
        }
    }
}