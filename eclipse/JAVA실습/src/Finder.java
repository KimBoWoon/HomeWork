import java.util.Scanner;

public class Finder
{
	public Finder(String aString)	{	s = aString;	}
	public int findFirst(String sub)
	{
		int i = 0;
		while (sub.length() + i <= s.length())
		{
			if(s.substring(i, i + sub.length()).equals(sub))
				return i;
			else
				i++;
		}
		return -1;
	}
	public int findLast(String sub)
	{
		String sCopy = s;
		while (sub.length() <= sCopy.length())
		{
			if(sCopy.substring(sCopy.length() - sub.length(),
					sCopy.length()).equals(sub))
				return sCopy.length() - sub.length();
			else
				sCopy = sCopy.substring(0, sCopy.length() - 2);
		}
		return -1;
	}
	private String s;
}
class MainClass
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("첫 번째 문자열 입력 : ");
		String str1 = in.nextLine();
		System.out.print("두 번째 문자열 입력 : ");
		String str2 = in.nextLine();
		
		Finder f = new Finder(str1);
		if(f.findFirst(str2) == 0)
			System.out.println("동일 문자열");
		else
			System.out.println("다른 문자열");
		if(f.findLast(str2) == 0)
			System.out.println("동일 문자열");
		else
			System.out.println("다른 문자열");
	}
}