#include "ScoreManager.h"
#include <iostream>
#include <iostream>

void Print(List<int> &list) {
	std::cout << "list : ";

	for (auto &i : list) {
		std::cout << i << ", ";
	}

	std::cout << std::endl;
}

int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	List<int> list;
	list.Insert(list.end(), 3);
	list.Insert(list.end(), 1);
	list.Insert(list.end(), 2);
	list.Insert(list.end(), 5);
	list.Insert(list.end(), 4);


	Print(list);
	list.Sort(list.begin(), list.end(),  [](int &a, int &b) { return a <= b; });
	Print(list);


	return 0;
	ScoreManager scoreManager;

	scoreManager.Load("asset/Scores.txt");

	scoreManager.Display();

	scoreManager.Clear();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
