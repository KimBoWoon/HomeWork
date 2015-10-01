import javax.crypto.Cipher;

/**
 * Created by 보운 on 2015-09-25.
 */

// 암호화 클래스
public class Encrypt {
    private Cipher aesCipher;
    private byte[] encryptText;
    private CreateKey key;

    // 생성자에서 키값과 암호화모드로 설정
    public Encrypt() {
        key = CreateKey.createKey();
        aesCipher = key.ModeSelect(0);
    }

    // 전달받은 String을 암호화해서 암호화된 문자열을 반환
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