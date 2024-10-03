#include "ScoreManager.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void Print(List<int> &list) {
	std::cout << "list : ";

	for (auto &i : list) {
		std::cout << i << ", ";
	}

	std::cout << std::endl;
}


int partition(vector<int> &arr, int low, int high) {
	int pivot = arr[high];  // ピボットを配列の最後の要素に設定
	int i = low - 1;  // iはピボットより小さい要素の最後の位置

	for (int j = low; j < high; j++) {
		// 現在の要素がピボット以下の場合
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);  // ピボットより小さい要素を前方に移動
		}
	}
	swap(arr[i + 1], arr[high]);  // ピボットを正しい位置に移動
	return i + 1;  // ピボットの位置を返す
}

// クイックソートの再帰関数
void quickSort(vector<int> &arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);  // 分割点を取得

		// 分割点を基に再帰的に左右の部分をソート
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	List<int> list;
	list.Insert(list.end(), 5);
	list.Insert(list.end(), 2);
	list.Insert(list.end(), 7);
	list.Insert(list.end(), 3);
	list.Insert(list.end(), 6);


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
