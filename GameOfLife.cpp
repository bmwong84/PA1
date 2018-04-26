//Bryant Wong PA1 

#include "GameOfLife.h"
using namespace csci2312;

//default constructor
GameOfLife::GameOfLife()
{

}//end default constructor

//sets GameOfLife board size to passed value
GameOfLife::GameOfLife(size_t boardSize)
{

}
//GameOfLife::GameOfLife()
//{
//}



//Member function to seed the board with a predefined matrix, passed data from an opened file
void GameOfLife::seedBoard(std::ifstream& fileName)
{
	std::string incount="0";
	for (int vert = 0; vert < MAX_BOARD + 2; vert++)		//sets all cells to state false in both currentLife board and nextLife board; this loop took the place of the default constructor setting everything to false
	{
		for (int horiz = 0; horiz < MAX_BOARD + 2; horiz++)
		{
			currentLife[vert][horiz].setState(false);
			nextLife[vert][horiz].setState(false);
		}
	}
	std::cout << "Seeding board from file..." << std::endl;		
	int intcount[MAX_BOARD*MAX_BOARD];								//creates an array to hold the input data for each cell in the board
	for (int input = 0; input < MAX_BOARD*MAX_BOARD; input++)
		fileName >> intcount[input];								//adds each input line to the array in order
	int inputseeding=0;
	for (int vert = 1; vert < MAX_BOARD+1; vert++)					//for each cell in visible board
	{
		for (int horiz = 1; horiz < MAX_BOARD+1; horiz++)
		{	
			bool seeding;						
			if (intcount[inputseeding] == 0)						//if the seeding file has a 0
				seeding = false;									//set bool to false
			else if (intcount[inputseeding] == 1)
				seeding = true;
			currentLife[vert][horiz].setState(seeding);				//sets the state of the currentLife at each cell coordinate to the state from the seeding file
			inputseeding++;
		}
	}

}


//seeds the board randomly

void GameOfLife::seedBoard()	
{
	for (int vert = 0; vert < MAX_BOARD + 2; vert++)		//sets all cells to state false in both currentLife board and nextLife board
	{
		for (int horiz = 0; horiz < MAX_BOARD + 2; horiz++)
		{
			currentLife[vert][horiz].setState(false);
			nextLife[vert][horiz].setState(false);
		}
	}
	std::cout << "Seeding initial board randomly" << std::endl;
	for (int vert = 1; vert < MAX_BOARD+1; vert++)					//for each cell
	{
		for (int horiz = 1; horiz < MAX_BOARD+1; horiz++)
		{
			int seed;		
			seed = rand() % 2;			//generates a random 1 or 0
			bool seeding;
			if (seed == 1)				//sets a bool to true or false depending on 1 or 0
				seeding = true;
			else if (seed == 0)
				seeding = false;
			currentLife[vert][horiz].setState(seeding);				//sets current cell to whatever the random number generator says it should be
			std::cout << currentLife[vert][horiz].getFace();		//displays the status of the current board so the user can see the parent board
		}
		std::cout << std::endl;					//at the end of each horizontal line, new line
	}
}

//member function to check the status of neighbors (alive or dead) and returns an int of number of alive neighbors
unsigned int GameOfLife::CheckNeighbors(int vert, int horiz)	
{
	int neighborAlive = 0;
	if (currentLife[vert - 1][horiz - 1].getState())			//checks cell to the upper left of current cell
		neighborAlive++;										//increments if the cell is alive
	if (currentLife[vert - 1][horiz].getState())				//checks cell to the top of current cell
		neighborAlive++;
	if (currentLife[vert - 1][horiz + 1].getState())			//checks cell to the upper right of current cell
		neighborAlive++;
	if (currentLife[vert][horiz - 1].getState())				//etc etc.
		neighborAlive++;
	if (currentLife[vert][horiz + 1].getState())
		neighborAlive++;
	if (currentLife[vert + 1][horiz - 1].getState())
		neighborAlive++;
	if (currentLife[vert + 1][horiz].getState())
		neighborAlive++;
	if (currentLife[vert + 1][horiz + 1].getState())
		neighborAlive++;

	return neighborAlive;										//returns the number of neighboring cells that are alive
}

