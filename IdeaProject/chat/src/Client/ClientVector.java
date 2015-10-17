package Client;

import java.util.Vector;

/**
 * Created by 보운 on 2015-10-11.
 */
public class ClientVector {
    private Vector<ClientInfo> clientInfos;

    public ClientVector() {
        clientInfos = new Vector<ClientInfo>();
    }

    public int vectorSize() {
        return clientInfos.size();
    }

    public Vector<ClientInfo> getClientInfos() {
        return clientInfos;
    }
}
