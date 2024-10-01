/*--------------------------------------------------
	Name : 01 list課題
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_



/*--- include ---*/

#include <string>
#include "List.h"


/*--- struct ---*/

/// <summary>
/// スコア情報
/// </summary>
struct ScoreInfo {
	int score = 0;			// スコア
	std::string playerName;	// プレイヤー名
};



/// <summary>
/// スコアマネージャクラス
/// </summary>
class ScoreManager {
private:
	/*--- メンバー変数 ---*/

	List<ScoreInfo> scores;



public:
	/*--- メンバー関数 ---*/

	/// <summary>
	/// txtファイルの読み込み
	/// </summary>
	/// <param name="filePath"></param>
	void Load(std::string filePath);

	/// <summary>
	/// 表示
	/// </summary>
	/// <param name=""></param>
	void Display(void);

	/// <summary>
	/// スコア情報の削除
	/// </summary>
	/// <param name=""></param>
	void Clear(void);
};

#endif
