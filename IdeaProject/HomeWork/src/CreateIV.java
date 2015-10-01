import javax.crypto.spec.IvParameterSpec;
import java.security.SecureRandom;

/**
 * Created by ���� on 2015-09-30.
 */
public class CreateIV {
    private static IvParameterSpec iv;

    public static IvParameterSpec getIV() {
        if (iv == null) {
            byte[] ivByteArray = new byte[16];
            // ������ ����Ʈ�� �迭�� ä��
            new SecureRandom().nextBytes(ivByteArray);
            iv = new IvParameterSpec(ivByteArray);
        }
        return iv;
    }
}
