import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class MyDataStream {
    public static void main(String[] args) throws IOException {
        FileOutputStream fos;
        DataOutputStream dos;
        String fname = "src/data.txt";

        fos = new FileOutputStream(fname);
        dos = new DataOutputStream(fos);
        dos.writeChars("�����Ͱ� �� ������?\n");
        dos.writeInt(2385);
        dos.writeDouble(34.567);

        dos.close();
        fos.close();
    }
}
