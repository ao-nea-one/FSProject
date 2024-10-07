/*--------------------------------------------------
	Name : Dictionary
	Date : 2024/10/07
--------------------------------------------------*/

#pragma once
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

/*--- include ---*/
#include "../FSProject/List.h"
#include <cassert>
#include <vector>



/// <summary>
/// ���X�g�N���X
/// </summary>
template<class K, class V>
class Dictionary {
private:
	/*--- �C���i�[�N���X ---*/

	struct Pair {
		K key = K();
		V value = V();
	};



private:
	/*--- �����o�[�ϐ� ---*/

	unsigned int BUCKET_SIZE = 10;
	std::vector<List<Pair>> list = std::vector<List<Pair>>(BUCKET_SIZE);

};

#endif
