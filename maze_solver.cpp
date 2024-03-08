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
using std::ifstream;
using std::ofstream;
using std::ios;



///////////////////////////////////////////////////////////////////////////////////////////////////////////
void get_maze_from_txt(vector <vector <char>> &maze , int &height , int &width , int &start_row , int &start_col )
{
	//opening the "Maze array.txt"
	ifstream file;
	file.open("Maze array.txt");
	
	//Width and height information to declare a 2D vector inside the SOLVER CPP
	file >> height >> width;
	
	//Filling it
	for (int i = 0; i < height; i++)
	{
		vector <char> temp;
		for (int j = 0; j < width; j++)
		{
			char ch;
			file >> ch;
			temp.push_back(ch);
			if(ch=='A')
			{
				start_row=i;
				start_col=j;
			}
		}
		maze.push_back(temp);
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Print_maze(int height, int width, vector <vector <char>> maze) //To print the maze on the console
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (maze[i][j] == '1')
			{
				cout<<char(219)<<char(219);
			}
			else if(maze[i][j] == '0')
			{
				cout<<char(176)<<char(176);
			}			
			else if	(maze[i][j] == 'A')
			{
				cout<<'A'<<char(176);
			}
			else if	(maze[i][j] == '3')
			{
				cout<<'#'<<" ";
			}
			else
			{
				if(maze[i][j] == 'B')
				{
					cout<<'B'<<char(176);
				}
			}
		}
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Visited_points(vector <vector <char>> maze, vector <vector <int>> &visited_cases, int height, int width )
{
	//	path, 0
	//	solid, 1
	//	end, B - 2 	
	
	//filling the 2D vector visited_cases as above
	int i, j;
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			if (maze[i][j] == '1') {
				visited_cases[i][j] = 1;
			}
			else if (maze[i][j] == 'B') {
				visited_cases[i][j] = 2;
			}
			else {
				visited_cases[i][j] = 0;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
int depth_first_search(int row, int column , vector <vector <int>> &visited_cases)  //To find the correct path
{
	
	if (visited_cases[row][column] == 0)  //0 represent paths
	{
		visited_cases[row][column] = 3;   // to keep the correct path tracked

		if (depth_first_search(row, column - 1,visited_cases))   //recursive search
		{
			return 1;
		}
		if (depth_first_search(row + 1, column,visited_cases))  //recursive search
		{
			return 1;
		}
		if (depth_first_search(row, column + 1,visited_cases))  //recursive search
		{
			return 1;
		}
		if (depth_first_search(row - 1, column,visited_cases))  //recursive search
		{
			return 1;
		}
		
		visited_cases[row][column] = 0;  //to remove back tracked paths 
	}
	if (visited_cases[row][column] == 2)  //To identify the end of the maze. (point B)
	{
		return 1;
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void pathdraw(int height, int width, vector <vector <char>> &maze, vector <vector <int>> visited_cases)
{
	//Drawing the path
	int i, j;
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			if (maze[i][j] != 's' && visited_cases[i][j] == 3) {
				maze[i][j] = '3';
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void array_to_txt(int height, int width, vector <vector <char>> &maze)
{
	ofstream file01;
	file01.open("Solved maze.txt",ios::app);
	//putting all the maze charactors inside the txt file
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (maze[i][j] == '1')
			{
				file01<<" 1";
			}
			else if(maze[i][j] == '0')
			{
				file01<<" 0";
			}			
			else if	(maze[i][j] == 'A')
			{
				file01<<" A";
			}
			else if	(maze[i][j] == '3')
			{
				file01<<" #";
			}
			else
			{
				if(maze[i][j] == 'B')
				{
					file01<<" B";
				}
			}
		}
		file01<<"\n";
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	//getting dementions
	int height, width;

	//start point index
	int start_row,start_col;
	
	//creating the 2D vector required
	vector <vector <char>> maze;
	
	//Filling the 2D vector using the txt file
	get_maze_from_txt(maze , height , width, start_row , start_col );

	//Before solving
	cout<<"\n\tBefore solving\n\n";
	Print_maze(height, width, maze);
	
//	cout<<endl<<start_row<<start_col;


	//2D vector for visited cases
	vector <vector <int>> visited_cases;
	
	//filling it with a random value(
	for (int i = 0; i < height; i++)
	{
		vector <int> temp;
		for (int j = 0; j < width; j++)
		{
			temp.push_back(0);
		}
		visited_cases.push_back(temp);
	}
	
	//finding path(DEPTH FIRST SEARCH METHOD)
	Visited_points(maze, visited_cases, height, width );
	if (depth_first_search(start_row, start_col, visited_cases)) { //if depth_first_search function returns 1, So we can go from start to the end (A to B)  
		pathdraw(height, width, maze,visited_cases);  //respective maze entries must be filled with value 3 (3=path)
	}
	
	
	//Printing the found path
	cout<<"\n\n\tafter solving\n\n";
	Print_maze(height, width, maze); //Printing the maze with the path found
	
	//Getting solved maze into a txt named Solved maze
	array_to_txt(height, width, maze);  //Sending the solved maze to a text file 
	 



	return 0;
}
