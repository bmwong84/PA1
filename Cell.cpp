//Bryant Wong PA1

#include "GameOfLife.h"
using namespace csci2312;

Cell::~Cell()
{

}

Cell::Cell() : state(false)		//sets all to false to start
{

}


//Cell::Cell()
//{
//}


Cell::Cell(bool state)		//sets the state of the cell to whatever is passed
{
	setState(state);
}

bool Cell::getState() const		//returns the state of the cell (dead or alive)
{
	return state;
}

void Cell::setState(bool newState)	//sets the face to whatever is passed false = dead, true = alive
{
	if (newState == false)
	{
		face = dead;
	}
	else if (newState == true)
	{
		face = alive;
	}
	state = newState;
	//sets dead or alive given newState true or false
}

char Cell::getFace() const	//returns + or o depending on status of the cell
{
	return face;
}




