package card;

public class Card
{
	public Card()
	{
		name = "";
	}
	public Card(String n)
	{
		name = n;
	}
	public String getName()
	{
		return name;
	}
	public boolean isExpired()
	{
		return false;
	}
	public String format()
	{
		return "Card holder: " + name;
	}
	private String name;
}