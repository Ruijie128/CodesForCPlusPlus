#include<iostream>
#include <stdlib.h>
#include "maze.h"
using namespace std;

int main(void)
{

	int map[10][10] ={
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL,WALL},
		{WALL,WALL,WALL,WALL,WALL,WALL,ROAD,ROAD,WALL,WALL},
		{WALL,WALL,WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,WALL},
		{WALL,WALL,WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL},
		{WALL,WALL,WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,WALL,WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,WALL,WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,ROAD,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
	};
	MazeMap maze1;
	maze1.setWall('#');
	maze1.setRoad(' ');
	maze1.setMap(&map[0][0], 10, 10);
	maze1.drawMaze();

	MazePerson mazer;
	mazer.setPosition(9,1);
	mazer.setSpeed(FAST);
	mazer.setCharPerson('T');

	COORD startPosition = mazer.getPosition();
	COORD nextPosition = startPosition;
	mazer.gotoXY(nextPosition.Y, nextPosition.X);
	while (nextPosition.X!=1 && map[nextPosition.X][nextPosition.Y] == ROAD)
	{
		while ( !maze1.check_boundary(nextPosition.X, nextPosition.Y))
		{
			mazer.setFace(UP);
			nextPosition = mazer.goForward(nextPosition.X, nextPosition.Y);		
			mazer.gotoXY(nextPosition.Y, nextPosition.X);
			Sleep(mazer.getSpeed());
		}
		mazer.setFace(RIGHT);
		nextPosition = mazer.turn(nextPosition.X, nextPosition.Y);
		mazer.gotoXY(nextPosition.Y, nextPosition.X);
		Sleep(mazer.getSpeed());
	}





	mazer.gotoXY(1, 20);



	system("pause");
	return 0;
}