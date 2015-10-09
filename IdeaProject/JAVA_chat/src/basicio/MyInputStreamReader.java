package basicio;

import java.io.*;

public class MyInputStreamReader {
    public static void main(String[] args) {
        String line;
        //���� ���� �̸� ����
        String fname = "src/basicio/MyInputStreamReader.java";
        try {
            //���� ���� �̸����� FileInputStream ����
            FileInputStream fis = new FileInputStream(fname);
            //���� �Է½�Ʈ���� �ٽ� InputStreamReader�� ����
            InputStreamReader isr = new InputStreamReader(fis);
            //InputStreamReader�� �ٽ� BufferedReader�� ����
            BufferedReader br = new BufferedReader(isr);
            //���� InputStreamReader�� ���ڵ� ��� ���
            System.out.println(isr.getEncoding());
            System.out.println();
            //�� �پ� �о� ���
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            br.close();
            isr.close();
            fis.close();
        } catch (FileNotFoundException e) {
            System.err.println("���� ������ �����ϴ�. : " + fname);
        } catch (IOException e) {
            System.err.println(e);
        }
        System.out.println();
    }
}
