package employeeSortTest;

public class Employee implements Comparable<Employee> 
{
	private String name;
	private double salary;
	private int companyID;
	
	public Employee(int companyID, String n, double s)
	{
		this.companyID = companyID;
		name = n;
		salary = s;
	}
	public String getName()
	{
		return name;
	}
	public double getSalary()
	{
		return salary;
	}
	public int getcompanyID()
	{
		return companyID;
	}
	public void raiseSalary(double byPercent)
	{
		double raise = salary * byPercent / 100;
		salary += raise;
	}
	public String toString()
	{
		return "companyID = " + getcompanyID() + ", name = " + getName() + ", salary = " + getSalary();
	}
	public int compareTo(Employee other)
	{
		if(companyID < other.companyID)
			return -1;
		if(companyID > other.companyID)
			return 1;
		return 0;
	}
}
