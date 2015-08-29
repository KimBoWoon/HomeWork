package speaker;

public class Dog extends Speaker 
{
	public void speak()
	{
		System.out.println("woof");
	}
	public void announce(String announcement)
	{
		System.out.println("woof : " + announcement);
	}
}
