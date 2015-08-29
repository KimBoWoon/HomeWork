package needle;

import java.util.Random;

public class Needle 
{

	private static Random generator;
	private int hits;
	private int tries;

	public Needle(){
		hits = 0 ;
		tries = 0 ;
		generator = new Random();
	}

	public void drop() {
		double ylow = 2 * generator.nextDouble();
		double angle = 180 * generator.nextDouble();

		double yhigh = ylow + Math.sin(Math.toRadians(angle));
		if(yhigh >= 2) hits++;
		tries++;
	}

	public int getHits() {
		return hits;
	}

	public int getTries() {
		return tries;
	}
}