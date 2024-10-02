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
/// リストクラス
/// </summary>
template<class T>
class List {
private:
	/*--- インナークラス ---*/

	/// <summary>
	/// ノードクラス:インターフェース
	/// </summary>
	class INode {
	private:
		/*--- メンバー変数 ---*/

		INode *pNext = nullptr;	// 次のノード
		INode *pPrev = nullptr;	// 前のノード

		friend List;



	public:
		/*--- コンストラクタ ---*/

		INode() = default;



	public:
		/*--- メンバー関数 ---*/

		/// <summary>
		/// nextに繋げる
		/// </summary>
		/// <param name="pNode"></param>
		/// <returns></returns>
		T *LinkNext(INode *pNode) {
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
		T *LinkPrevious(INode *pNode) {
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

		/// <summary>
		/// ダミーノードか否か
		/// </summary>
		/// <returns>
		/// true:ダミーノード
		/// false:デフォルトノード
		/// </returns>
		virtual bool IsDummy(void) = 0;

		/// <summary>
		/// 値を取得
		/// </summary>
		/// <returns>格納する値のポインタ</returns>
		virtual T *Get(void) = 0;
	};

	/// <summary>
	/// ノードクラス
	/// </summary>
	class Node : public INode {
	private:
		/*--- メンバー変数 ---*/

		T value;				// 値

		friend List;



	public:
		/*--- コンストラクタ ---*/

		Node() = default;
		Node(const T &value) : value(value) { }



	public:
		/*--- メンバー関数 ---*/

		/// <summary>
		/// ダミーノードか否か
		/// </summary>
		/// <returns>
		/// true:ダミーノード
		/// false:デフォルトノード
		/// </returns>
		bool IsDummy(void) override { return false; }



	public:
		/*--- アクセサ関数 ---*/

		/// <summary>
		/// 値を取得
		/// </summary>
		/// <returns>格納する値のポインタ</returns>
		T *Get(void) override { return &value; }
	};

	/// <summary>
	/// ダミーノードクラス（値を保持しない）
	/// </summary>
	class DummyNode : public INode {
	private:
		/*--- メンバー変数 ---*/

		friend List;



	public:
		/*--- コンストラクタ ---*/

		DummyNode() = default;



	public:
		/*--- メンバー関数 ---*/

		/// <summary>
		/// ダミーノードか否か
		/// </summary>
		/// <returns>true:ダミーノード　false:デフォルトノード</returns>
		bool IsDummy(void) override { return true; }



	public:
		/*--- アクセサ関数 ---*/

		/// <summary>
		/// 値を取得
		/// </summary>
		/// <returns>nullptr</returns>
		T *Get(void) override { return nullptr; }
	};

public:

	/// <summary>
	/// コンストイテレータクラス
	/// </summary>
	class ConstIterator {
	protected:
		/*--- メンバー変数 ---*/

		INode *pNode = nullptr;	// 現在のノード

		friend List;



	public:
		/*--- コンストラクタ ---*/

		ConstIterator() = default;
		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode) { }

	protected:

		ConstIterator(INode *pNode) : pNode(pNode) { }



	public:
		/*--- メンバー関数 ---*/

		/// <summary>
		/// ダミーノードか否か
		/// </summary>
		/// <returns>
		/// true:ダミーノード
		/// false:nullptr or デフォルトノード 
		/// </returns>
		bool IsDummy(void) { return pNode ? pNode->IsDummy() : false; }

		/// <summary>
		/// ノードが保持されているか否か
		/// </summary>
		/// <returns>
		/// true:nullptr
		/// false:ノードが存在する
		/// </returns>
		bool IsEmpty(void) { return pNode == nullptr; }



	protected:
		/*--- アクセサ関数 ---*/

		/// <summary>
		/// ノードを取得
		/// </summary>
		/// <returns>ノードポインタ</returns>
		INode *GetNode(void) { return pNode; }

	public:

		/// <summary>
		/// 値を取得する
		/// </summary>
		/// <returns>ノードに格納されている値</returns>
		T *Get(void) {
			assert(pNode);
			return pNode->Get();
		}



	public:
		/*--- オペレータ ---*/

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

		Iterator(INode *pNode) : ConstIterator(pNode) { }



	public:
		/*--- オペレータ ---*/

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
	/*--- メンバー変数 ---*/

	INode *pHead = nullptr;	// 先頭ノード
	DummyNode tail;			// 末尾ノード
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
	/// <param name="value">追加する値</param>
	void PushFront(const T &value) {
		Insert(begin(), value);
	}

	/// <summary>
	/// 末尾に追加する
	/// </summary>
	/// <param name="value">追加する値</param>
	void PushBack(const T &value) {
		Insert(end(), value);
	}

	/// <summary>
	/// 先頭を削除する
	/// </summary>
	/// <returns>
	/// true:削除成功
	/// false:削除失敗
	/// </returns>
	bool PopFront(void) {
		return Remove(begin());
	}

	/// <summary>
	/// 末尾を削除する
	/// </summary>
	/// <returns>
	/// true:削除成功
	/// false:削除失敗
	/// </returns>
	bool PopBack(void) {
		return Remove(--end());
	}

	/// <summary>
	/// 挿入
	/// </summary>
	/// <param name="iter">挿入先のイテレータ</param>
	/// <param name="value">挿入する値</param>
	/// <returns>
	/// true:挿入成功
	/// false:挿入失敗
	/// </returns>
	bool Insert(ConstIterator iter, const T&value) {
		Node *pNode = new Node(value);

		if (iter.GetNode() == nullptr) {
			return false;
		}
		// 先頭ポインタを更新
		else if (iter.GetNode() == pHead) {
			pHead = pNode;
		}

		// 追加処理
		iter.GetNode()->LinkPrevious(pNode);


		count++;

		return true;
	}

	/// <summary>
	/// 削除する
	/// </summary>
	/// <param name="iter">削除するイテレータ</param>
	/// <returns>
	/// true:削除成功
	/// false:削除失敗
	/// </returns>
	bool Remove(ConstIterator iter) {
		INode *pNode = iter.GetNode();

		if (pNode == &tail || pNode == nullptr) {
			return false;
		}
		// 削除処理
		else if (pNode) {
			// 先頭を削除するなら更新
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
	/// 全て削除
	/// </summary>
	void Clear(void) {
		INode *pTmpNode;

		// ノードを全て削除
		while (pHead != &tail) {
			pTmpNode = pHead;
			pHead = pHead->pNext;

			delete pTmpNode;
		}

		// リセット
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
	/*--- アクセサ関数 ---*/

	/// <summary>
	/// 要素数を取得
	/// </summary>
	/// <returns>要素数</returns>
	unsigned int GetCount(void) { return count; }
};


#endif
