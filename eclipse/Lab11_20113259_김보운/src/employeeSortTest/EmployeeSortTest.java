package employeeSortTest;

import java.util.*;

public class EmployeeSortTest 
{
	public static void main(String[] args)
	{
		ArrayList<Employee> al = new ArrayList<Employee>();
		
		al.add(new Employee(20071008, "Harry Hacker", 35000));
		al.add(new Employee(20010003, "Carl Cracker", 75000));
		al.add(new Employee(2004001, "Tony Tester", 38000));
		
		al.sort(null);
		//Employee[] staff = new Employee[3];
		
		//staff[0] = new Employee(20071008, "Harry Hacker", 35000);
		//staff[1] = new Employee(20010003, "Carl Cracker", 75000);
		//staff[2] = new Employee(2004001, "Tony Tester", 38000);
		
		//Arrays.sort(staff);
		
		Iterator<Employee> i = al.iterator();
		while(i.hasNext())
			System.out.println(i.next());
		//for(Employee e : al)
			//System.out.println("companyID = " + e.getcompanyID() + ", name = " + e.getName() + ", salary = " + e.getSalary());
	}
}
