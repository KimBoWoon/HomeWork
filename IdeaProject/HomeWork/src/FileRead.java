import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Created by 보운 on 2015-09-25.
 */

// 파일에서 암호화할 문장을 읽어오는 클래스
public class FileRead {
    private BufferedReader in;
    private String str;

    public FileRead(String fileName) {
        try {
            in = new BufferedReader(new FileReader(fileName));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.out.println("File Read Exception");
        }
    }

    public String fileRead() {
        try {
            str = in.readLine();
            in.close();

            return str;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}