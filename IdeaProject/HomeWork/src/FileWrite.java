import java.io.*;

/**
 * Created by 보운 on 2015-09-25.
 */

// 암호화된 문장을 파일에 저장하는 클래스
public class FileWrite {
    private PrintWriter out;
    public FileWrite(String fileName) {
        try {
            out = new PrintWriter(new FileWriter(fileName));
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("File Write Exception");
        }
    }

    public void fileWrite(byte[] cipherText) {
        try {
            // byte[]타입의 저장 메서드가 존재하지 않아
            // PrintWriter Class를 사용해 파일에 저장
            out.print(cipherText);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("File Write Exception");
        }
    }
}