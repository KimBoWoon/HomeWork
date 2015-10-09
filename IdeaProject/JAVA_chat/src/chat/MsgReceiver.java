
package chat;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

//import java.io.DataInputStream;

public class MsgReceiver extends Thread {
    String nickname;
	Socket socket;
	BufferedReader in;
	//DataInputStream dis;
	
	public MsgReceiver(String nickname, Socket socket) {
		this.nickname = "[" + nickname + "] ";
		this.socket = socket;
		try {
			//���Ͽ� �Է� ��Ʈ���� ����
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			//dis = new DataInputStream(socket.getInputStream());
		} catch (IOException e) {
			System.out.println(e.toString());			
		}
	}
	
	public void run() {
		while (in != null) {
		//while (dis != null) {
			try {
				//�������κ��� ���� �޽����� ȭ�鿡 ���
				System.out.println(in.readLine());		
				//System.out.println(nickname + dis.readUTF());		
			} catch (IOException e) {
				System.out.println(e.toString());			
			}
		}
		try {
			// Ŭ���̾�Ʈ ���� ����
			socket.close();		
		} catch(IOException e) {
			e.printStackTrace();			
		}
	}
}
