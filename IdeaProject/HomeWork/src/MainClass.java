/**
 * Created by 보운 on 2015-09-25.
 */

// 메인 클래스
public class MainClass {
    public static void main(String[] args) {
        try {
            String fileName = "input.txt";
            FileRead in = new FileRead(fileName);
            FileWrite out = new FileWrite();
            Encrypt encrypt = new Encrypt();
            Decrypt decrypt = new Decrypt();
            byte[] encryptText;
            String decryptText;

            String plainText = in.fileRead();
            System.out.println("Plain Text : " + plainText);

            // 암호화
            encryptText = encrypt.encrypt(plainText);
            System.out.println("Encrypt Text : " + encryptText);

            out.fileWrite(encryptText);

            // 복호화
            decryptText = decrypt.decrypt(encryptText);
            System.out.println("Decrypt Text : " + decryptText);
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Main Exception");
        }
    }
}