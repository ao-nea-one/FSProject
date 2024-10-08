#pragma once
#ifndef _SCORE_INFO_H_
#define _SCORE_INFO_H_

/*--- include ---*/
#include <string>



/*--- struct ---*/

/// <summary>
/// スコア情報
/// </summary>
struct ScoreInfo {
	int score = 0;			// スコア
	std::string playerName;	// プレイヤー名



	/*--- メンバー関数 ---*/

	ScoreInfo() = default;
};


#endif
