class Geometry
{
	public static double circleCircumference(int r)
	{
		return r * 2 * 3.14;
	}
	public static double circleArea(int r)
	{
		return 3.14 * r * r;
	}
}
public class Circle 
{
	private int radius = 0;
	
	public double circleCircumference(int r)
	{
		return r * 2 * 3.14;
	}
	public double circleArea(int r)
	{
		return 3.14 * r * r;
	}
	public int compareRadius(double radius)
	{
		final double EPSILON = 1E-12;
		double diff = this.radius - radius;
		
		if(Math.abs(diff) < EPSILON)
			return 0;
		else if(diff < 0)
			return -1;
		else if(diff > 0)
			return 1;
		else
			return 3;
	}
}
class ControlClass
{
	public static void main(String[] args)
	{
		Circle c = new Circle();
		
		c.circleCircumference(5);
		c.circleArea(5);
	}
}