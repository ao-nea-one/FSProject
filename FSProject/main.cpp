#include "ScoreManager.h"
#include <iostream>


int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<int> tmp;
	tmp.PushBack(0);
	tmp.PushBack(1);
	tmp.PushBack(2);

	std::cout << "Hello World";
	tmp.Clear();

	//ScoreManager scoreManager;

	//scoreManager.Load("asset/Scores.txt");

	//scoreManager.Display();

	//scoreManager.Clear();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
