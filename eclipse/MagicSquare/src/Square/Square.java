package Square;

import java.util.Scanner;

public class Square 
{
	int[][] square;
	Scanner in = new Scanner(System.in);
	
	public Square(int size)	{	square = new int[size][size];	}
	public int sumRow(int row)
	{
		int sum=0;
		
		for(int i=0;i<square[row].length;i++)
			sum+=square[row][i];
		
		return sum;
	}
	public int sumCol(int col)
	{
		int sum=0;
		
		for(int i=0;i<square[col].length;i++)
			sum+=square[i][col];
		
		return sum;
	}
	public int sumMainDiag()
	{
		int sum=0;
		
		for(int i=0;i<square.length;i++)
			sum+=square[i][i];
		
		return sum;
	}
	public int sumOtherDiag()
	{
		int sum=0;
		
		for(int i=0;i<square.length;i++)
			sum+=square[i][(square.length-1)-i];
		
		return sum;
	}
	public boolean magic()
	{
		int sum = sumRow(0);
		
		for(int i=1;i<square.length;i++)
		{
			if(sum != sumRow(i))
				return false;
		}
		for(int i=0;i<square.length;i++)
		{
			if(sum != sumCol(i))
				return false;
		}
		if(sum != sumMainDiag())
			return false;
		if(sum != sumOtherDiag())
			return false;
		return true;
	}
	public void readSquare()
	{
		for(int i=0; i < square.length; i++)
		{
			for(int j=0; j < square.length; j++)
				square[i][j] = in.nextInt();
		}
	}
	public void printSquare()
	{
		for(int i=0; i < square.length; i++)
		{
			for(int j=0; j < square.length; j++)
				System.out.print(square[i][j] + " ");
			System.out.println();
		}
	}
}