/*--------------------------------------------------
	Name : List
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*--- include ---*/
#include <cassert>



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
	class INode {
	private:
		/*--- �����o�[�ϐ� ---*/

		INode *pNext = nullptr;	// ���̃m�[�h
		INode *pPrev = nullptr;	// �O�̃m�[�h

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		INode() = default;



	public:
		/*--- �����o�[�֐� ---*/

		/// <summary>
		/// next�Ɍq����
		/// </summary>
		/// <param name="pNode"></param>
		/// <returns></returns>
		T *LinkNext(INode *pNode) {
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
		T *LinkPrevious(INode *pNode) {
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

		/// <summary>
		/// �_�~�[�m�[�h���ۂ�
		/// </summary>
		/// <returns>
		/// true:�_�~�[�m�[�h
		/// false:�f�t�H���g�m�[�h
		/// </returns>
		virtual bool IsDummy(void) = 0;

		/// <summary>
		/// �l���擾
		/// </summary>
		/// <returns>�i�[����l�̃|�C���^</returns>
		virtual T *Get(void) = 0;
	};

	/// <summary>
	/// �m�[�h�N���X
	/// </summary>
	class Node : public INode {
	private:
		/*--- �����o�[�ϐ� ---*/

		T value;				// �l

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		Node() = default;
		Node(const T &value) : value(value) { }



	public:
		/*--- �����o�[�֐� ---*/

		/// <summary>
		/// �_�~�[�m�[�h���ۂ�
		/// </summary>
		/// <returns>
		/// true:�_�~�[�m�[�h
		/// false:�f�t�H���g�m�[�h
		/// </returns>
		bool IsDummy(void) override { return false; }



	public:
		/*--- �A�N�Z�T�֐� ---*/

		/// <summary>
		/// �l���擾
		/// </summary>
		/// <returns>�i�[����l�̃|�C���^</returns>
		T *Get(void) override { return &value; }
	};

	/// <summary>
	/// �_�~�[�m�[�h�N���X�i�l��ێ����Ȃ��j
	/// </summary>
	class DummyNode : public INode {
	private:
		/*--- �����o�[�ϐ� ---*/

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		DummyNode() = default;



	public:
		/*--- �����o�[�֐� ---*/

		/// <summary>
		/// �_�~�[�m�[�h���ۂ�
		/// </summary>
		/// <returns>true:�_�~�[�m�[�h�@false:�f�t�H���g�m�[�h</returns>
		bool IsDummy(void) override { return true; }



	public:
		/*--- �A�N�Z�T�֐� ---*/

		/// <summary>
		/// �l���擾
		/// </summary>
		/// <returns>nullptr</returns>
		T *Get(void) override { return nullptr; }
	};

public:

	/// <summary>
	/// �R���X�g�C�e���[�^�N���X
	/// </summary>
	class ConstIterator {
	protected:
		/*--- �����o�[�ϐ� ---*/

		INode *pNode = nullptr;	// ���݂̃m�[�h

		friend List;



	public:
		/*--- �R���X�g���N�^ ---*/

		ConstIterator() = default;
		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode) { }

	protected:

		ConstIterator(INode *pNode) : pNode(pNode) { }



	public:
		/*--- �����o�[�֐� ---*/

		/// <summary>
		/// �_�~�[�m�[�h���ۂ�
		/// </summary>
		/// <returns>
		/// true:�_�~�[�m�[�h
		/// false:nullptr or �f�t�H���g�m�[�h 
		/// </returns>
		bool IsDummy(void) { return pNode ? pNode->IsDummy() : false; }

		/// <summary>
		/// �m�[�h���ێ�����Ă��邩�ۂ�
		/// </summary>
		/// <returns>
		/// true:nullptr
		/// false:�m�[�h�����݂���
		/// </returns>
		bool IsEmpty(void) { return pNode == nullptr; }



	protected:
		/*--- �A�N�Z�T�֐� ---*/

		/// <summary>
		/// �m�[�h���擾
		/// </summary>
		/// <returns>�m�[�h�|�C���^</returns>
		INode *GetNode(void) { return pNode; }

	public:

		/// <summary>
		/// �l���擾����
		/// </summary>
		/// <returns>�m�[�h�Ɋi�[����Ă���l</returns>
		T *Get(void) {
			assert(pNode);
			return pNode->Get();
		}



	public:
		/*--- �I�y���[�^ ---*/

		bool operator==(ConstIterator &iter) {
			return pNode == iter.pNode;
		}

		bool operator!=(ConstIterator &iter) {
			return pNode != iter.pNode;
		}

		T *const *operator&() {
			assert(pNode);
			return &pNode->Get();
		}

		T const &operator* () {
			assert(pNode);
			pNode->Get();
		}

		T const *operator->() {
			assert(pNode);
			return pNode;
		}
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

		Iterator(INode *pNode) : ConstIterator(pNode) { }



	public:
		/*--- �I�y���[�^ ---*/

		Iterator operator++() {
			assert(ConstIterator::pNode);
			assert(ConstIterator::pNode->pNext);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pNext);
		}

		Iterator operator--() {
			assert(ConstIterator::pNode);
			assert(ConstIterator::pNode->pPrev);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pPrev);
		}

		Iterator operator++(int) {
			assert(ConstIterator::pNode);
			assert(ConstIterator::pNode->pNext);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pNext);
		}

		Iterator operator--(int) {
			assert(ConstIterator::pNode);
			assert(ConstIterator::pNode->pPrev);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pPrev);
		}

		T *operator&() {
			assert(ConstIterator::pNode);
			return ConstIterator::Get();
		}

		T &operator*() {
			assert(ConstIterator::pNode);
			assert(ConstIterator::Get());
			return *ConstIterator::Get();
		}
	};



