package student;

public class Grades 
{
	public static void main(String[] args)
	{
		Student student1 = new Student("Mary");
		Student student2 = new Student("Mike");
		
		student1.inputGrades();
		System.out.print("Student 1: " + student1);
		
		System.out.println();
		
		student2.inputGrades();
		System.out.print("Student 2: " + student2);
	}
}
