#include "maze.h"

#include <iostream>
using namespace std;

MazeMap::MazeMap()
{

}

void MazeMap::setWall(char wall)
{
	this->m_charWall = wall;
}

char MazeMap::getWall()
{
	return m_charWall;
}

void MazeMap::setRoad(char road)
{
	m_charRoad = road;
}

char MazeMap::getRoad()
{
	return m_charRoad;
}

void MazeMap::setMap(int *p, int row,int column)
{
	m_pMazeMap = p;
	m_iRows = row;
	m_iColumn = column;
}

void MazeMap::drawMaze()
{
	for(int i=0;i<m_iRows;i++)
	{
		for(int j = 0; j<m_iColumn;j++)
		{
			if(m_pMazeMap[i*m_iColumn +j] == WALL)
			{
				cout<<getWall();
			}
			else if (m_pMazeMap[i*m_iColumn +j] == ROAD)
			{
				cout<<getRoad();
			}
		}
		cout<<endl;
	}
}

void MazeMap::callBack()
{
	cout<<"congratulations!"<<endl;
}

bool MazeMap::check_boundary(  int x, int y) // check if it is a wall on the up side
{
	//the right-hand principle
	bool isBoundary = false;
	if(m_pMazeMap[(x-1)*m_iColumn+y] == WALL)
	{
		isBoundary = true;
	}
	else
	{
		isBoundary = false;
	}
	return isBoundary;
}


MazePerson::MazePerson()
{

}

void MazePerson::setCharPerson(char person)
{
	m_charPerson = person;
}

char MazePerson::getPerson()
{
	return m_charPerson;
}

void MazePerson::setFace(string face)
{
	m_strFace = face;
}

string MazePerson::getFace()
{
	return m_strFace;
}

void MazePerson::setPosition(int x, int y)
{
	m_coorPosition.X = x;
	m_coorPosition.Y = y;
}

COORD MazePerson::getPosition()
{
	return m_coorPosition;
}

COORD MazePerson::getPrePosition()
{
	return m_coorPrePosition;
}

void MazePerson::setSpeed(int speed)
{
	m_iSpeed = speed;
}

int MazePerson::getSpeed()
{
	return m_iSpeed;
}

COORD MazePerson::goForward(int x, int y )
{
	COORD nextPosition  ;
	if (m_strFace == UP)
	{
		nextPosition.X = x-1;
		nextPosition.Y = y;
	}
	else if (m_strFace == DOWN)
	{
		nextPosition.X = x+1;
		nextPosition.Y = y;
	}

	return nextPosition;
}

COORD MazePerson::turn(int x, int y)
{
	COORD nextPosition  ;
	if (m_strFace == LEFT)
	{
		nextPosition.X = x;
		nextPosition.Y = y-1;
	}
	else if (m_strFace == RIGHT)
	{
		nextPosition.X = x ;
		nextPosition.Y = y+1;
	}
	return nextPosition;
}

void MazePerson::gotoXY(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	HANDLE handl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handl,cd);
}

void MazePerson::start()
{
	COORD startPosition = m_coorPosition;

}