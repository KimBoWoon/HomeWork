import java.util.Scanner;

class ControlClass
{
	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args)
	{
		Score s = new Score();

		while(true)
		{
			System.out.printf("점수를 입력하세요 : ");
			int score = in.nextInt();
			String str = new String("");
			str = in.nextLine();

			if (str.compareTo("quit") == 0)
				break;

			s.asdf();
		}
	}
}

public class Score 
{
	public void asdf()
	{
		for (int x; ; ) 
		{
			x = 5;
			
			if (x == 5)
				System.out.println("x is equal to " + x);
			break;
		}
	}
}