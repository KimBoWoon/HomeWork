package kr.otherpkg;
import kr.ac.kookmin.cs.*;

class PPointTest
{
	/**
	좌표값을 출력하는 main함수
	*/
	public static void main(String[] args)
	{
		PPoint aObj = new PPoint(10, 20);
		System.out.println("aObj(x, y) = " + aObj.getX() + ", " + aObj.getY());
	}
}