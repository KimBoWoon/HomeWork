package kr.ac.kookmin.cs;

public class PPoint
{
	/** xA, yA 변수 설정 */
	int xA;
	int yA;
	/** 생성자를 이용해 xA, yA의 값을 초기화 */
	public PPoint(int x, int y)
	{
		xA = x;
		yA = y;
	};
	/** xA의 값을 반환 */
	public int getX()	{	return xA;	}
	/** yA의 값을 반환 */
	public int getY()	{	return yA;	}
}