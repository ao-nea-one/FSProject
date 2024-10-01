/*--------------------------------------------------
	Name : List
	Date : 2024/10/01
--------------------------------------------------*/

#pragma once
#ifndef _LIST_H_
#define _LIST_H_



/// <summary>
/// リストクラス
/// </summary>
template<class T>
class List {
public:
	/*--- クラス ---*/

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

	/// <summary>
	/// イテレータクラス
	/// </summary>
	class Iterator {
	private:
		/*--- メンバー変数 ---*/

		Node *pNode = nullptr;	// 現在のノード

		friend List;



	public:
		/*--- コンストラクタ ---*/

		Iterator() = default;

	private:

		Iterator(Node *pNode) : pNode(pNode) { }



	private:
		/*--- メンバー関数 ---*/

		Node *GetNode(void) { return pNode; }



	public:
		/*--- オペレータ ---*/

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
	/*--- メンバー変数 ---*/

	Node *pHead = nullptr;	// 先頭ノード
	Node *pTail = nullptr;	// 末尾ノード
	unsigned int count = 0;	// 要素数



public:
	/*--- コンストラクタ ---*/

	List() = default;



public:
	/*--- デストラクタ ---*/

	~List() { Clear(); }



public:
	/*--- メンバー関数 ---*/

	/// <summary>
	/// 先頭に追加する
	/// </summary>
	/// <param name="value"></param>
	void PushFront(T value) {
		Node *pNode = new Node(value);

		// 追加処理
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
	/// 末尾に追加する
	/// </summary>
	/// <param name="value"></param>
	void PushBack(T value) {
		Node *pNode = new Node(value);

		// 追加処理
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
	/// 先頭を削除する
	/// </summary>
	void PopFront(void) {
		if (pHead) {
			Node *pNext = pHead->pNext;

			// 削除処理
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
	/// 末尾を削除する
	/// </summary>
	void PopBack(void) {
		if (pTail) {
			Node *pPrev = pTail->pPrev;

			// 削除処理
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
		return nullptr;
	}
};


#endif
