package control;

import phoneBookManager.PhoneBookManager;
import java.util.*;

import exception.MenuNumException;

interface MenuNum
{
	int INPUT=1, SEARCH=2, DELETE=3, PRINT=4, EXIT=5;
}
class MenuViewer
{
	public static void showMenu()
	{
		System.out.println("�����ϼ���.");
		System.out.println("1. ������ �Է�");
		System.out.println("2. ������ �˻�");
		System.out.println("3. ������ ����");
		System.out.println("4. �Էµ� ������ ���");
		System.out.println("5. ���α׷� ����");
		System.out.print("���� : ");
	}
}
public class Main
{
	private static Scanner input=new Scanner(System.in);

	public static void main(String[] args)
	{
		PhoneBookManager manager=PhoneBookManager.createManagerInst();
		int choice;

		while(true)
		{
			try
			{
				MenuViewer.showMenu();
				choice=input.nextInt();
				input.nextLine();

				if(choice<MenuNum.INPUT || choice>MenuNum.EXIT)
					throw new MenuNumException(choice);
				
				switch (choice)
				{
				case MenuNum.INPUT:
					manager.inputData();
					break;
				case MenuNum.SEARCH:
					manager.searchData();
					break;
				case MenuNum.DELETE:
					manager.deleteData();
					break;
				case MenuNum.PRINT:
					manager.print();
					break;
				case MenuNum.EXIT:
					manager.storeToFile();
					System.out.print("���α׷��� ���� �˴ϴ�.");
					return;
				}
			}
			catch(MenuNumException e)
			{
				System.out.println(e.getMessage());
				System.out.println("ó������ �ٽ� �����մϴ�.");
			}
		}
	}
}