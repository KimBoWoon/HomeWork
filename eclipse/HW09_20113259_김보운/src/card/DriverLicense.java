package card;

public class DriverLicense extends Card
{
	private String idNumber;
	
	public DriverLicense(String n, String id)
	{
		super(n);
		idNumber = id;
	}
}