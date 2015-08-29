package information;

public class PhoneUnivInfo extends PhoneInfo
{
	private String major;
	private int year;
	
	public PhoneUnivInfo(String n, String p, String m, int y)
	{
		super(n, p);
		major=m;
		year=y;
	}
	public void showInfo()
	{
		super.showInfo();
		System.out.println("학년 : " + year);
		System.out.println("전공 : " + major);
	}
}