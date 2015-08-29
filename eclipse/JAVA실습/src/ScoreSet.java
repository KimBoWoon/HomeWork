import java.util.ArrayList;
import java.util.Scanner;

class ControlClass1
{
	public static Scanner in = new Scanner(System.in);
	private static int size;

	public static void main(String[] args)
	{
		ScoreSet s = new ScoreSet();

		System.out.print("사이즈를 입력하세요 : ");
		size = in.nextInt();
		System.out.println("학생들의 점수를 입력하세요 : ");
		for(int i = 0; i < size; i++)
			s.add(in.nextInt());

		double average = s.averageWithoutLowest2();

		System.out.printf("평균 : %.1f\n", average);
		System.out.println(s);
	}
}
public class ScoreSet
{
	private ArrayList<Integer> scores;

	public ScoreSet()
	{
		scores = new ArrayList<Integer>();
	}
	public void add(int score)
	{
		//		Integer wrapper = new Integer(score);
		//		scores.add(wrapper);
		scores.add(score);
	}
	public double averageWithoutLowest2()
	{
		int sum = 0;
		//		for(int i = 0;i < scores.size();i++)
		//			sum += scores.get(i);
		//		
		//		System.out.printf("총점 : %d\n", sum);
		//		
		//		return sum / scores.size();
		scores.sort(null);
		scores.remove(0);
		scores.remove(0);
		for(int i=0;i<scores.size();i++)
			sum+=scores.get(i);
		return sum / scores.size();
	}
	public String toString()
	{
		String str = new String("");
		int t = 0;

		str += '[';
		for(Integer i : scores)
		{
			if(scores.size()-1 == t)
				str += i;
			else
				str += i + " ";
			t++;
		}
		str += ']';

		return str;
	}
}