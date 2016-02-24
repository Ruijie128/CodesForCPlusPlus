#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// written by Rachel

void ReverseString(char *p, int from, int to)
{
	while(from<to)
	{
		char temp = p[from];
		p[from] = p[to];
		p[to] = temp;
		from ++;
		to --;
	}
}

void Change(char *p, int length, int m)
{
	m %= length;
	ReverseString(p, 0, m-1);
	ReverseString(p, m, length -1);
	ReverseString(p, 0, length-1);
}

void ReverseSentence(char *p, int length)
{
	int mark = 0;
	for (int i =0; i<length;i++)
	{
		if (p[i] == ' ')
		{
			ReverseString(p, mark, i-1);
			mark =i+1;
		}
	}
	ReverseString(p, mark, length-1);
	ReverseString(p, 0, length-1);
}

int main(void)
{
	char str[] = "abcdefg";
	Change(str,  sizeof(str)-1,2);
	cout<<str<<endl; // expecting cdefgab

	char str2[] = "I am Rachel.";
	ReverseSentence(str2, sizeof(str2)-1);
	cout<<str2<<endl; // expecting "Rachel. am I"

	system("pause");
	return 0;
}
