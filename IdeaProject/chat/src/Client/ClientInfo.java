package Client;

/**
 * Created by 보운 on 2015-10-06.
 */
public class ClientInfo {
    private String name;
    private String ip;
    private int port;
    private String udpPort;
    private static int cnt;

    public ClientInfo(String name, String ip, int port) {
        this.name = name;
        this.ip = ip;
        this.port = port;
        cnt++;
    }
    public ClientInfo(String ip, int port, String udpPort) {
        this.ip = ip;
        this.port = port;
        this.udpPort = udpPort;
        cnt++;
    }
    public ClientInfo(String name, String ip, int port, String udpPort) {
        this.name = name;
        this.ip = ip;
        this.port = port;
        this.udpPort = udpPort;
        cnt++;
    }

    public static int getCnt() {
        return cnt;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
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

    public String getUdpPort() {
        return udpPort;
    }

    public void setUdpPort(String udpPort) {
        this.udpPort = udpPort;
    }
}
