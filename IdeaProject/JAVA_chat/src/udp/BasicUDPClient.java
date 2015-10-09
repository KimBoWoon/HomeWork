package udp;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class BasicUDPClient {
    DatagramSocket dsock;
    DatagramPacket sPack, rPack;
    InetAddress server;
    int port = 8888;

    public BasicUDPClient(String ip, int port) {
        try {
            // DatagramPacket�� �� ip �ּҰ� InetAddress ���¿��� ��
            server = InetAddress.getByName(ip);
            this.port = port;
            this.dsock = new DatagramSocket();
            System.out.println(">> ������ �����մϴ�.");
            System.out.println(">> ������ ������ �޽����� ���� Enter�� ��������.");
            System.out.println(">> �����Ϸ��� quit�� ���� Enter�� ��������." + "\n");
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        BasicUDPClient client = new BasicUDPClient("127.0.0.1", 7777);
        client.communicate();
    }

    public void communicate() {
        try {
            // Ű����κ��� �������� ������ ���ڿ��� �Է¹ޱ� ���� System.in�� BufferedReader ���·� ��ȯ
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String strOut = null;
            while ((strOut = br.readLine()) != null) {
                //DatagramPacket�� �Է� ���� �����ϰ� ������ ����
                sPack = new DatagramPacket(strOut.getBytes(), strOut.getBytes().length, server, port);
                dsock.send(sPack);
                //������ quit�� �����ϸ� ����
                if (strOut.equals("quit")) break;

                //�����κ��� ���ŵǴ� DatagramPacket�� �޾� ǥ�����
                byte[] buffer = new byte[1024];
                rPack = new DatagramPacket(buffer, buffer.length);
                dsock.receive(rPack);
                String strIn = new String(rPack.getData(), 0, rPack.getData().length);
                System.out.println("[����" + server + ": " + port + "]" + strIn);
            }
            System.out.println("UDP Ŭ���̾�Ʈ�� �����մϴ�.");
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}