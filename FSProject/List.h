/*--------------------------------------------------
	Name : List
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _LIST_H_
#define _LIST_H_

/*--- include ---*/



/// <summary>
/// リストクラス
/// </summary>
template<class T>
class List {
private:
	/*--- インナークラス ---*/

	/// <summary>
	/// ノードクラス
	/// </summary>
	class Node {
	private:
		/*--- メンバー変数 ---*/

		T value;				// 値
		Node *pNext = nullptr;	// 次のノード
		Node *pPrev = nullptr;	// 前のノード

		friend List;



	public:
		/*--- コンストラクタ ---*/

		Node() = default;
		Node(const T &value) : value(value) { }



	public:
		/*--- メンバー関数 ---*/

		/// <summary>
		/// nextに繋げる
		/// </summary>
		/// <param name="pNode"></param>
		/// <returns></returns>
		T *LinkNext(Node *pNode) {
			// nullチェック
			if (pNode == nullptr) return nullptr;

			pNode->pNext = this->pNext;
			this->pNext = pNode;
			pNode->pPrev = this;
			if (pNode->pNext) pNode->pNext->pPrev = pNode;
		}

		/// <summary>
		/// previousに繋げる
		/// </summary>
		/// <param name="pNode"></param>
		/// <returns></returns>
		T *LinkPrevious(Node *pNode) {
			// nullチェック
			if (pNode == nullptr) return nullptr;

			pNode->pPrev = this->pPrev;
			this->pPrev = pNode;
			pNode->pNext = this;
			if (pNode->pPrev) pNode->pPrev->pNext = pNode;
		}

		/// <summary>
		/// 離す
		/// </summary>
		void Leave() {
			if (pNext) pNext->pPrev = pPrev;
			if (pPrev) pPrev->pNext = pNext;
			pNext = pPrev = nullptr;
		}



	public:
		/*--- アクセサ関数 ---*/

		/// <summary>
		/// 値を取得
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		T &Get(void) { return value; }
	};

public:

	/// <summary>
	/// コンストイテレータクラス
	/// </summary>
	class ConstIterator {
	private:
		/*--- メンバー変数 ---*/

		Node *pNode = nullptr;	// 現在のノード

		friend List;



	public:
		/*--- コンストラクタ ---*/

		ConstIterator() = default;
		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode) { }

	protected:

		ConstIterator(Node *pNode) : pNode(pNode) { }



	protected:
		/*--- メンバー関数 ---*/

		Node *GetNode(void) { return pNode; }



	public:
		/*--- オペレータ ---*/

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
	/// イテレータクラス
	/// </summary>
	class Iterator : public ConstIterator {
	private:

		friend List;

	public:
		/*--- コンストラクタ ---*/

		Iterator() = default;
		Iterator(const Iterator &iter) : ConstIterator(iter.pNode) { }

	protected:

		Iterator(Node *pNode) : ConstIterator(pNode) { }



	protected:
		/*--- メンバー関数 ---*/

		Node *GetNode(void) { return pNode; }



	public:
		/*--- オペレータ ---*/

		T *operator&() { return &ConstIterator::GetNode()->Get(); }
		T &operator*() { return ConstIterator::GetNode()->Get(); }
	};



private:
	/*--- メンバー変数 ---*/

	Node *pHead = nullptr;	// 先頭ノード
	Node tail;				// 末尾ノード
	unsigned int count = 0;	// 要素数



public:
	/*--- コンストラクタ ---*/

	List() {
		pHead = &tail;
	}



public:
	/*--- デストラクタ ---*/

	~List() { Clear(); }



public:
	/*--- メンバー関数 ---*/

	/// <summary>
	/// 先頭に追加する
	/// </summary>
	/// <param name="value"></param>
	void PushFront(const T &value) {
		Node *pNode = new Node(value);

		// 追加処理
			pHead->LinkPrevious(pNode);
			pHead = pNode;


		count++;
	}

	/// <summary>
	/// 末尾に追加する
	/// </summary>
	/// <param name="value"></param>
	void PushBack(const T &value) {
		Node *pNode = new Node(value);

		// 追加処理
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
	/// 先頭を削除する
	/// </summary>
	void PopFront(void) {
		if (pHead != &tail) {
			Node *pNext = pHead->pNext;

			// 削除処理
			pHead->Leave();
			delete pHead;
			pHead = pNext;


			count--;
		}
	}

	/// <summary>
	/// 末尾を削除する
	/// </summary>
	void PopBack(void) {
		if (pHead != &tail) {
			Node *pPrev = tail.pPrev->pPrev;

			// 削除処理
			tail.pPrev->Leave();
			delete tail.pPrev;
			tail.pPrev = pPrev;


			count--;
		}
	}



	/// <summary>
	/// 挿入する
	/// </summary>
	void Insert(Iterator &iter, const T&value) {
		Node *pNode = new Node(value);

		// 追加処理
		if (iter.GetNode()) {
			iter.GetNode()->LinkNext(pNode);

			count++;
		}
	}

	/// <summary>
	/// 削除する
	/// </summary>
	void Remove(Iterator &iter) {
		Node *pNode = iter.GetNode();

		// 削除処理
		if (pNode) {
			// 先頭を削除したなら更新
			if (pNode == pHead) {
				pHead = pNode->pNext;
			}

			pNode->Leave();
			delete pNode;

			count--;
		}
	}

	/// <summary>
	/// 全て削除
	/// </summary>
	/// <param name=""></param>
	void Clear(void) {
		Node *pTmpNode;

		// ノードを全て削除
		while (pHead) {
			pTmpNode = pHead;
			pHead = pHead->pNext;

			delete pTmpNode;
		}

		// リセット
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
	/*--- アクセサ関数 ---*/

	unsigned int GetCount(void) { return count; }
};


#endif
