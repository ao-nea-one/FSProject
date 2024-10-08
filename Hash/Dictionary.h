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
#include <functional>



/// <summary>
/// ���X�g�N���X
/// </summary>
template<class K, class V>
class Dictionary {
private:
	/*--- �C���i�[�N���X ---*/

	struct Pair {
		/*--- �����o�[�ϐ� ---*/

		K key = K();
		V value = V();



	public:
		/*--- �R���X�g���N�^ ---*/

		Pair() = default;
		Pair(const K &key, const V &value) : key(key), value(value) { };
	};



private:
	/*--- �����o�[�ϐ� ---*/

	unsigned int BUCKET_SIZE = 10;
	std::vector<List<Pair>> bucket = std::vector<List<Pair>>(BUCKET_SIZE);



public:
	/*--- �����o�[�֐� ---*/

	/// <summary>
	/// �}��
	/// </summary>
	/// <param name="key">�}������L�[</param>
	/// <param name="value">�}������l</param>
	/// <returns>
	/// true:�}������
	/// false:�}�����s
	/// </returns>
	bool Insert(const K &key, const V &value);

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="key">��������L�[</param>
	/// <returns>�L�[�ɑΉ�����l</returns>
	V &Find(const K &key);
};

#include "Dictionary.inl"

#endif
