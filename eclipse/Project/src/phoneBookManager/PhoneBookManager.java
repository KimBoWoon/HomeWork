package phoneBookManager;

import java.io.*;
import java.util.*;

import information.*;
import exception.MenuNumException;

interface InputNum
{
	int NORMAL=1, UNIV=2, COMPANY=3;
}
public class PhoneBookManager
{
	private final File dataFile=new File("Data.txt");
	private static PhoneBookManager inst=null;
	private Scanner input=new Scanner(System.in);
	//private PhoneInfo[] person=new PhoneInfo[100];
	private int choice;
	HashSet<PhoneInfo> infoStorage=new HashSet<PhoneInfo>();

	private PhoneBookManager()	{	readFromFile();	}
	public void inputData() throws MenuNumException
	{
		System.out.println("1. �Ϲ�, 2. ����, 3. ȸ��");
		System.out.print("���� : ");
		choice=input.nextInt();
		input.nextLine();
		PhoneInfo info=null;

		if(choice<InputNum.NORMAL || choice>InputNum.COMPANY)
			throw new MenuNumException(choice);

		switch(choice)
		{
			case InputNum.NORMAL:
				info=readFriendInfo();
				break;
			case InputNum.UNIV:
				info=readUnivFriendInfo();
				break;
			case InputNum.COMPANY:
				info=readCompanyFriendInfo();
				break;
		}

		boolean isAdded=infoStorage.add(info);
		if(isAdded)
			System.out.println("�Է��� �Ϸ�Ǿ����ϴ�.");
		else
			System.out.println("�̹� ����� �������Դϴ�.");
	}
	private PhoneInfo readFriendInfo()
	{
		System.out.print("�̸�: ");
		String name=input.nextLine();
		System.out.print("��ȭ��ȣ: ");
		String phone=input.nextLine();
		return new PhoneInfo(name, phone);
	}

	private PhoneInfo readUnivFriendInfo()
	{
		System.out.print("�̸�: ");
		String name=input.nextLine();
		System.out.print("��ȭ��ȣ: ");
		String phone=input.nextLine();
		System.out.print("����: ");
		String major=input.nextLine();
		System.out.print("�г�: ");
		int year=input.nextInt();
		input.nextLine();
		return new PhoneUnivInfo(name, phone, major, year);
	}

	private PhoneInfo readCompanyFriendInfo()
	{
		System.out.print("�̸�: ");
		String name=input.nextLine();
		System.out.print("��ȭ��ȣ: ");
		String phone=input.nextLine();
		System.out.print("ȸ��: ");
		String company=input.nextLine();
		return new PhoneCompanyInfo(name, phone, company);
	}
	public void searchData()
	{
		System.out.print("�̸��� �Է��ϼ��� : ");
		String name=input.nextLine();
//		int index=search(name);
//		if(index>=0)
//		{
//			person[index].showInfo();
//			System.out.println("������ �˻��� �Ϸ�Ǿ����ϴ�.");
//		}
//		else
//			System.out.println("�������� �ʴ� ������ �Դϴ�.");
		PhoneInfo info=search(name);
		if(info==null)
			System.out.println("�ش��ϴ� �����Ͱ� �������� �ʽ��ϴ�.");
		else
		{
			info.showInfo();
			System.out.println("������ �˻��� �Ϸ�Ǿ����ϴ�.");
		}
	}
	public void deleteData()
	{
		System.out.print("�̸��� �Է��ϼ��� : ");
		String name=input.nextLine();
//		int index=search(name);
//		if(index>=0)
//		{
//			for(int i=index;i<num;i++)
//				person[index]=person[index+1];
//			num--;
//			System.out.println("������ ������ �Ϸ�Ǿ����ϴ�.");
//		}
//		else
//			System.out.println("�������� �ʴ� ������ �Դϴ�.");
		Iterator<PhoneInfo> iter=infoStorage.iterator();
		while(iter.hasNext())
		{
			PhoneInfo curInfo=iter.next();
			if(name.compareTo(curInfo.name)==0)
			{
				iter.remove();
				System.out.println("������ ������ �Ϸ�Ǿ����ϴ�.");
				return;
			}
		}
		System.out.println("�������� �ʴ� ������ �Դϴ�.");
	}
	private PhoneInfo search(String name)
	{
		Iterator<PhoneInfo> iter=infoStorage.iterator();
		while(iter.hasNext())
		{
			PhoneInfo curInfo=iter.next();
			if(name.compareTo(curInfo.name)==0)
				return curInfo;
		}
		return null;
//		for(int i=0;i<num;i++)
//		{
//			if(name.compareTo(person[i].name)==0)
//				return i;
//		}
//		return -1;
	}
	public void print()
	{
//		if(num==0)
//			System.out.println("�Էµ� �����Ͱ� �����ϴ�.");
//		else
//		{
//			for(int i=0;i<num;i++)
//				person[i].showInfo();
//		}
		Iterator<PhoneInfo> iter=infoStorage.iterator();
		if(!(iter.hasNext()))
			System.out.println("����� ������ �����ϴ�!");
		else
		{
			while (iter.hasNext())
				System.out.println(iter.next());
		}
	}
	public static PhoneBookManager createManagerInst()
	{
		if(inst==null)
			inst=new PhoneBookManager();
		return inst;
	}
	public void storeToFile()
	{
		try
		{
			FileOutputStream file=new FileOutputStream(dataFile);
			ObjectOutputStream out=new ObjectOutputStream(file);

			Iterator<PhoneInfo> iter=infoStorage.iterator();
			while(iter.hasNext())
				out.writeObject(iter.next());
			out.close();
		}
		catch(IOException e)	{	e.printStackTrace();	}
	}
	public void readFromFile()
	{
		if(dataFile.exists()==false)
			return;
		try
		{
			FileInputStream file=new FileInputStream(dataFile);
			ObjectInputStream in=new ObjectInputStream(file);

			while(true)
			{
				PhoneInfo info=(PhoneInfo)in.readObject();
				if(info==null)
					break;
				infoStorage.add(info);
			}
			in.close();
		}
		catch(IOException e)	{	return;	}
		catch(ClassNotFoundException e)	{	return;	}
	}
}