#include "ScoreManager.h"

/*--- include ---*/

#include <iostream>
#include <sstream>
#include <crtdbg.h>
#include <fstream>



void ScoreManager::Load(std::string filePath) {
	
	std::ifstream ifs(filePath);

	// é∏îsèàóù
	if (ifs.fail()) {
		std::cerr << "ÉtÉ@ÉCÉãÇ™ë∂ç›ÇµÇ‹ÇπÇÒÇ≈ÇµÇΩ" << std::endl;
		return;
	}



	std::string line;
	std::stringstream sstream;
	ScoreInfo scoreInfo;

	// ì«Ç›çûÇ›
	while (std::getline(ifs, line)) {
		sstream = std::stringstream(line);

		sstream >> scoreInfo.score;
		sstream >> scoreInfo.playerName;

		scores.Insert(scores.end(), scoreInfo);
	}
}





void ScoreManager::Display(void) {
	for (auto &info : scores) {
		std::cout << info.playerName << " : " << info.score << std::endl;
	}
}





void ScoreManager::Clear(void) {
	scores.Clear();
}
