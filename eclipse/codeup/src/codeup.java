import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		TreeSet<Third> tSet=new TreeSet<Third>();
		int n=s.nextInt();
		String x;
		int y;
		
		for(int i=0;i<n;i++)
		{
			x=s.next();
			y=s.nextInt();
			tSet.add(new Third(x, y));
		}
		Iterator<Third> iter=tSet.iterator();
		while(iter.hasNext())
			System.out.println(iter.next());
	}
}
class Third implements Comparable<Third>
{
	String name;
	int score;
	
	public Third(String name, int score)
	{
		this.name=name;
		this.score=score;
	}
	public int compareTo(Third t)
	{
		if(score>t.score)
			return -1;
		else if(score<t.score)
			return 1;
		else
			return 0;
	}
	public String toString()	{	return name + " " + score;	}
}