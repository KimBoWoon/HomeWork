package basicio;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class WriteFiles {
    public static void main(String[] args) {
        int data;
        FileInputStream fis;
        FileOutputStream fos;
        String inFname = "src/basicio/WriteFiles.java";
        String outFname = "src/basicio/WriteFiles.back";

        try {
            //���� ���� �̸����� FileInputStream ����
            fis = new FileInputStream(inFname);
            //���� ���� ���� �̸����� FileOutputStream ����
            fos = new FileOutputStream(outFname);
            //�� ����Ʈ�� �о� FileOutputStream���� ���
            while ((data = fis.read()) != -1) {
                fos.write(data);
            }
            System.out.println(outFname + " : ������ �����Ǿ����ϴ�.");
        } catch (IOException e) {
            System.err.println(e);
        }
    } // end main
}