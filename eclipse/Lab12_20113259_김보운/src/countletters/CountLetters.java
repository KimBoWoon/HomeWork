package countletters;

import java.util.Scanner;

public class CountLetters 
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int[] counts = new int[26];

		System.out.print("Enter a single word (letters only, please) : ");
		String word = in.next();

		word = word.toUpperCase();

		for (int i = 0; i < word.length(); i++)
		{
			try
			{
				counts[word.charAt(i) - 'A']++;
			}
			catch(ArrayIndexOutOfBoundsException exp)
			{
				System.out.println("Not a letter : " + word.charAt(i));
			}
		}

		System.out.println();
		for (int i = 0; i < counts.length; i++)
		{
			if (counts[i] != 0)
				System.out.println((char) (i + 'A') + " : " + counts[i]);
		}
	}
}
