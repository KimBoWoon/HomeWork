package randomnumber;

import java.util.Random;
import java.util.Scanner;

public class RandomNumber
{
	public static void main(String[] args)
	{
		Random r = new Random();
		Scanner in = new Scanner(System.in);
		
		System.out.print("�� ���� ������ �����ұ��? ");
		int size = in.nextInt();
		System.out.print("������ ������ �����ϼ���. ");
		int range = in.nextInt();
		int[] arr = new int[size];
		
		for(int i = 0; i < size; i++)
			arr[i] = r.nextInt(range);
		
		for(int i = 0; i < size; i++)
			System.out.println(i + " " + arr[i]);
	}
}