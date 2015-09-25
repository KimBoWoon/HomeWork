import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

/**
 * Created by º¸¿î on 2015-09-25.
 */
public class CreateKey {
    private KeyGenerator keyGen;
    private SecretKey aesKey;
    private Cipher aesCipher;
    private static CreateKey key = new CreateKey();

    public CreateKey() {
        try {
            keyGen = KeyGenerator.getInstance("AES");
            aesKey = keyGen.generateKey();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("CreateKey Exception");
        }
    }

    public static CreateKey createKey() {
        return key;
    }

    public Cipher ModeSelect(int mode) {
        try {
            aesCipher = Cipher.getInstance("AES/ECB/PKCS5Padding");

            if (mode == 0)
                aesCipher.init(Cipher.ENCRYPT_MODE, aesKey);
            else if (mode == 1)
                aesCipher.init(Cipher.DECRYPT_MODE, aesKey);
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