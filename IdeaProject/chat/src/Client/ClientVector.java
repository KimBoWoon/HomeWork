package Client;

import java.util.Vector;

/**
 * Created by 보운 on 2015-10-11.
 */
public class ClientVector {
    private static Vector<ClientInfo> clientInfos;

    public ClientVector() {
        clientInfos = new Vector<ClientInfo>();
    }

    public int vectorSize() {
        return clientInfos.size();
    }

    public static Vector<ClientInfo> getClientVector() {
        if (clientInfos == null) {
            clientInfos = new Vector<ClientInfo>();
            return clientInfos;
        }
        return clientInfos;
    }

    public Vector<ClientInfo> getClientInfos() {
        return clientInfos;
    }
}
