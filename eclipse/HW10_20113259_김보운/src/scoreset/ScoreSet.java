package scoreset;

import java.util.ArrayList;

public class ScoreSet
{
	public ScoreSet()
	{
		scores = new ArrayList<Integer>();
	}
	public void add(int score)
	{
		//Integer wrapper = new Integer(score);
		scores.add(score);
	}
	public double averageWithoutLowest2() 
	{
		double sum = 0;
		
		scores.sort(null);
		
		for(int i = 2; i < scores.size(); i++)
			sum += scores.get(i);
		
		return sum / (scores.size() - 2);
	}
	public String toString()
	{
		String result = "[";
		for(int i = 0; i < scores.size() - 1; i++)
			result += scores.get(i) + " ";
		result += scores.get(scores.size() - 1) + "]";
		return result;
	}
	private ArrayList<Integer> scores;
}
class Main
{
	public static void main(String[] args)
	{
		ScoreSet s = new ScoreSet();
		
		s.add(100);
		s.add(90);
		s.add(80);
		s.add(70);
		s.add(60);
		s.add(50);
		s.add(40);
		s.add(30);
		s.add(20);
		s.add(10);
		
		s.averageWithoutLowest2();
		
		System.out.println(s);
	}
}