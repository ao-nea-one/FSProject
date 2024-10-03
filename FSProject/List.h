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



#define print {\
Iterator e = this->end();\
for (Iterator j = this->begin(); j != e; j++) {\
	if (j == tmpStart || j == tmpEnd) std::cout << "[";\
	std::cout << *j;\
	if (j == tmpStart || j == tmpEnd) std::cout << "]";\
}\
std::cout << std::endl;\
}\



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
		Node *pNext = nullptr;	// ���̃m�[�h
		Node *pPrev = nullptr;	// �O�̃m�[�h



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




	public:
		/*--- �R���X�g���N�^ ---*/

		ConstIterator() = default;
		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode) { }

	protected:

		ConstIterator(Node *pNode) : pNode(pNode) { }



	protected:
		/*--- �A�N�Z�T�֐� ---*/

		/// <summary>
		/// �m�[�h���擾
		/// </summary>
		/// <returns>�m�[�h�|�C���^</returns>
		Node *GetNode(void) { return pNode; }



	public:
		/*--- �I�y���[�^ ---*/

		ConstIterator operator++() {
			assert(pNode);
			assert(pNode->pNext);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pNext);
		}

		ConstIterator operator--() {
			assert(pNode);
			assert(pNode->pPrev);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pPrev);
		}

		ConstIterator operator++(int) {
			assert(pNode);
			assert(pNode->pNext);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pNext);
		}

		ConstIterator operator--(int) {
			assert(pNode);
			assert(pNode->pPrev);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pPrev);
		}

		T const &operator* () {
			assert(pNode);
			return *pNode->pValue;
		}

		ConstIterator operator=(ConstIterator iter) {
			pNode = iter.pNode;
			return *this;
		}

		bool operator==(ConstIterator &iter) {
			return pNode == iter.pNode;
		}

		bool operator!=(ConstIterator &iter) {
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
		Iterator(const Iterator &iter) : ConstIterator(iter.pNode) { }

	protected:

		Iterator(Node *pNode) : ConstIterator(pNode) { }



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

	Node *pHead = nullptr;	// �擪�m�[�h
	Node tail;				// �����m�[�h
	unsigned int count = 0;	// �v�f��



public:
	/*--- �R���X�g���N�^ ---*/

	List() {
		pHead = &tail;
	}



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
		Node *pNode = new Node(new T(value));

		if (iter.GetNode() == nullptr) {
			return false;
		}

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
		Node *pNode = iter.GetNode();

		if (pNode == &tail || pNode == nullptr) {
			return false;
		}
		// �폜����
		else if (pNode) {
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

		Node *pNode;

		// �m�[�h��S�č폜
		while (pHead != &tail) {
			pNode = pHead;
			pHead = pHead->pNext;

			delete pNode->pValue;
			delete pNode;
		}

		// ���Z�b�g
		pHead = &tail;
		count = 0;
	}

	/// <summary>
	/// �擪�̃C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃C�e���[�^</returns>
	Iterator begin(void) {
		return Iterator(pHead);
	}

	/// <summary>
	/// �����̃C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃C�e���[�^</returns>
	Iterator end(void) {
		return Iterator(&tail);
	}

	/// <summary>
	/// �擪�̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�擪�̃R���X�g�C�e���[�^</returns>
	ConstIterator ConstBegin(void) {
		return ConstIterator(pHead);
	}

	/// <summary>
	/// �����̃R���X�g�C�e���[�^���擾
	/// </summary>
	/// <returns>�����̃R���X�g�C�e���[�^</returns>
	ConstIterator ConstEnd(void) {
		return ConstIterator(&tail);
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

		// �擪�|�C���^�̍X�V
		if (pThis == pHead) pHead = pOther;
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
		// �擪�|�C���^�̍X�V
		if (pThis == pHead) pHead = pHead->pNext;


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
