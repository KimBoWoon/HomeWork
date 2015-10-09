package basicio;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MyFileReaderWriter {
    public static void main(String[] args) {
        int data;
        //���� ���� �̸� ����
        String inFname = "src/basicio/MyFileReaderWriter.java";
        String outFname = "src/basicio/MyFileReaderWriter.back";
        try {
            //���� ���� �̸����� FileReader ����
            FileReader fr = new FileReader(inFname);
            //�ٽ� ����� ���� �̸����� FileWriter ����
            FileWriter fw = new FileWriter(outFname);

            //�� ���ھ� �о� �ְܼ� ���Ͽ� ���
            while ((data = fr.read()) != -1) {
                System.out.print((char) data);
                fw.write(data);
            }
            fr.close();
            fw.close();
            System.out.println();
            System.out.println("�� ������ �����Ǿ����ϴ�. : " + outFname);
        } catch (FileNotFoundException e) {
            System.err.println("���� ������ �����ϴ�. : " + inFname);
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}