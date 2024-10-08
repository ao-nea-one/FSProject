/*--------------------------------------------------
	Name : 01 list�ۑ�
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_



/*--- include ---*/

#include "ScoreInfo.h"
#include "List.h"



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
