import javax.crypto.Cipher;

/**
 * Created by ���� on 2015-09-25.
 */

// ��ȣȭ Ŭ����
public class Decrypt {
    private Cipher aesCipher;
    private byte[] decryptText;
    private String decrypt;
    private CreateKey key;

    // �����ڿ��� Ű���� ��ȣȭ���� �����Ѵ�
    public Decrypt() {
        key = CreateKey.createKey();
        aesCipher = key.ModeSelect(1);
    }

    // ��ȣȭ�� �����ϰ� StringŸ������ ��ȯ�ؼ� ��ȯ
    public String decrypt(byte[] cipherText) {
        try {
            decryptText = aesCipher.doFinal(cipherText);
            decrypt = new String(decryptText);

            return decrypt;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Decrypt Exception");
            return null;
        }
    }
}