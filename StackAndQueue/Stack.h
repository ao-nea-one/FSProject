/*--------------------------------------------------
	Name : Stack
	Date : 2024/10/04
--------------------------------------------------*/

#pragma once
#ifndef _STACK_H_
#define _STACK_H_

/*--- include ---*/
#include "../FSProject/List.h"



/// <summary>
/// Stack�N���X
/// </summary>
template<class T>
class Stack {
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
		return list.Insert(list.end(), value);
	}

	/// <summary>
	/// ��������v�f�����o��
	/// </summary>
	/// <param name="pDst">�����̒l��Ԃ��|�C���^</param>
	/// <returns>
	/// true:�|�b�v����
	/// false:�|�b�v���s
	/// </returns>
	bool Pop(T *pDst) {
		// �v�f�������Ȃ��Ȃ�
		if (list.GetCount() == 0) return false;

		// �����̒l���擾
		if (pDst) *pDst = list.back();

		// �����̃m�[�h���폜
		return list.Remove(--list.end());
	}

	/// <summary>
	/// �擪�̒l���擾
	/// </summary>
	/// <returns>
	/// �擪�̒l
	/// </returns>
	T &front(void) {
		return list.front();
	}

	/// <summary>
	/// �����̒l���擾
	/// </summary>
	/// <returns>
	/// �����̒l
	/// </returns>
	T &back(void) {
		return list.back();
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
