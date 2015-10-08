package Client;

import java.util.Vector;

/**
 * Created by º¸¿î on 2015-10-06.
 */
public class ClientInfo {
    private String ip;
    private int port;
    private int udpPort;

    public ClientInfo(String ip, int port, int udpPort) {
        this.ip = ip;
        this.port = port;
        this.udpPort = udpPort;
    }

    public String getIp() {
        return ip;
    }

    public void setIp(String ip) {
        this.ip = ip;
    }

    public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }

    public int getUdpPort() {
        return udpPort;
    }

    public void setUdpPort(int udpPort) {
        this.udpPort = udpPort;
    }
}
