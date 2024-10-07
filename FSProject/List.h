/*--------------------------------------------------
	Name : List
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*--- include ---*/
#include <cassert>
#include <functional>
#include <iostream>



/// <summary>
/// ���X�g�N���X
/// </summary>
template<class T>
class List {
private:
	/*--- �C���i�[�N���X ---*/

	/// <summary>
	/// �m�[�h�N���X:�C���^�[�t�F�[�X
	/// </summary>
	struct Node {
		/*--- �����o�[�ϐ� ---*/

		T value = T();
		Node *pNext = this;		// ���̃m�[�h
		Node *pPrev = this;		// �O�̃m�[�h



		/*--- �R���X�g���N�^ ---*/

		Node() = default;
		Node(const T &value) : value(value) { }
	};



public:

	/// <summary>
	/// �R���X�g�C�e���[�^�N���X
	/// </summary>
	class ConstIterator {

		friend List;

	protected:
		/*--- �����o�[�ϐ� ---*/

		Node *pNode = nullptr;	// ���݂̃m�[�h
		const List<T> *pParent = nullptr;



	public:
		/*--- �R���X�g���N�^ ---*/

		ConstIterator() = default;

		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode), pParent(iter.pParent) { }

	public:

		ConstIterator(Node *pNode, const List<T> *pParent) : pNode(pNode), pParent(pParent) { }

		ConstIterator(ConstIterator &&iter) {
			pNode = iter.pNode;
			pParent = iter.pParent;

			iter.pNode = nullptr;
			iter.pParent = nullptr;
		}



	protected:
		/*--- �A�N�Z�T�֐� ---*/

		/// <summary>
		/// �m�[�h���擾
		/// </summary>
		/// <returns>�m�[�h�|�C���^</returns>
		Node *GetNode(void) { return pNode; }



	public:
		/*--- �I�y���[�^ ---*/

		ConstIterator &operator++();

		ConstIterator &operator--();

		ConstIterator operator++(int);

		ConstIterator operator--(int);

		T const &operator* () const;

		ConstIterator operator=(const ConstIterator &iter);

		bool operator==(ConstIterator &iter) const;

		bool operator!=(ConstIterator &iter) const;
	};

	/// <summary>
	/// �C�e���[�^�N���X
	/// </summary>
	class Iterator : public ConstIterator {

		friend List;

	public:
		/*--- �R���X�g���N�^ ---*/

		Iterator() = default;

		Iterator(const Iterator &iter) : ConstIterator(iter.pNode, iter.pParent) { }

	protected:

		Iterator(Node *pNode, List<T> *pParent) : ConstIterator(pNode, pParent) { }



	public:
		/*--- �I�y���[�^ ---*/

		Iterator &operator++();

		Iterator &operator--();

		Iterator operator++(int);

		Iterator operator--(int);

		T &operator*();

		bool operator==(Iterator &iter);

		bool operator!=(Iterator &iter);
	};



private:
	/*--- �����o�[�ϐ� ---*/

	Node dummy;				// �_�~�[�m�[�h
	unsigned int count = 0;	// �v�f��



public:
	/*--- �R���X�g���N�^ ---*/

	List() = default;
	


public:
	/*--- �f�X�g���N�^ ---*/

	~List() { Clear(); }



public:
	/*--- �����o�[�֐� ---*/

	/// <summary>
	/// �}��
	/// </summary>
	/// <param name="iter">�}����̃C�e���[�^</param>
	/// <param name="value">�}������l</param>
	/// <returns>
	/// true:�}������
	/// false:�}�����s
	/// </returns>
	bool Insert(ConstIterator iter, const T &value);

	/// <summary>
	/// �폜����
	/// </summary>
	/// <param name="iter">�폜����C�e���[�^</param>
	/// <returns>
	/// true:�폜����
	/// false:�폜���s
	/// </returns>
	bool Remove(ConstIterator iter);

	/// <summary>
	/// �\�[�g
	/// </summary>
	/// <param name="func">�\�[�g���̊֐�</param>
	void Sort(Iterator first, Iterator last, std::function<bool(T &, T &)> func);


	/// <summary>
	/// �S�č폜
	/// </summary>
	void Clear(void);

private:
	
	/// <summary>
	/// �q����
	/// </summary>
	/// <param name="pThis">�ꏊ���w�肷��m�[�h�|�C���^</param>
	/// <param name="pOther">�V�����q�������m�[�h�|�C���^</param>
	void Link(Node *pThis, Node *pOther);
	
	/// <summary>
	/// �q����
	/// </summary>
	/// <param name="thisIter">�ꏊ���w�肷��C�e���[�^</param>
	/// <param name="otherIter">�V�����q�������C�e���[�^</param>
	void Link(Iterator thisIter, Iterator otherIter);

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="pThis">�ڑ���؂�m�[�h�|�C���^</param>
	void Leave(Node *pThis);

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="thisIter">�ڑ���؂�C�e���[�^</param>
	void Leave(Iterator thisIter);



public:
	/*--- �A�N�Z�T�֐� ---*/

	/// <summary>
	/// �擪�̃C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃C�e���[�^</returns>
	Iterator begin(void);

	/// <summary>
	/// �����̃C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃C�e���[�^</returns>
	Iterator end(void);

	/// <summary>
	/// �擪�̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃C�e���[�^</returns>
	ConstIterator begin(void) const;

	/// <summary>
	/// �����̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃C�e���[�^</returns>
	ConstIterator end(void) const;

	/// <summary>
	/// �擪�̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃R���X�g�C�e���[�^</returns>
	ConstIterator cbegin(void) const;

	/// <summary>
	/// �����̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃R���X�g�C�e���[�^</returns>
	ConstIterator cend(void) const;

	/// <summary>
	/// �擪�̒l���擾
	/// </summary>
	/// <returns>�擪�̒l</returns>
	T &front(void);

	/// <summary>
	/// �����̒l���擾
	/// </summary>
	/// <returns>�����̒l</returns>
	T &back(void);

	/// <summary>
	/// �v�f�����擾
	/// </summary>
	/// <returns>�v�f��</returns>
	unsigned int GetCount(void) const { return count; }
};


#include "List.inl"

#endif
