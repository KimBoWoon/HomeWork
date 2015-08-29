package bankaccount;

import java.util.ArrayList;
import java.util.Collections;

/**
   This program tests the Bank class.
 */
public class BankTester
{
	public static void main(String[] args)
	{
		ArrayList<BankAccount> list = new ArrayList<BankAccount>();
		
		BankAccount ba1 = new BankAccount(1, 3000);
		BankAccount ba2 = new BankAccount(1, 2000);
		BankAccount ba3 = new BankAccount(1, 1000);
		BankAccount ba4 = new BankAccount(1, 5000);
		BankAccount ba5 = new BankAccount(1, 4000);
		
		list.add(ba1);
		list.add(ba2);
		list.add(ba3);
		list.add(ba4);
		list.add(ba5);
		
		Collections.sort(list);
		
		for (BankAccount b : list)
		System.out.println(b.getBalance());
	}
}
