package basicio;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Arrays;

public class ByteArrayIO {
    public static void main(String args[]) throws IOException {
        int c;
        byte b[] = {'a', 'b', 'c', 'd'};

        //�迭 b�� �д� ByteArrayInputStream ��ü�� ����
        ByteArrayInputStream bInput = new ByteArrayInputStream(b);
        //�迭 b�� �ҹ��ڸ� �빮�ڷ� ����ϴ� ByteArrayOutputStream ��ü�� ����
        ByteArrayOutputStream bOutput = new ByteArrayOutputStream();

        System.out.println("���ڸ� �о� �빮�ڷ� ���");
        while ((c = bInput.read()) != -1) {
            System.out.print((char) c);
            //��ü ByteArrayOutputStream�� �빮�ڸ� ���
            bOutput.write(Character.toUpperCase((char) c));
        }
        System.out.println();
        //��ü ByteArrayOutputStream�� ����ϸ� ��µ� �ڷᰡ �״�� ���
        System.out.println(bOutput);

        //�迭 Arrays �޼ҵ� toString() ����Ͽ� ���� �Է� ���� ��� ���� ���
        System.out.println(Arrays.toString(b));
        System.out.println(Arrays.toString(bOutput.toByteArray()));
    }
}
