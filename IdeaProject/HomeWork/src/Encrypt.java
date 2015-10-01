import javax.crypto.Cipher;

/**
 * Created by ���� on 2015-09-25.
 */

// ��ȣȭ Ŭ����
public class Encrypt {
    private Cipher aesCipher;
    private byte[] encryptText;
    private CreateKey key;

    // �����ڿ��� Ű���� ��ȣȭ���� ����
    public Encrypt() {
        key = CreateKey.createKey();
        aesCipher = key.ModeSelect(0);
    }

    // ���޹��� String�� ��ȣȭ�ؼ� ��ȣȭ�� ���ڿ��� ��ȯ
    public byte[] encrypt(String plainText) {
        try {
            encryptText = aesCipher.doFinal(plainText.getBytes());

            return encryptText;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Encrypt Exception");
            return null;
        }
    }
}