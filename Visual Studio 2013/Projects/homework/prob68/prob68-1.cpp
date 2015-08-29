#include "prob68.h"

class position
{
public:
	position(int x=0, int y=0)	{	row=x;	col=y;	}
	int getrow() const	{	return row;	}
	int getcol() const	{	return col;	}
	int getdir() const	{	return dir;	}
	void setpos(int r, int c)	{	row=r;	col=c;	}
	void setpos(position& p)	{	row=p.row;	col=p.col;	}
	void setdir(int d)	{	dir=d;	}

private:
	int row;
	int col;
	int dir;
};

static int direction[8][2]={{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

knighttour::knighttour()	{	sizerow=sizecol=8;	}
knighttour::knighttour(int srow, int scol)
{
	if(srow>=2 && srow<=MAX_SIZE)
		sizerow=srow;
	else
		sizerow=8;

	if(scol>=2 && scol<=MAX_SIZE)
		sizecol=scol;
	else
		sizecol=8;
}

bool knighttour::buildknighttour(int startrow, int startcol)
{
	for(int r=0;r<sizerow;r++)
	{
		for(int c=0;c<sizecol;c++)
			board[r][c]=0;
	}
	if(startrow<=0 || startrow>sizerow)
		startrow=0;
	if(startcol<=0 || startcol>sizecol)
		startcol=0;

	board[startrow-1][startcol-1]=1;

	return recurknighttour(startrow-1, startcol-1, 1);
}
void knighttour::printboard()
{
	for(int r=0;r<sizerow;r++)
	{
		for(int c=0;c<sizecol;c++)
			cout<<board[r][c]<<" ";
		cout<<endl;

	}
}

bool knighttour::recurknighttour(int startrow, int startcol, int move)
{
	int nextrow, nextcol;

	if(move==sizerow*sizecol)
		return true;
	
	for(int dir=0;dir<8;dir++)
	{
		nextrow=startrow+direction[dir][0];
		nextcol=startcol+direction[dir][1];

		if(isvalidmove(nextrow, nextcol))
		{
			board[nextrow][nextcol]=++move;
			if(recurknighttour(nextrow, nextcol, move))
				return true;
			else
			{
				move--;
				board[nextrow][nextcol]=0;
			}
		}
	}
	return false;
}
bool knighttour::isvalidmove(int row, int col)
{
	if(row>=sizerow || row<0)
		return false;
	if(col>=sizecol || col<0)
		return false;
	if(board[row][col]!=0)
		return false;
	else
		return true;
}