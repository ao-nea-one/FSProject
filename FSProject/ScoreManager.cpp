#include "ScoreManager.h"

/*--- include ---*/

#include <iostream>
#include <sstream>
#include <crtdbg.h>
#include <fstream>



void ScoreManager::Load(std::string filePath) {
	
	std::ifstream ifs(filePath);

	// ���s����
	if (ifs.fail()) {
		std::cerr << "�t�@�C�������݂��܂���ł���" << std::endl;
		return;
	}



	std::string line;
	std::stringstream sstream;
	ScoreInfo scoreInfo;

	// �ǂݍ���
	while (std::getline(ifs, line)) {
		sstream = std::stringstream(line);

		sstream >> scoreInfo.score;
		sstream >> scoreInfo.playerName;

		scores.Insert(scores.end(), scoreInfo);
	}
}





void ScoreManager::Display(void) {

	scores.Sort(scores.begin(), scores.end(), [](ScoreInfo &a, ScoreInfo &b) { return a.score >= b.score; });
	for (auto &info : scores) {
		std::cout << info.playerName << " : " << info.score << std::endl;
	}
}





void ScoreManager::Clear(void) {
	scores.Clear();
}
