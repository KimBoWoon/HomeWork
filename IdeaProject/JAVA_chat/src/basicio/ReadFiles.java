package basicio;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class ReadFiles {
    public static void main(String[] args) {
        int data;
        //���� ���� �̸� ����
        String fname = "src/basicio/ReadFiles.java";

        try {
            //���� ���� �̸����� FileInputStream ����
            FileInputStream fis = new FileInputStream(fname);
            //�� ����Ʈ�� �о� ���ڷ� ��ȯ�Ͽ� ���
            while ((data = fis.read()) != -1) {
                char c = (char) data;
                System.out.print(c);
            }
        } catch (FileNotFoundException e) {
            System.err.println("���� ������ �����ϴ�. : " + fname);
        } catch (IOException e) {
            System.err.println(e);
        }
        System.out.println();
    }
}

//public FileInputStream(String filename) throws FileNotFoundException
//public FileInputStream(File file) throws FileNotFoundException
//public FileInputStream(FileDescriptor fd)

