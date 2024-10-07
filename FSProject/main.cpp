#include "ScoreManager.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		ScoreManager scoreManager;

		scoreManager.Load("asset/Scores.txt");

		scoreManager.Display();

		scoreManager.Clear();
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
