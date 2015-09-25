import javax.crypto.Cipher;

/**
 * Created by º¸¿î on 2015-09-25.
 */
public class Decrypt {
    private Cipher aesCipher;
    private byte[] decryptText;
    private String decrypt;
    private CreateKey key;

    public Decrypt() {
        key = CreateKey.createKey();
        aesCipher = key.ModeSelect(1);
    }

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