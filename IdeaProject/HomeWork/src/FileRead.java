import java.io.BufferedReader;
import java.io.FileReader;

/**
 * Created by º¸¿î on 2015-09-25.
 */
public class FileRead {
    public String fileRead() {
        try {
            BufferedReader in = new BufferedReader(new FileReader("input.txt"));

            String str;
            str = in.readLine();
            in.close();

            return str;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("File Read Exception");
            return null;
        }
    }
}