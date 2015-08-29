import java.util.*;

public class Temps 
{
	public static void main(String [] args)
	{
		final int HOURS_PER_DAY=24;
		
		int temp;
		int maxTemp=-1000;
		int maxHour=0;
		int minTemp=1000;
		int minHour=1000;
		
		System.out.println();
		System.out.println("Temperature Readings for 24 Hour Period");
		System.out.println();
		
		Scanner in = new Scanner(System.in);
		
		for(int hour=0;hour<HOURS_PER_DAY;hour++)
		{
			System.out.print("Enter the temperature reading at " + hour + " hours: ");
			temp=in.nextInt();
			
			if(maxTemp < temp)
			{
				maxTemp=temp;
				maxHour=hour;
			}
			if(minTemp > temp)
			{
				minTemp=temp;
				minHour=hour;
			}
		}
		System.out.printf("maxTemp : %d maxHour : %d\n", maxTemp, maxHour);
		System.out.printf("minTemp : %d minHour : %d\n", minTemp, minHour);
	}
}
