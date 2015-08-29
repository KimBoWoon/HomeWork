package fruitSalesMain;

import fruitBuyer.FruitBuyer;
import fruitSeller.FruitSeller;

class FruitSalesMain3
{
	public static void main(String[] args)
	{
		FruitSeller seller1 = new FruitSeller(0, 30, 1500);
		FruitSeller seller2 = new FruitSeller(0, 20, 1000);
		
		FruitBuyer buyer = new FruitBuyer(10000);
		buyer.buyApple(seller1, 4500);
		buyer.buyApple(seller2, 2000);
		
		System.out.println("���� �Ǹ���1�� ���� ��Ȳ");
		seller1.showSaleResult();
		
		System.out.println("���� �Ǹ���2�� ���� ��Ȳ");
		seller2.showSaleResult();
		
		System.out.println("���� �������� ���� ��Ȳ");
		buyer.showBuyResult();
	}
}