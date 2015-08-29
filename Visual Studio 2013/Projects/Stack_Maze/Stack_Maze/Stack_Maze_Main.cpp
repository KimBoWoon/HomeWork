// HW 1
// Name :
// Student ID :

#include "Stack_Maze.h"

int **mark; // mark
int **maze; // maze

int main()
{
	try
	{
		while (1)
		{
			cerr << "Maze> " << endl;
			string command;
			cin >> command;
			if (command.compare("quit") == 0)
				break;
			else if (command.compare("maze") == 0)
			{
				int m, p;

				cout << "Enter the dimension m, p of the maze " << endl;
				cin >> m >> p;
				maze = new int*[m + 2];
				mark = new int*[m + 2];

				int i, j;
				for (i = 0; i < m + 2; i++)
				{
					maze[i] = new int[p + 2];
					mark[i] = new int[p + 2];
				}
				for (i = 0; i < m + 2; i++)
					for (j = 0; j < p + 2; j++)
					{
					maze[i][j] = 1;
					mark[i][j] = 0;
					}
				cout << "Enter the Maze" << endl;
				for (i = 1; i <= m; i++)
					for (j = 1; j <= p; j++)
						cin >> maze[i][j];

				// run Path() algorithm
				Path(m, p, maze, mark);

				delete maze;
				delete mark;
			}
		}
	}
	catch (const char *e)
	{
		cout << "Command Error : " << e << endl;
	}

	return 1;
}