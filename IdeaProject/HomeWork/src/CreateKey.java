import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;

/**
 * Created by 보운 on 2015-09-25.
 */

// 키생성 클래스
public class CreateKey {
    private KeyGenerator keyGen;
    private SecretKey aesKey;
    private Cipher aesCipher;
    private SecretKeySpec keySpec;
    private String secretKey;
    private Scanner in = new Scanner(System.in);
    // 암호화나 복호화를 할때 키값이 동일해야 원하는 문장을 얻을 수 있다
    // 키생성 클래스를 생성할 때 마다 새로운 키값이 생성되므로
    // 스태틱 메서드를 이용해 객체의 주소값을 반환한다
    private static CreateKey key;

    public CreateKey() {
        try {
            // 비밀키 값을 입력받음
            System.out.print("input Secret Key : ");
            secretKey = in.nextLine();
            byte[] keyBytes = new byte[16];
            byte[] secretKeyBytes = secretKey.getBytes("UTF-8");
            // secretKeyBytes가 16바이트보다 크면 keyBytes에 16바이트만 복사
            if(secretKeyBytes.length > keyBytes.length)
                System.arraycopy(secretKeyBytes, 0, keyBytes, 0, keyBytes.length);
            // 비밀키 생성
            SecretKeySpec keySpec = new SecretKeySpec(keyBytes, "AES");

            this.keySpec = keySpec;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("CreateKey Exception");
        }
    }

    // 만약 CreateKey의 인스턴스가 존재하면 주소값을 반환
    // 그렇지 않으면 인스턴스를 생성해 주소값을 반환
    public static CreateKey createKey() {
        if (key == null) {
            key = new CreateKey();
            return key;
        }
        else
            return key;
    }

    // 매개변수를 이용해 암호화나 복호화를 선택해서 진행
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