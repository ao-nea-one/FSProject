/*--------------------------------------------------
	Name : 01 list�ۑ�
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
/// �X�R�A���
/// </summary>
struct ScoreInfo {
	int score = 0;			// �X�R�A
	std::string playerName;	// �v���C���[��



	/*--- �����o�[�֐� ---*/

	ScoreInfo() = default;
};



/// <summary>
/// �X�R�A�}�l�[�W���N���X
/// </summary>
class ScoreManager {
private:
	/*--- �����o�[�ϐ� ---*/

	List<ScoreInfo> scores;



public:
	/*--- �����o�[�֐� ---*/

	/// <summary>
	/// txt�t�@�C���̓ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void Load(std::string filePath);

	/// <summary>
	/// �\��
	/// </summary>
	void Display(void);

	/// <summary>
	/// �X�R�A���̍폜
	/// </summary>
	void Clear(void);
};

#endif
