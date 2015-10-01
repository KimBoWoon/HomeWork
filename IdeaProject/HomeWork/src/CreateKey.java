import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;

/**
 * Created by ���� on 2015-09-25.
 */

// Ű���� Ŭ����
public class CreateKey {
    private KeyGenerator keyGen;
    private SecretKey aesKey;
    private Cipher aesCipher;
    private SecretKeySpec keySpec;
    private String secretKey;
    private Scanner in = new Scanner(System.in);
    // ��ȣȭ�� ��ȣȭ�� �Ҷ� Ű���� �����ؾ� ���ϴ� ������ ���� �� �ִ�
    // Ű���� Ŭ������ ������ �� ���� ���ο� Ű���� �����ǹǷ�
    // ����ƽ �޼��带 �̿��� ��ü�� �ּҰ��� ��ȯ�Ѵ�
    private static CreateKey key;

    public CreateKey() {
        try {
            // ���Ű ���� �Է¹���
            System.out.print("input Secret Key : ");
            secretKey = in.nextLine();
            byte[] keyBytes = new byte[16];
            byte[] secretKeyBytes = secretKey.getBytes("UTF-8");
            // secretKeyBytes�� 16����Ʈ���� ũ�� keyBytes�� 16����Ʈ�� ����
            if(secretKeyBytes.length > keyBytes.length)
                System.arraycopy(secretKeyBytes, 0, keyBytes, 0, keyBytes.length);
            // ���Ű ����
            SecretKeySpec keySpec = new SecretKeySpec(keyBytes, "AES");

            this.keySpec = keySpec;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("CreateKey Exception");
        }
    }

    // ���� CreateKey�� �ν��Ͻ��� �����ϸ� �ּҰ��� ��ȯ
    // �׷��� ������ �ν��Ͻ��� ������ �ּҰ��� ��ȯ
    public static CreateKey createKey() {
        if (key == null) {
            key = new CreateKey();
            return key;
        }
        else
            return key;
    }

    // �Ű������� �̿��� ��ȣȭ�� ��ȣȭ�� �����ؼ� ����
    public Cipher ModeSelect(int mode) {
        try {
            aesCipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

            if (mode == 0)
                aesCipher.init(Cipher.ENCRYPT_MODE, keySpec, CreateIV.getIV());
            else if (mode == 1)
                aesCipher.init(Cipher.DECRYPT_MODE, keySpec, CreateIV.getIV());
            else
                return null;

            return aesCipher;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("ModeSelect Exception");
            return null;
        }
    }
}