package Server;

import Client.ClientVector;

/**
 * Created by 보운 on 2015-10-06.
 */
public class ChatServerMain {
    public static void main(String[] args) {
        ClientVector cv = new ClientVector();
        ChatServer server = new ChatServer(cv);
    }
}
