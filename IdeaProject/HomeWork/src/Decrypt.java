import javax.crypto.Cipher;

/**
 * Created by 보운 on 2015-09-25.
 */

// 복호화 클래스
public class Decrypt {
    private Cipher aesCipher;
    private byte[] decryptText;
    private String decrypt;
    private CreateKey key;

    // 생성자에서 키값과 복호화모드로 설정한다
    public Decrypt() {
        key = CreateKey.createKey();
        aesCipher = key.ModeSelect(1);
    }

    // 복호화를 진행하고 String타입으로 변환해서 반환
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