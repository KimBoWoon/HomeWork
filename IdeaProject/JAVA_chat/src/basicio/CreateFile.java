package basicio;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class CreateFile {
    public static void main(String args[]) {
        //���� ���� �̸� ����
        String fname = "src/basicio/newfile.txt";
        //File ��ü ����
        File f = new File(fname);

        //���� ���� ���� ���� Ȯ��
        if (!f.exists()) {
            //ó�� �����ϸ� ������ �����Ƿ� �����
            System.out.println("���� ������ ã�� �� �����ϴ�. : " + fname);
        }
        //������ ������ ����� ���ڿ��� ����
        try {
            f.createNewFile();
            if (f.exists()) {
                System.out.println("���� ������ �ֽ��ϴ�. : " + fname);
            }

            FileWriter fr = new FileWriter(f);
            fr.write("���� ������ ���ϴ�.");
            fr.close();

        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
