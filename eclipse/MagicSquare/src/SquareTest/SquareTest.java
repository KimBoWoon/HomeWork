package SquareTest;

import java.util.Scanner;
import Square.Square;

public class SquareTest 
{	
	public static void main(String[] args)
	{
		int count = 1;
		Scanner in = new Scanner(System.in);
		
		System.out.print("size : ");
		int size = in.nextInt();
		
		while(size!=-1)
		{
			Square square = new Square(size);
			
			System.out.printf("%d x %d matrix : \n", size, size);
			square.readSquare();
			
			System.out.println("\n******** Square " + count + " ********");
			
			System.out.println("<<matrix>>");
			square.printSquare();
			
			for(int i=0;i<size;i++)
				System.out.printf("sum of %d row : %d\n", i, square.sumRow(i));
			
			for(int i=0;i<size;i++)
				System.out.printf("sum of %d col : %d\n", i, square.sumCol(i));
			
			System.out.printf("sum of main diagonal : %d\n", square.sumMainDiag());
			
			System.out.printf("sum of other diagonal : %d\n", square.sumOtherDiag());
			
			if(square.magic())
				System.out.println("Magic Square");
			else
				System.out.println("not Magic Square");

			System.out.print("size : ");
			size = in.nextInt();
		}
	}
}