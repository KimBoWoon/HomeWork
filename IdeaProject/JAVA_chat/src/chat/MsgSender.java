package chat;

//import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class MsgSender extends Thread {
    String nickname;
	Socket socket;
	PrintWriter out;
	//DataOutputStream dos;
	
	public MsgSender(String nickname, Socket socket) {
		this.nickname = "[" + nickname + "] ";
		this.socket = socket;
		try {
			//���Ͽ� ��� ��Ʈ���� ����
			out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
			//dos = new DataOutputStream(socket.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();			
			System.out.println(e.toString());			
		}
	}
	
	public void run() {
		Scanner s = new Scanner(System.in);
		while (out != null) {
		//while (dos != null) {
			String msg = s.nextLine();
			//������ ����� ������� �տ� �ٿ� ����
			out.println(nickname + msg);
			out.flush();
			/*
			try {
				//dos.writeUTF(msg);
			} catch (IOException e) {
				e.printStackTrace();			
				System.out.println(e.toString());			
			}
			*/
		}
		try {
			// Ŭ���̾�Ʈ ���� ����
			socket.close();		
		} catch(IOException e) {
			e.printStackTrace();			
		}
	}	
}
