#include "prob65.h"

bingo::bingo()
{
}
bingo::bingo(int card_num[][card_size])
{
	setcard(card_num);
}
void bingo::setcard(int card_num[][card_size])
{
	for(int i=0;i<card_size;i++)
	{
		for(int j=0;j<card_size;j++)
			bingocard[i][j]=card_num[i][j];
	}
}
int bingo::runbingogame(int numcalls[])
{
	int bingocnt=0;

	for(int i=0;numcalls[i]!=0;i++)
	{
		for(int j=0;j<card_size;j++)
		{
			for(int k=0;k<card_size;k++)
			{
				if(bingocard[j][k]==numcalls[i])
					bingocard[j][k]=0;
			}
		}
		for(int j=0;j<card_size;j++)
		{
			for(int k=0;k<card_size;k++)
			{
				if(bingocard[j][k]==0)
					bingocnt++;
			}
			if(bingocnt==card_size)
				return i+1;
			else
				bingocnt=0;
		}
		for(int j=0;j<card_size;j++)
		{
			for(int k=0;k<card_size;k++)
			{
				if(bingocard[k][j]==0)
					bingocnt++;
			}
			if(bingocnt==card_size)
				return i+1;
			else
				bingocnt=0;
		}
		for(int j=0;j<card_size;j++)
		{
			if(bingocard[j][j]==0)
				bingocnt++;

			if(bingocnt==card_size)
				return i+1;
		}
		bingocnt=0;
		for(int j=0;j<card_size;j++)
		{
			for(int k=0;k<card_size;k++)
			{
				if(j+k==4)
				{
					if(bingocard[j][k]==0)
						bingocnt++;
				}
			}
			if(bingocnt==card_size)
				return i+1;
		}
		bingocnt=0;
	}
}