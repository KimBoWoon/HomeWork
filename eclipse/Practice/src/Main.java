import Practice.Class1;
import other.Class2;

public class Main 
{
	public static void main(String[] args)
	{
		Class1 c1 = new Class1();
		Class2 c2 = new Class2();
		
		c1.print();
		c2.print();
		
		Class1.staticPrit();
		Class2.staticPrit();
	}
}