package Server;

import Client.ClientInfo;

import java.util.Vector;

public class ChatServerMain {
    public static Vector<ClientInfo> clientInfos = new Vector<ClientInfo>();

    public static void main(String[] args) {
        ChatServer server = new ChatServer();
    }
}
