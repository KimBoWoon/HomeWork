package factorials;

import java.util.Scanner;

public class Factorials
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		char keepGoing = 'y';

		while (keepGoing == 'y' || keepGoing == 'Y')
		{
			try
			{
				System.out.print("Enter an integer : ");
				int val = in.nextInt();
				System.out.println("Factorial (" + val + ") = " + MathUtils.factorial(val));
				System.out.print("Another factorial? (y/n) ");
				keepGoing = in.next().charAt(0);
			}
			catch (IllegalArgumentException exp)
			{
				System.out.println(exp.getMessage());
			}
		}
	}
}
