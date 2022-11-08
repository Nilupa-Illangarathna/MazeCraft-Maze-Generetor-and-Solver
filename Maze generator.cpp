#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::ofstream;
using std::ios;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Solid_block_creation(int width, int height, vector <vector <char>> &maze) //This fills the whole maze area with solid blocks ( 1 )
{
	for (int j = 0; j < width; j++)
	{
		vector <char> temp;
		for (int i = 0; i < height ; i++)
		{
			temp.push_back(char(219)); /* filled character */
		}
		maze.push_back(temp);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Bounds(int xcoord, int ycoord, int width, int height)
{
	if (xcoord < 0 || xcoord >= width)
	{
		return false;
	}
	if (ycoord < 0 || ycoord >= height)
	{
		return false;
	}
	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Generating_the_maze(int xcoord, int ycoord, int width, int height, vector <vector <char>> &maze)
{
	
	maze[xcoord][ycoord] = char(176);

	int Direct[4];
	for (int i = 0; i < 4; i++)
	{
		Direct[i] = i;
	}

	for (int i = 0; i < 4; i++)
	{
		int r = rand() % 3;
		swap(Direct[i], Direct[r]);
	}

	for (int i = 0; i < 4; ++i)
	{
		int X = 0, Y = 0;

		Direct[i] == 0 ? Y = -1 : Direct[i] == 1 ? X = 1 : Direct[i] == 2 ? Y = 1 : X = -1;

		int x2 = xcoord + (X << 1);
		int y2 = ycoord + (Y << 1);
		if (Bounds(x2, y2, width, height))
		{
			if (maze[x2][y2] == char(219))
			{
				maze[x2 - X][y2 - Y] = char(176);
				Generating_the_maze(x2, y2, width, height, maze);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Print_maze(int height, int width, vector <vector <char>> &maze) //To rint the maze on the console
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(maze[j][i] ==char(219)||maze[j][i]==char(176))
			{
				cout << maze[j][i]<<maze[j][i];
			}
			else
			{
				cout << maze[j][i]<<char(176);
			}
		}
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void array_to_txt(int height, int width, vector <vector <char>> &maze) // To get the maze detailes into a txt file
{
	ofstream file;
	file.open("Maze array.txt",ios::app);
	
	file<<height<<endl;
	file<<width<<endl;
	
	//putting all the maze charactors inside the txt file
	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			if(maze[i][j]==char(219))
			{
				file<<"1 ";
			}
			else if(maze[i][j]==char(176))
			{
				file<<"0 ";
			}
			else if(maze[i][j]=='A')
			{
				file<<"A ";
			}
			else
			{	if(maze[i][j]=='B')
				{
					file<<"B ";
				}	
			}
		}
	file<<"\n";
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	//GETTING INPUTS FROM THE USER
	int maze_width, maze_height;
	cout << "Input maze width as given (25,35,45,55,65,75,85,95) : ";
	cin >> maze_width;
	cout << "Input maze height as given (15,25,35,45) : ";
	cin >> maze_height;

	srand(time(NULL)); //random number generator

	//vector to store maze data
	vector <vector <char>> maze;

	Solid_block_creation(maze_width, maze_height, maze);


	Generating_the_maze(1, 1, maze_width, maze_height, maze);
	maze[1][1]='A';
	if(maze[maze_width-2][maze_height-2]==char(176))
	{
		maze[maze_width-2][maze_height-2] ='B';
	}

	Print_maze(maze_height, maze_width, maze);

	array_to_txt(maze_height,maze_width,maze);
	

	return 0;
}








