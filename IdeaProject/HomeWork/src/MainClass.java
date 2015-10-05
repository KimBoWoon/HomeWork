import java.util.Scanner;

/**
 * Created by 보운 on 2015-09-25.
 */

// 메인 클래스
public class MainClass {
    public static void main(String[] args) {
        try {
            // 입력 파일 이름을 입력받는다
            Scanner stdin = new Scanner(System.in);
            System.out.println("Input File Name");
            String fileName = stdin.nextLine();
            // 파일 읽음
            FileRead in = new FileRead(fileName);
            // 출력 파일 이름을 입력받는다
            System.out.println("Output File Name");
            fileName = stdin.nextLine();
            // 파일 기록
            FileWrite out = new FileWrite(fileName);
            // 암호화
            Encrypt encrypt = new Encrypt();
            // 복호화
            Decrypt decrypt = new Decrypt();
            // 암호화된 문자열을 byte 배열에 담는다
            byte[] encryptText;
            // 복호화된 문자열 저장
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