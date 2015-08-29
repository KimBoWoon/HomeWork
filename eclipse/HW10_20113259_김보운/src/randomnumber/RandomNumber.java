package randomnumber;

import java.util.Random;
import java.util.Scanner;

public class RandomNumber
{
	public static void main(String[] args)
	{
		Random r = new Random();
		Scanner in = new Scanner(System.in);
		
		System.out.print("몇 개의 난수를 생성할까요? ");
		int size = in.nextInt();
		System.out.print("난수의 범위를 설정하세요. ");
		int range = in.nextInt();
		int[] arr = new int[size];
		
		for(int i = 0; i < size; i++)
			arr[i] = r.nextInt(range);
		
		for(int i = 0; i < size; i++)
			System.out.println(i + " " + arr[i]);
	}
}