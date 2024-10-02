/*--------------------------------------------------
	Name : List
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*--- include ---*/



/// <summary>
/// ���X�g�N���X
/// </summary>
template<class T>
class List {
private:
	/*--- �C���i�[�N���X ---*/

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

public:

	/// <summary>
	/// �R���X�g�C�e���[�^�N���X
	/// </summary>
	class ConstIterator {
	private:
		/*--- �����o�[�ϐ� ---*/

		Node *pNode = nullptr;	// ���݂̃m�[�h

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		ConstIterator() = default;
		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode) { }

	protected:

		ConstIterator(Node *pNode) : pNode(pNode) { }



	protected:
		/*--- �����o�[�֐� ---*/

		Node *GetNode(void) { return pNode; }



	public:
		/*--- �I�y���[�^ ---*/

		ConstIterator operator++() { return ConstIterator(pNode = pNode->pNext); }
		ConstIterator operator--() { return ConstIterator(pNode = pNode->pPrev); }
		bool operator==(ConstIterator &iter) { return pNode == iter.pNode; }
		bool operator!=(ConstIterator &iter) { return pNode != iter.pNode; }
		ConstIterator operator=(ConstIterator &iter) { return ConstIterator(pNode = iter.pNode); }
		T *const  operator&() { return &pNode->Get(); }
		T &operator* () { return pNode->Get(); }
		T const *operator->() { return pNode; }
	};

	/// <summary>
	/// �C�e���[�^�N���X
	/// </summary>
	class Iterator : public ConstIterator {
	private:

		friend List;

	public:
		/*--- �R���X�g���N�^ ---*/

		Iterator() = default;
		Iterator(const Iterator &iter) : ConstIterator(iter.pNode) { }

	protected:

		Iterator(Node *pNode) : ConstIterator(pNode) { }



	protected:
		/*--- �����o�[�֐� ---*/

		Node *GetNode(void) { return pNode; }



	public:
		/*--- �I�y���[�^ ---*/

		T *operator&() { return &ConstIterator::GetNode()->Get(); }
		T &operator*() { return ConstIterator::GetNode()->Get(); }
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
	/// �擪�ɒǉ�����
	/// </summary>
	/// <param name="value"></param>
	void PushFront(const T &value) {
		Node *pNode = new Node(value);

		// �ǉ�����
			pHead->LinkPrevious(pNode);
			pHead = pNode;


		count++;
	}

	/// <summary>
	/// �����ɒǉ�����
	/// </summary>
	/// <param name="value"></param>
	void PushBack(const T &value) {
		Node *pNode = new Node(value);

		// �ǉ�����
		if (pHead != &tail) {
			tail.LinkPrevious(pNode);
		}
		else {
			tail.LinkPrevious(pNode);
			pHead = pNode;
		}


		count++;
	}

	/// <summary>
	/// �擪���폜����
	/// </summary>
	void PopFront(void) {
		if (pHead != &tail) {
			Node *pNext = pHead->pNext;

			// �폜����
			pHead->Leave();
			delete pHead;
			pHead = pNext;


			count--;
		}
	}

	/// <summary>
	/// �������폜����
	/// </summary>
	void PopBack(void) {
		if (pHead != &tail) {
			Node *pPrev = tail.pPrev->pPrev;

			// �폜����
			tail.pPrev->Leave();
			delete tail.pPrev;
			tail.pPrev = pPrev;


			count--;
		}
	}



	/// <summary>
	/// �}������
	/// </summary>
	void Insert(Iterator &iter, const T&value) {
		Node *pNode = new Node(value);

		// �ǉ�����
		if (iter.GetNode()) {
			iter.GetNode()->LinkNext(pNode);

			count++;
		}
	}

	/// <summary>
	/// �폜����
	/// </summary>
	void Remove(Iterator &iter) {
		Node *pNode = iter.GetNode();

		// �폜����
		if (pNode) {
			// �擪���폜�����Ȃ�X�V
			if (pNode == pHead) {
				pHead = pNode->pNext;
			}

			pNode->Leave();
			delete pNode;

			count--;
		}
	}

	/// <summary>
	/// �S�č폜
	/// </summary>
	/// <param name=""></param>
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
		return Iterator(tail);
	}

	ConstIterator front(void) {
		return ConstIterator(pHead);
	}

	ConstIterator back(void) {
		return ConstIterator(pTail);
	}



public:
	/*--- �A�N�Z�T�֐� ---*/

	unsigned int GetCount(void) { return count; }
};


#endif
