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
template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
class Dictionary {
public:
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

	std::vector<List<Pair>> bucket = std::vector<List<Pair>>(BUCKET_SIZE);
	unsigned int count = 0;	// �S�Ẵ��X�g���̗v�f��



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
	/// <param name="outValue">�L�[�ɑΉ�����l��Ԃ�</param>
	/// <returns>
	/// true:��������
	/// false:�������s
	/// </returns>
	bool Find(const K &key, V &outValue) const;

	/// <summary>
	/// �폜
	/// </summary>
	/// <param name="key">�폜����L�[</param>
	/// <returns>
	/// true:�폜����
	/// false:�폜���s
	/// </returns>
	bool Remove(const K &key);

	/// <summary>
	/// �n�b�V���l�̌v�Z
	/// </summary>
	/// <param name="key">�L�[</param>
	/// <returns>�n�b�V���̒l</returns>
	unsigned int CalcHash(const K &key) const;



public:
	/*--- �A�N�Z�T�֐� ---*/

	/// <summary>
	/// �v�f�����擾
	/// </summary>
	/// <returns>�v�f��</returns>
	unsigned int GetCount(void) const;
};

#include "Dictionary.inl"

#endif
