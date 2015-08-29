import java.util.*;

public class Count 
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		String phrase;
		int countBlank, countA, countE, countS, countT;
		int length;
		char ch;

		System.out.println();
		System.out.println("Character Counter");
		System.out.println();

		while(true)
		{
			System.out.print("Enter a sentence or type quit : ");
			phrase = in.nextLine();
			length = phrase.length();
			
			if(phrase.compareTo("quit")==0)
				return;
			
			countBlank=countA=countE=countS=countT=0;

			for(int i=0;i<length;i++)
			{
				ch=phrase.charAt(i);

				switch(ch)
				{
				case 'a':
				case 'A':
					countA++;
					break;
				case 'e':
				case 'E':
					countE++;
					break;
				case 's':
				case 'S':
					countS++;
					break;
				case 't':
				case 'T':
					countT++;
					break;
				case ' ':
					countBlank++;
					break;
				}
			}
			System.out.println();
			System.out.printf("countA : %d, countE : %d, countS : %d, countT : %d\n", countA, countE, countS, countT);
			System.out.println("Number of blank spaces: " + countBlank);
			System.out.println();
		}
	}
}
