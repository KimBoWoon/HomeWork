/**
 * Created by 보운 on 2015-05-31.
 */

public class HomeWork {
    public static void main(String[] args) {
        try {
            FileRead in = new FileRead();
            FileWrite out = new FileWrite();
            Encrypt encrypt = new Encrypt();
            Decrypt decrypt = new Decrypt();
            byte[] encryptText;
            String decryptText;

            String plaintext = in.fileRead();
            System.out.println("Plain Text : " + plaintext);

            encryptText = encrypt.encrypt(plaintext);
            System.out.println("Encrypt Text : " + encryptText);

            out.fileWrite(encryptText);

            decryptText = decrypt.decrypt(encryptText);
            System.out.println("Decrypt Text : " + decryptText);
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Main Exception");
        }
    }
}