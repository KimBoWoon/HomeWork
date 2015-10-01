import javax.crypto.spec.IvParameterSpec;
import java.security.SecureRandom;

/**
 * Created by 보운 on 2015-09-30.
 */
public class CreateIV {
    private static IvParameterSpec iv;

    public static IvParameterSpec getIV() {
        if (iv == null) {
            byte[] ivByteArray = new byte[16];
            // 임의의 바이트로 배열을 채움
            new SecureRandom().nextBytes(ivByteArray);
            iv = new IvParameterSpec(ivByteArray);
        }
        return iv;
    }
}
