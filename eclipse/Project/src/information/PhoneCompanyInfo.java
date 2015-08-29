package information;

public class PhoneCompanyInfo extends PhoneInfo
{
	private String company;
	
	public PhoneCompanyInfo(String n, String p, String c)
	{
		super(n, p);
		company=c;
	}
	public void showInfo()
	{
		super.showInfo();
		System.out.println("È¸»ç : " + company);
	}
}