package information;

import java.io.*;

public class PhoneInfo implements Serializable
{
	public String name, phoneNumber;
	
	public PhoneInfo(String n, String p)
	{
		name=n;
		phoneNumber=p;
	}
	public void showInfo()
	{
		System.out.println("�̸� : " + name);
		System.out.println("��ȭ��ȣ : " + phoneNumber);
	}
	public int hashCode()
	{
		return name.hashCode();
	}
	public boolean equals(Object o)
	{
		PhoneInfo p=(PhoneInfo)o;
		
		if(name.compareTo(p.name)==0)
			return true;
		else
			return false;
	}
}