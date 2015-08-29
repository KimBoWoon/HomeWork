class decimal_to_binary
{
	public static void main(String[] args)
	{
		int n=30;
		
		tobinary(n);
	}
	public static int tobinary(int n)
	{
		if(n>0)
		{
			int bin=n%2;
			n/=2;
			tobinary(n);
			System.out.print(bin);
		}
		return 0;	
	}
}