import java.util.Vector;

class Point
{
	private int x, y;
	
	public Point(int xpos, int ypos)
	{
		x=xpos;
		y=ypos;
	}
	public void SetX(int xpos)
	{
		x=xpos;
	}
	public void SetY(int ypos)
	{
		y=ypos;
	}
	public String toString()
	{
		return "[x : " + x + ", y : " + y + "]";
	}
}
class VectorPractice
{
	public static void main(String[] args)
	{
		Vector<Point> point=new Vector<Point>();
		
		for(int i=0;i<10;i++)
			point.add(new Point(i, i));
		
		System.out.println(point.capacity());
		System.out.println(point.size());
		for(int i=0;i<point.size();i++)
			System.out.println(point.get(i));
		
		for(int i=0;i<10;i++)
			point.add(new Point(i+10, i+10));
		
		System.out.println(point.capacity());
		System.out.println(point.size());
		for(int i=0;i<point.size();i++)
			System.out.println(point.get(i));
	}
}