package kr.ac.kookmin.cs;

public class PPoint
{
	/** xA, yA ���� ���� */
	int xA;
	int yA;
	/** �����ڸ� �̿��� xA, yA�� ���� �ʱ�ȭ */
	public PPoint(int x, int y)
	{
		xA = x;
		yA = y;
	};
	/** xA�� ���� ��ȯ */
	public int getX()	{	return xA;	}
	/** yA�� ���� ��ȯ */
	public int getY()	{	return yA;	}
}