package exception;

public class MenuNumException extends Exception
{
	private int choice;
	
	public MenuNumException(int c)	{	choice=c;	}
	public String getMessage()	{	return choice + "�� �ش��ϴ� �޴��� �����ϴ�.";	}
}