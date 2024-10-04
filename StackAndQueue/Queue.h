/*--------------------------------------------------
	Name : Queue
	Date : 2024/10/04
--------------------------------------------------*/

#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

/*--- include ---*/
#include "../FSProject/List.h"



/// <summary>
/// Queue�N���X
/// </summary>
template<class T>
class Queue {
private:
	/*--- �����o�[�ϐ� ---*/

	List<T> list;		// ���X�g



public:
	/*--- �����o�[�֐� ---*/

	/// <summary>
	/// �����ɗv�f��ǉ�
	/// </summary>
	/// <param name="value">�v�b�V������l</param>
	/// <returns>
	/// true:�v�b�V������
	/// false:�v�b�V�����s
	/// </returns>
	bool Push(const T &value) {
		// �����ɑ}��
		return list.Insert(list.end(), value)
	}

	/// <summary>
	/// �擪����v�f�����o��
	/// </summary>
	/// <returns>
	/// �����̒l
	/// </returns>
	T Pop(void) {
		// �����̒l���擾
		T result = list.front();

		// �����̃m�[�h���폜
		list.Remove(--list.end());

		return result;
	}



public:
	/*--- �A�N�Z�T�֐� ---*/

	/// <summary>
	/// �v�f�����擾
	/// </summary>
	/// <returns>�v�f��</returns>
	unsigned int GetCount(void) const {
		return list.GetCount();
	}
};

#endif
