package student;

import java.util.Scanner;

public class Student 
{
	String name;
	int score1 = -1, score2 = -1;
	Scanner in = new Scanner(System.in);

	public Student(String studentName)
	{
		name = studentName;
	}
	public void inputGrades()
	{
		while(true)
		{
			System.out.print("first score : ");
			score1 = in.nextInt();
			System.out.print("second score : ");
			score2 = in.nextInt();
			
			if((score1 < 101 && score1 > -1) && (score2 < 101 && score2 > -1))
				break;
			else
				continue;
		}
	}
	public double getAverage()
	{
		return (score1 + score2) / 2;
	}
	public void printName()
	{
		System.out.print(name);
	}
	public String getName()
	{
		return name;
	}
	public String toString()
	{
		return "Name: " + name + " Test1: " + score1 + " Test2: " + score2;
	}
}