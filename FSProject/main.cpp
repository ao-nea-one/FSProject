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
	int pivot = arr[high];  // �s�{�b�g��z��̍Ō�̗v�f�ɐݒ�
	int i = low - 1;  // i�̓s�{�b�g��菬�����v�f�̍Ō�̈ʒu

	for (int j = low; j < high; j++) {
		// ���݂̗v�f���s�{�b�g�ȉ��̏ꍇ
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);  // �s�{�b�g��菬�����v�f��O���Ɉړ�
		}
	}
	swap(arr[i + 1], arr[high]);  // �s�{�b�g�𐳂����ʒu�Ɉړ�
	return i + 1;  // �s�{�b�g�̈ʒu��Ԃ�
}

// �N�C�b�N�\�[�g�̍ċA�֐�
void quickSort(vector<int> &arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);  // �����_���擾

		// �����_����ɍċA�I�ɍ��E�̕������\�[�g
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
