import javax.crypto.Cipher;

/**
 * Created by º¸¿î on 2015-09-25.
 */
public class Encrypt {
    private Cipher aesCipher;
    private byte[] encryptText;
    private CreateKey key;

    public Encrypt() {
        key = CreateKey.createKey();
        aesCipher = key.ModeSelect(0);
    }

    public byte[] encrypt(String plaintext) {
        try {
            encryptText = aesCipher.doFinal(plaintext.getBytes());

            return encryptText;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Encrypt Exception");
            return null;
        }
    }
}