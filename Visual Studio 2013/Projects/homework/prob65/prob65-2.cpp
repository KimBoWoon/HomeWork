#include "prob65.h"

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream>>cases;
	bingo bingo;

	for(int i=0;i<cases;i++)
	{
		int cardnum[card_size][card_size];
		int numcalls[num_calls]={0};

		for(int j=0;j<card_size;j++)
		{
			for(int k=0;k<card_size;k++)
				inStream>>cardnum[j][k];
		}

		bingo.setcard(cardnum);
		
		for(int j=0;j<num_calls;j++)
		{
			if(inStream.eof()==1)
				break;
			else
				inStream>>numcalls[j];
		}

		cout<<bingo.runbingogame(numcalls)<<endl;
	}
	inStream.close();
}