private:
	/*--- �����o�[�ϐ� ---*/

	INode *pHead = nullptr;	// �擪�m�[�h
	DummyNode tail;			// �����m�[�h
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
	/// <param name="value">�ǉ�����l</param>
	void PushFront(const T &value) {
		Insert(begin(), value);
	}

	/// <summary>
	/// �����ɒǉ�����
	/// </summary>
	/// <param name="value">�ǉ�����l</param>
	void PushBack(const T &value) {
		Insert(end(), value);
	}

	/// <summary>
	/// �擪���폜����
	/// </summary>
	/// <returns>
	/// true:�폜����
	/// false:�폜���s
	/// </returns>
	bool PopFront(void) {
		return Remove(begin());
	}

	/// <summary>
	/// �������폜����
	/// </summary>
	/// <returns>
	/// true:�폜����
	/// false:�폜���s
	/// </returns>
	bool PopBack(void) {
		return Remove(--end());
	}

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
		Node *pNode = new Node(value);

		if (iter.GetNode() == nullptr) {
			return false;
		}
		// �擪�|�C���^���X�V
		else if (iter.GetNode() == pHead) {
			pHead = pNode;
		}

		// �ǉ�����
		iter.GetNode()->LinkPrevious(pNode);


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
		INode *pNode = iter.GetNode();

		if (pNode == &tail || pNode == nullptr) {
			return false;
		}
		// �폜����
		else if (pNode) {
			// �擪���폜����Ȃ�X�V
			if (pNode == pHead) {
				pHead = pNode->pNext;
			}

			pNode->Leave();
			delete pNode;

			count--;
			return true;
		}
	}

	/// <summary>
	/// �S�č폜
	/// </summary>
	void Clear(void) {
		INode *pTmpNode;

		// �m�[�h��S�č폜
		while (pHead != &tail) {
			pTmpNode = pHead;
			pHead = pHead->pNext;

			delete pTmpNode;
		}

		// ���Z�b�g
		pHead = &tail;
		count = 0;
	}

	Iterator begin(void) {
		return Iterator(pHead);
	}

	Iterator end(void) {
		return Iterator(&tail);
	}

	ConstIterator ConstBegin(void) {
		return ConstIterator(pHead);
	}

	ConstIterator ConstEnd(void) {
		return ConstIterator(&tail);
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
