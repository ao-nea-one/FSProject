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

		T *pValue = nullptr;
		Node *pNext = this;		// ���̃m�[�h
		Node *pPrev = this;		// �O�̃m�[�h



		/*--- �R���X�g���N�^ ---*/

		Node() = default;
		Node(T* pValue) : pValue(pValue) { }
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
		Node *GetNode(void) const { return pNode; }



	public:
		/*--- �I�y���[�^ ---*/

		ConstIterator operator++() {
			assert(pNode);
			assert(pNode != &pParent->dummy);

			pNode = pNode->pNext;
			return *this;
		}

		ConstIterator operator--() {
			assert(pNode);
			assert(pNode->pPrev != &pParent->dummy);

			pNode = pNode->pPrev;
			return *this;
		}

		ConstIterator operator++(int) {
			assert(pNode);
			assert(pNode != &pParent->dummy);

			pNode = pNode->pNext;
			return ConstIterator(pNode->pPrev, pParent);
		}

		ConstIterator operator--(int) {
			assert(pNode);
			assert(pNode->pPrev != &pParent->dummy);

			pNode = pNode->pPrev;
			return ConstIterator(pNode->pNext, pParent);
		}

		T const &operator* () const {
			assert(pNode);
			return *pNode->pValue;
		}

		ConstIterator operator=(ConstIterator iter) {
			if (pParent != iter.pParent) return *this;

			pNode = iter.pNode;
			return *this;
		}

		bool operator==(ConstIterator &iter) const {
			return pNode == iter.pNode;
		}

		bool operator!=(ConstIterator &iter) const {
			return pNode != iter.pNode;
		}
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

		T &operator*() {
			assert(ConstIterator::pNode);
			assert(ConstIterator::pNode->pValue);
			return *ConstIterator::pNode->pValue;
		}
	};



private:
	/*--- �����o�[�ϐ� ---*/

	Node dummy;				// �_�~�[�m�[�h
	unsigned int count = 0;	// �v�f��



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
	bool Insert(ConstIterator iter, const T&value) {
		// null�`�F�b�N
		if (iter.GetNode() == nullptr) return false;
		// ���֌W�̃��X�g
		if (iter.pParent != this) return false;

		Node *pNode = new Node(new T(value));


		// �ǉ�����
		Link(iter.GetNode(), pNode);


		count++;

		return true;
	}

	/// <summary>
	/// �폜����
	/// </summary>
	/// <param name="iter">�폜����C�e���[�^</param>
	/// <returns>
	/// true:�폜����
	/// false:�폜���s
	/// </returns>
	bool Remove(ConstIterator iter) {
		// null�`�F�b�N
		if (iter.GetNode() == nullptr) return false;
		// �_�~�[�`�F�b�N
		if (iter.GetNode() == &dummy) return false;
		// ���֌W�̃��X�g
		if (iter.pParent != this) return false;



		Node *pNode = iter.GetNode();

		// �폜����
		if (pNode) {
			Leave(pNode);
			delete pNode->pValue;
			delete pNode;

			count--;
			return true;
		}
	}

	/// <summary>
	/// �S�č폜
	/// </summary>
	void Clear(void) {
		if (count == 0) return;

		Node *pNode = dummy.pNext;
		Node *pTmp = nullptr;

		// �m�[�h��S�č폜
		while (pNode != &dummy) {
			pTmp = pNode;
			pNode = pNode->pNext;

			delete pTmp->pValue;
			delete pTmp;
		}

		// ���Z�b�g
		count = 0;
	}

	/// <summary>
	/// �擪�̃C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃C�e���[�^</returns>
	Iterator begin(void) {
		return Iterator(dummy.pNext, this);
	}

	/// <summary>
	/// �����̃C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃C�e���[�^</returns>
	Iterator end(void) {
		return Iterator(&dummy, this);
	}

	/// <summary>
	/// �擪�̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃R���X�g�C�e���[�^</returns>
	ConstIterator cbegin(void) const {
		return ConstIterator(dummy.pNext, this);
	}

	/// <summary>
	/// �����̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃R���X�g�C�e���[�^</returns>
	ConstIterator cend(void) const {
		return ConstIterator(const_cast<Node*>(&dummy), this);
	}

	/// <summary>
	/// �擪�̒l���擾
	/// </summary>
	/// <returns>�擪�̒l</returns>
	T &front(void) {
		assert(dummy.pNext->pValue);
		return *dummy.pPrev->pValue;
	}

	/// <summary>
	/// �����̒l���擾
	/// </summary>
	/// <returns>�����̒l</returns>
	T &back(void) {
		assert(dummy.pPrev->pValue);
		return *dummy.pPrev->pValue;
	}

private:
	
	/// <summary>
	/// �q����
	/// </summary>
	/// <param name="pThis">�ꏊ���w�肷��m�[�h�|�C���^</param>
	/// <param name="pOther">�V�����q�������m�[�h�|�C���^</param>
	void Link(Node *pThis, Node *pOther) {
		if (pThis == pOther) return;

		// �q���鏈��
		pOther->pPrev = pThis->pPrev;
		pThis->pPrev = pOther;
		pOther->pNext = pThis;
		if (pOther->pPrev) pOther->pPrev->pNext = pOther;
	}
	
	/// <summary>
	/// �q����
	/// </summary>
	/// <param name="thisIter">�ꏊ���w�肷��C�e���[�^</param>
	/// <param name="otherIter">�V�����q�������C�e���[�^</param>
	void Link(Iterator thisIter, Iterator otherIter) {
		Link(thisIter.GetNode(), otherIter.GetNode());
	}

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="pThis">�ڑ���؂�m�[�h�|�C���^</param>
	void Leave(Node *pThis) {
		// �؂藣������
		if (pThis->pNext) pThis->pNext->pPrev = pThis->pPrev;
		if (pThis->pPrev) pThis->pPrev->pNext = pThis->pNext;
		pThis->pNext = pThis->pPrev = nullptr;
	}

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="thisIter">�ڑ���؂�C�e���[�^</param>
	void Leave(Iterator thisIter) {
		Leave(thisIter.GetNode());
	}



public:
	/*--- �A�N�Z�T�֐� ---*/

	/// <summary>
	/// �v�f�����擾
	/// </summary>
	/// <returns>�v�f��</returns>
	unsigned int GetCount(void) { return count; }
};


#endif
