import java.io.*;

/**
 * Created by ���� on 2015-09-25.
 */

// ��ȣȭ�� ������ ���Ͽ� �����ϴ� Ŭ����
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
            // byte[]Ÿ���� ���� �޼��尡 �������� �ʾ�
            // PrintWriter Class�� ����� ���Ͽ� ����
            out.print(cipherText);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("File Write Exception");
        }
    }
}