package basicio;

import java.io.*;
import java.util.Arrays;

public class BufferedStream {
    public static void main(String[] args) {
        FileOutputStream fos;
        BufferedInputStream bis;
        BufferedOutputStream bos;
        String fname = "src/basicio/test.buff";

        try {
            //���� ���� ���� �̸����� FileOutputStream ����
            //fos = new FileOutputStream(fname);
            fos = new FileOutputStream("src/basicio/test.buff");
            bos = new BufferedOutputStream(fos);
            byte data[] = {'A', 'B', 'C', 'D', 'E'};
            //�� ����Ʈ�� �о� FileOutputStream���� ���
            bos.write(data, 0, 5);
            bos.close();
            fos.close();
            System.out.println(fname + " : ������ �����Ǿ����ϴ�.");

            //���� ���� �̸����� FileInputStream ����
            bis = new BufferedInputStream(new FileInputStream(fname));
            data = new byte[10];
            bis.read(data, 0, 10);
            bis.close();
            System.out.println(Arrays.toString(data));
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}
