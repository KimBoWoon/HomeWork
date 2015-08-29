import java.util.*;

public class Control 
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter a number : ");
		
		int num = in.nextInt();
		
		if(num<0)
		{
			System.out.println("num은 0보다 커야한다.");
			return;
		}
		
		while(num<50)
		{
			if(num%5 == 0)
				System.out.println(num);
			num++;
		}
	}
}