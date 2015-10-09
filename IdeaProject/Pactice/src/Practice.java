
import java.util.Arrays;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class Practice {
    private static byte[] aesEncryptEcb(String sKey, String sText) {
        byte[] key = null;
        byte[] text = null;
        byte[] encrypted = null;
        final int AES_KEY_SIZE_128 = 128;

        try {
            // UTF-8
            key = sKey.getBytes("UTF-8");

            // Key size 맞춤 (128bit, 16byte)
            key = Arrays.copyOf(key, AES_KEY_SIZE_128 / 8);

            // UTF-8
            text = sText.getBytes("UTF-8");

            // AES/EBC/PKCS5Padding
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
            cipher.init(Cipher.ENCRYPT_MODE, new SecretKeySpec(key, "AES"));
            encrypted = cipher.doFinal(text);
        } catch (Exception e) {
            encrypted = null;
            e.printStackTrace();
        }

        return encrypted;
    }

    private static byte[] aesDecryptEcb(String sKey, byte[] encrypted) {
        byte[] key = null;
        byte[] decrypted = null;
        final int AES_KEY_SIZE_128 = 128;

        try {
            // UTF-8
            key = sKey.getBytes("UTF-8");

            // Key size 맞춤 (128bit, 16byte)
            key = Arrays.copyOf(key, AES_KEY_SIZE_128 / 8);

            // AES/EBC/PKCS5Padding
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
            cipher.init(Cipher.DECRYPT_MODE, new SecretKeySpec(key, "AES"));
            decrypted = cipher.doFinal(encrypted);
        } catch (Exception e) {
            decrypted = null;
            e.printStackTrace();
        }

        return decrypted;
    }

    private static byte[] aesEncryptCbc(String sKey, String sText) {
        return aesEncryptCbc(sKey, sText, "");
    }

    private static byte[] aesDecryptCbc(String sKey, byte[] encrypted) {
        return aesDecryptCbc(sKey, encrypted, "");
    }

    private static byte[] aesEncryptCbc(String sKey, String sText, String sInitVector) {
        byte[] key = null;
        byte[] text = null;
        byte[] iv = null;
        byte[] encrypted = null;
        final int AES_KEY_SIZE_128 = 128;

        try {
            // UTF-8
            key = sKey.getBytes("UTF-8");

            // Key size 맞춤 (128bit, 16byte)
            key = Arrays.copyOf(key, AES_KEY_SIZE_128 / 8);

            // UTF-8
            text = sText.getBytes("UTF-8");

            if (sInitVector != null) {
                // UTF-8
                iv = sInitVector.getBytes("UTF-8");

                // Key size 맞춤 (128bit, 16byte)
                iv = Arrays.copyOf(iv, AES_KEY_SIZE_128 / 8);

                // AES/EBC/PKCS5Padding
                Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                IvParameterSpec ips = new IvParameterSpec(iv);
                cipher.init(Cipher.ENCRYPT_MODE, new SecretKeySpec(key, "AES"), ips);
                encrypted = cipher.doFinal(text);
            } else {
                // AES/EBC/PKCS5Padding
                Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                cipher.init(Cipher.ENCRYPT_MODE, new SecretKeySpec(key, "AES"));
                encrypted = cipher.doFinal(text);
            }
        } catch (Exception e) {
            encrypted = null;
            e.printStackTrace();
        }

        return encrypted;
    }

    private static byte[] aesDecryptCbc(String sKey, byte[] encrypted, String sInitVector) {
        byte[] key = null;
        byte[] iv = null;
        byte[] decrypted = null;
        final int AES_KEY_SIZE_128 = 128;

        try {
            // UTF-8
            key = sKey.getBytes("UTF-8");

            // Key size 맞춤 (128bit, 16byte)
            key = Arrays.copyOf(key, AES_KEY_SIZE_128 / 8);

            if (sInitVector != null) {
                // UTF-8
                iv = sInitVector.getBytes("UTF-8");

                // Key size 맞춤 (128bit, 16byte)
                iv = Arrays.copyOf(iv, AES_KEY_SIZE_128 / 8);

                // AES/EBC/PKCS5Padding
                Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                IvParameterSpec ips = new IvParameterSpec(iv);
                cipher.init(Cipher.DECRYPT_MODE, new SecretKeySpec(key, "AES"), ips);
                decrypted = cipher.doFinal(encrypted);
            } else {
                // AES/EBC/PKCS5Padding
                Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                cipher.init(Cipher.DECRYPT_MODE, new SecretKeySpec(key, "AES"));
                decrypted = cipher.doFinal(encrypted);
            }
        } catch (Exception e) {
            decrypted = null;
            e.printStackTrace();
        }

        return decrypted;
    }

    private static String toHexString(byte[] b) {
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < b.length; i++) {
            sb.append(String.format("%02X", b[i]));
            if ((i + 1) % 16 == 0 && ((i + 1) != b.length)) {
                sb.append(" ");
            }
        }

        return sb.toString();
    }

    public static void main(String[] args){
        String sKey = "ABC";
        String sText = "1234123412341234가나다";
        String sInitVector = "123가나다";
        byte[] encrypted = null;
        byte[] decrypted = null;

        try {
            System.out.println("* AES/ECB");
            System.out.println("    - KEY : " + sKey);
            System.out.println("    - TEXT : " + sText);

            // AES/ECB 암호화
            encrypted = aesEncryptEcb(sKey, sText);

            // AES/ECB 복호화
            decrypted = aesDecryptEcb(sKey, encrypted);

            if (encrypted == null) {
                System.out.println("    - Encrypted : ERROR!!!");
            } else {
                System.out.println("    - Encrypted : " + toHexString(encrypted));
            }

            if (decrypted == null) {
                System.out.println("    - Decrypted : ERROR!!!");
            } else {
                System.out.println("    - Decrypted : " + new String(decrypted, "UTF-8"));
            }

            System.out.println("* AES/CBC");
            System.out.println("    - KEY : " + sKey);
            System.out.println("    - TEXT : " + sText);
            System.out.println("    - IV : (Empty)");

            // AES/CBC 암호화
            encrypted = aesEncryptCbc(sKey, sText);

            // AES/CBC 복호화
            decrypted = aesDecryptCbc(sKey, encrypted);

            if (encrypted == null) {
                System.out.println("    - Encrypted : ERROR!!!");
            } else {
                System.out.println("    - Encrypted : " + toHexString(encrypted));
            }

            if (decrypted == null) {
                System.out.println("    - Decrypted : ERROR!!!");
            } else {
                System.out.println("    - Decrypted : " + new String(decrypted, "UTF-8"));
            }

            System.out.println("* AES/CBC/IV");
            System.out.println("    - KEY : " + sKey);
            System.out.println("    - TEXT : " + sText);
            System.out.println("    - IV : " + sInitVector);

            // AES/CBC/IV 암호화
            encrypted = aesEncryptCbc(sKey, sText, sInitVector);

            // AES/CBC/IV 복호화
            encrypted = aesEncryptCbc(sKey, sText, sInitVector);

            if (encrypted == null) {
                System.out.println("    - Encrypted : ERROR!!!");
            } else {
                System.out.println("    - Encrypted : " + toHexString(encrypted));
            }

            if (decrypted == null) {
                System.out.println("    - Decrypted : ERROR!!!");
            } else {
                System.out.println("    - Decrypted : " + new String(decrypted, "UTF-8"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}