//carries out the rules of the game of life according to number of live neighbors
bool GameOfLife::executeRules(unsigned int countAlive, int vert, int horiz)
{
	//if itself is alive and less than 2 neighbors are alive, cell dies
	if (currentLife[vert][horiz].getState() && countAlive < 2)
		return false;
	//		state = false
	//	else if (self==alive && (neighborAlive ==2 || neighborAlive==3))
	else if (currentLife[vert][horiz].getState() && (countAlive == 2 || countAlive == 3))
		return true;
	//		state = true
	//	else if (self == alive && neighborAlive>3)
	else if (currentLife[vert][horiz].getState() && countAlive > 3)
		return false;
	//		state = false
	//	else if (self== dead && neighborAlive ==3)
	else if (currentLife[vert][horiz].getState() == false && countAlive == 3)
		return true;
	//		state =true
	else
		return false;

}


//runs the game of life once and asks each generation whether the user wants to continue to the next generation
void GameOfLife::run()		
{
	//runs the simulation with some long loop of << operator
	std::string yn = "y";
	do
	{
		
		for (int vert = 1; vert < MAX_BOARD+1; vert++)					//displays the initial board
		{
			for (int horiz = 1; horiz < MAX_BOARD+1; horiz++)
			{
				std::cout << currentLife[vert][horiz].getFace();
			}
			std::cout << std::endl;							//at the end of each horizontal row, new line
		}
		std::cout << std::endl;
		for (int vert = 1; vert < MAX_BOARD+1; vert++)			//sets the nextLife board 
		{
			for (int horiz = 1; horiz < MAX_BOARD+1; horiz++)
			{
				nextLife[vert][horiz].setState(executeRules(CheckNeighbors(vert, horiz), vert, horiz));	//O_o  set the state of the nextLife at coordinates vert/horiz 
			}																							//to the bool returned by the member function CheckNeighbors at vert/horiz, passing vert horiz
		}
		for (int vert = 1; vert < MAX_BOARD+1; vert++)					//sets currentLife array to nextLife array in preparation for next generation
		{
			for (int horiz = 1; horiz < MAX_BOARD+1; horiz++)
			{
				currentLife[vert][horiz].setState(nextLife[vert][horiz].getState());		
			}
		}
		std::cout << std::endl;
		std::cout << "Would you like to run another iteration (y)?  Or press any other key to return to menu" << std::endl;
		std::cin >> yn;
		std::cout << std::endl;
	}

	while (yn == "y" || yn == "Y");
}

void GameOfLife::run(unsigned int numberOfIterations)				//runs for a passed number of generations
{
	for (unsigned int iter = 0; iter < numberOfIterations; iter++)				//as long as the counter is less than the passed number of generations
	{
		for (int vert = 1; vert < MAX_BOARD + 1; vert++)					//displays the initial board
		{
			for (int horiz = 1; horiz < MAX_BOARD + 1; horiz++)
			{
				std::cout << currentLife[vert][horiz].getFace();
			}
			std::cout << std::endl;							//at the end of each horizontal row, new line
		}
		std::cout << std::endl;
		for (int vert = 1; vert < MAX_BOARD + 1; vert++)			//sets the nextLife board 
		{
			for (int horiz = 1; horiz < MAX_BOARD + 1; horiz++)
			{
				nextLife[vert][horiz].setState(executeRules(CheckNeighbors(vert, horiz), vert, horiz));
			}
		}
		for (int vert = 1; vert < MAX_BOARD + 1; vert++)					//sets currentLife array to nextLife array in preparation for next generation
		{
			for (int horiz = 1; horiz < MAX_BOARD + 1; horiz++)
			{
				currentLife[vert][horiz].setState(nextLife[vert][horiz].getState());
			}
		}
	}
}

//GameOfLife::ostream& operator << (ostream& out, const GameOfLife& board)
//{
//	for (int vert = 1; vert < MAX_BOARD; vert++)
//	{
//		for (int horiz = 1; horiz < MAX_BOARD; horiz++)
//		{
//			std::cout << currentLife[vert][horiz];
//		}
//		std::cout << std::endl;
//	}
//}


