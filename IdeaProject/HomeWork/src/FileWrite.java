import java.io.FileWriter;
import java.io.PrintWriter;

/**
 * Created by ���� on 2015-09-25.
 */

// ��ȣȭ�� ������ ���Ͽ� �����ϴ� Ŭ����
public class FileWrite {
    public void fileWrite(byte[] cipherText) {
        try {
            // byte[]Ÿ���� ���� �޼��尡 �������� �ʾ�
            // PrintWriter Class�� ����� ���Ͽ� ����
            PrintWriter out = new PrintWriter(new FileWriter("output.txt"));

            out.print(cipherText);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("File Write Exception");
        }
    }
}