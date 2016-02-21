#include <string>
#include <windows.h>
#include <iostream>
using namespace std;


const int WALL = 1;
const int ROAD = 0;
const string UP = "UP";
const string DOWN = "DOWN";
const string RIGHT = "RIGHT";
const string LEFT = "LEFT";
const int FAST = 2000;
const int SLOW = 5000;

class MazeMap
{
public:
	MazeMap();
	void setWall(char wall);
	char getWall();
	void setRoad(char road);
	char getRoad();
	void setMap(int *p, int row,int column);
	void drawMaze();
	void callBack();
	bool check_boundary( int x, int y);
private:
	char m_charWall;
	char m_charRoad;
	int *m_pMazeMap;
	int m_iRows;
	int m_iColumn;
};

class MazePerson
{
public:
	MazePerson();
	void setCharPerson(char person);
	char getPerson();
	void setFace(string face);
	string getFace();
	void setPosition(int x, int y);
	COORD getPosition();
	//	void setPrePosition(int prePosition);
	COORD getPrePosition();
	void setSpeed(int speed);
	int getSpeed();
	COORD goForward(int x, int y );
	COORD turn(int x, int y);
	void start( );
	void gotoXY(int x, int y);
private:
	char m_charPerson;
	string m_strFace;
	COORD m_coorPosition;
	COORD m_coorPrePosition;
	int m_iSpeed;
};

