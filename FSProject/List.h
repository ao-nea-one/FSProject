/*--------------------------------------------------
	Name : List
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _LIST_H_
#define _LIST_H_



/// <summary>
/// ���X�g�N���X
/// </summary>
template<class T>
class List {
public:
	/*--- �N���X ---*/

	/// <summary>
	/// �m�[�h�N���X
	/// </summary>
	class Node {
	private:
		/*--- �����o�[�ϐ� ---*/

		T value;				// �l
		Node *pNext = nullptr;	// ���̃m�[�h
		Node *pPrev = nullptr;	// �O�̃m�[�h

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		Node() = default;
		Node(const T &value) : value(value) { }



	public:
		/*--- �����o�[�֐� ---*/

		/// <summary>
		/// next�Ɍq����
		/// </summary>
		/// <param name="pNode"></param>
		/// <returns></returns>
		T *LinkNext(Node *pNode) {
			// null�`�F�b�N
			if (pNode == nullptr) return nullptr;

			pNode->pNext = this->pNext;
			this->pNext = pNode;
			pNode->pPrev = this;
			if (pNode->pNext) pNode->pNext->pPrev = pNode;
		}

		/// <summary>
		/// previous�Ɍq����
		/// </summary>
		/// <param name="pNode"></param>
		/// <returns></returns>
		T *LinkPrevious(Node *pNode) {
			// null�`�F�b�N
			if (pNode == nullptr) return nullptr;

			pNode->pPrev = this->pPrev;
			this->pPrev = pNode;
			pNode->pNext = this;
			if (pNode->pPrev) pNode->pPrev->pNext = pNode;
		}

		/// <summary>
		/// ����
		/// </summary>
		void Leave() {
			if (pNext) pNext->pPrev = pPrev;
			if (pPrev) pPrev->pNext = pNext;
			pNext = pPrev = nullptr;
		}



	public:
		/*--- �A�N�Z�T�֐� ---*/

		/// <summary>
		/// �l���擾
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		T &Get(void) { return value; }
	};

	/// <summary>
	/// �C�e���[�^�N���X
	/// </summary>
	class Iterator {
	private:
		/*--- �����o�[�ϐ� ---*/

		Node *pNode = nullptr;	// ���݂̃m�[�h

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		Iterator() = default;

	private:

		Iterator(Node *pNode) : pNode(pNode) { }



	private:
		/*--- �����o�[�֐� ---*/

		Node *GetNode(void) { return pNode; }



	public:
		/*--- �I�y���[�^ ---*/

		Iterator operator++() { return Iterator(pNode = pNode->pNext); }
		Iterator operator--() { return Iterator(pNode = pNode->pPrev); }
		Iterator operator++(int) { return Iterator(pNode = pNode->pNext); }
		Iterator operator--(int) { return Iterator(pNode = pNode->pPrev); }
		bool operator==(Iterator &iter) { return pNode == iter.pNode; }
		bool operator!=(Iterator &iter) { return pNode != iter.pNode; }
		T &operator*() { return pNode->Get(); }
		T *operator&() { return &pNode->Get(); }
		T const *operator->() { return pNode; }
	};



private:
	/*--- �����o�[�ϐ� ---*/

	Node *pHead = nullptr;	// �擪�m�[�h
	Node *pTail = nullptr;	// �����m�[�h
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
	/// �擪�ɒǉ�����
	/// </summary>
	/// <param name="value"></param>
	void PushFront(T value) {
		Node *pNode = new Node(value);

		// �ǉ�����
		if (pHead) {
			pHead->LinkPrevious(pNode);
			pHead = pNode;
		}
		else {
			pHead = pTail = pNode;
		}


		count++;
	}

	/// <summary>
	/// �����ɒǉ�����
	/// </summary>
	/// <param name="value"></param>
	void PushBack(T value) {
		Node *pNode = new Node(value);

		// �ǉ�����
		if (pTail) {
			pTail->LinkNext(pNode);
			pTail = pNode;
		}
		else {
			pHead = pTail = pNode;
		}


		count++;
	}

	/// <summary>
	/// �擪���폜����
	/// </summary>
	void PopFront(void) {
		if (pHead) {
			Node *pNext = pHead->pNext;

			// �폜����
			pHead->Leave();
			delete pHead;
			pHead = pNext;


			count--;

			if (count == 0) {
				pHead = pTail = nullptr;
			}
		}
	}

	/// <summary>
	/// �������폜����
	/// </summary>
	void PopBack(void) {
		if (pTail) {
			Node *pPrev = pTail->pPrev;

			// �폜����
			pTail->Leave();
			delete pTail;
			pTail = pPrev;


			count--;

			if (count == 0) {
				pHead = pTail = nullptr;
			}
		}
	}

	void Clear(void) {
		Node *pTmpNode;

		// �m�[�h��S�č폜
		while (pHead) {
			pTmpNode = pHead;
			pHead = pHead->pNext;

			delete pTmpNode;
		}

		// ���Z�b�g
		pHead = pTail = nullptr;
		count = 0;
	}

	Iterator begin(void) {
		return Iterator(pHead);
	}

	Iterator end(void) {
		return nullptr;
	}
};


#endif
