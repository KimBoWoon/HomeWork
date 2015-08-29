// HW 1
// Name : Kim Bo Woon
// Student ID : 20113259

#include "Stack_Maze.h"

class Position
{
public:
	Position(int x = 0, int y = 0)	{ row = x;	col = y; }
	int getrow() const	{ return row; }
	int getcol() const	{ return col; }
	int getdir() const	{ return dir; }
	void setpos(int r, int c)	{ row = r;	col = c; }
	void setpos(Position& p)	{ row = p.row;	col = p.col; }
	void setdir(int d)	{ dir = d; }
private:
	int row, col, dir;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity), top(-1)
{
	// NEED TO IMPLEMENT
	stack = new T[capacity];
}
template <class T>
Stack<T>::~Stack()	{ delete[]stack; }

// If number of elements in the stack is 0, return true else return false
template <class T>
inline bool Stack<T>::IsEmpty() const
{
	// NEED TO IMPLEMENT
	return top == -1;
}
template <class T>
inline bool Stack<T>::IsFull() const
{
	// NEED TO IMPLEMENT
	return top == capacity;
}

template <class T>
inline T & Stack<T>::Top() const
{
	// NEED TO IMPLEMENT
	return stack[top];
}

template <class T>
void Stack<T>::Push(const T & item)
{
	// NEED TO IMPLEMENT
	if (!(IsFull()))
		stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
	// NEED TO IMPLEMENT
	if (!(IsEmpty()))
		stack[top--] = 0;
}

void Path(const int m, const int p, int **maze, int **mark)
{// Output a path (if any) in the maze; 

	// start at (1,1)
	//mark[0][0] = 5;
	Stack<Position> s, rs;
	Position pos, nextpos;
	int dir;
	int direction[8][2] = { { 0, 1 }, { 1, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 } };
	//E, SE, NE, N, NW, W, SW, S

	pos.setdir(0);
	nextpos.setdir(0);

	while (true)
	{
		for (dir = nextpos.getdir(); dir < 8; dir++)
		{
			nextpos.setpos(pos.getrow() + direction[dir][0], pos.getcol() + direction[dir][1]);

			if ((maze[nextpos.getrow()][nextpos.getcol()] == 0) && (mark[nextpos.getrow()][nextpos.getcol()] != 5) && (mark[nextpos.getrow()][nextpos.getcol()] != 2))
			{
				mark[nextpos.getrow()][nextpos.getcol()] = 5;
				pos.setpos(nextpos);
				pos.setdir(dir);
				s.Push(pos);
				nextpos.setdir(0);
				break;
			}
		}
		if (dir == 8)
		{
			mark[pos.getrow()][pos.getcol()] = 2;
			s.Pop();
			pos.setpos(s.Top());
			nextpos.setdir(s.Top().getdir() + 1);
		}
		if (mark[m][p] == 5)
			break;
		if (mark[1][1] == 2)
			break;
	}

	// NEED TO IMPLEMENT
	if (s.top != -1)
	{
		while (!(s.IsEmpty()))
		{
			rs.Push(s.Top());
			s.Pop();
		}
		while (!(rs.IsEmpty()))
		{
			cout << "(" << rs.Top().getrow() << ", " << rs.Top().getcol() << ")" << endl;
			rs.Pop();
		}
	}
	else
		cout << "No path in the maze." << endl;
}