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
/// リストクラス
/// </summary>
template<class T>
class List {
private:
	/*--- インナークラス ---*/

	/// <summary>
	/// ノードクラス:インターフェース
	/// </summary>
	struct Node {
		/*--- メンバー変数 ---*/

		T *pValue = nullptr;
		Node *pNext = this;		// 次のノード
		Node *pPrev = this;		// 前のノード



		/*--- コンストラクタ ---*/

		Node() = default;
		Node(T* pValue) : pValue(pValue) { }
	};



public:

	/// <summary>
	/// コンストイテレータクラス
	/// </summary>
	class ConstIterator {

		friend List;

	protected:
		/*--- メンバー変数 ---*/

		Node *pNode = nullptr;	// 現在のノード
		const List<T> *pParent = nullptr;



	public:
		/*--- コンストラクタ ---*/

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
		/*--- アクセサ関数 ---*/

		/// <summary>
		/// ノードを取得
		/// </summary>
		/// <returns>ノードポインタ</returns>
		Node *GetNode(void) const { return pNode; }



	public:
		/*--- オペレータ ---*/

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
	/// イテレータクラス
	/// </summary>
	class Iterator : public ConstIterator {

		friend List;

	public:
		/*--- コンストラクタ ---*/

		Iterator() = default;
		Iterator(const Iterator &iter) : ConstIterator(iter.pNode, iter.pParent) { }

	protected:

		Iterator(Node *pNode, List<T> *pParent) : ConstIterator(pNode, pParent) { }



	public:
		/*--- オペレータ ---*/

		T &operator*() {
			assert(ConstIterator::pNode);
			assert(ConstIterator::pNode->pValue);
			return *ConstIterator::pNode->pValue;
		}
	};



private:
	/*--- メンバー変数 ---*/

	Node dummy;				// ダミーノード
	unsigned int count = 0;	// 要素数



public:
	/*--- デストラクタ ---*/

	~List() { Clear(); }



public:
	/*--- メンバー関数 ---*/

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
		// nullチェック
		if (iter.GetNode() == nullptr) return false;
		// 無関係のリスト
		if (iter.pParent != this) return false;

		Node *pNode = new Node(new T(value));


		// 追加処理
		Link(iter.GetNode(), pNode);


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
		// nullチェック
		if (iter.GetNode() == nullptr) return false;
		// ダミーチェック
		if (iter.GetNode() == &dummy) return false;
		// 無関係のリスト
		if (iter.pParent != this) return false;



		Node *pNode = iter.GetNode();

		// 削除処理
		if (pNode) {
			Leave(pNode);
			delete pNode->pValue;
			delete pNode;

			count--;
			return true;
		}
	}

	/// <summary>
	/// 全て削除
	/// </summary>
	void Clear(void) {
		if (count == 0) return;

		Node *pNode = dummy.pNext;
		Node *pTmp = nullptr;

		// ノードを全て削除
		while (pNode != &dummy) {
			pTmp = pNode;
			pNode = pNode->pNext;

			delete pTmp->pValue;
			delete pTmp;
		}

		// リセット
		count = 0;
	}

	/// <summary>
	/// 先頭のイテレータを取得
	/// </summary>
	/// <returns>先頭のイテレータ</returns>
	Iterator begin(void) {
		return Iterator(dummy.pNext, this);
	}

	/// <summary>
	/// 末尾のイテレータを取得
	/// </summary>
	/// <returns>末尾のイテレータ</returns>
	Iterator end(void) {
		return Iterator(&dummy, this);
	}

	/// <summary>
	/// 先頭のコンストイテレータを取得
	/// </summary>
	/// <returns>先頭のコンストイテレータ</returns>
	ConstIterator cbegin(void) const {
		return ConstIterator(dummy.pNext, this);
	}

	/// <summary>
	/// 末尾のコンストイテレータを取得
	/// </summary>
	/// <returns>末尾のコンストイテレータ</returns>
	ConstIterator cend(void) const {
		return ConstIterator(const_cast<Node*>(&dummy), this);
	}

	/// <summary>
	/// 先頭の値を取得
	/// </summary>
	/// <returns>先頭の値</returns>
	T &front(void) {
		assert(dummy.pNext->pValue);
		return *dummy.pPrev->pValue;
	}

	/// <summary>
	/// 末尾の値を取得
	/// </summary>
	/// <returns>末尾の値</returns>
	T &back(void) {
		assert(dummy.pPrev->pValue);
		return *dummy.pPrev->pValue;
	}

private:
	
	/// <summary>
	/// 繋げる
	/// </summary>
	/// <param name="pThis">場所を指定するノードポインタ</param>
	/// <param name="pOther">新しく繋げたいノードポインタ</param>
	void Link(Node *pThis, Node *pOther) {
		if (pThis == pOther) return;

		// 繋げる処理
		pOther->pPrev = pThis->pPrev;
		pThis->pPrev = pOther;
		pOther->pNext = pThis;
		if (pOther->pPrev) pOther->pPrev->pNext = pOther;
	}
	
	/// <summary>
	/// 繋げる
	/// </summary>
	/// <param name="thisIter">場所を指定するイテレータ</param>
	/// <param name="otherIter">新しく繋げたいイテレータ</param>
	void Link(Iterator thisIter, Iterator otherIter) {
		Link(thisIter.GetNode(), otherIter.GetNode());
	}

	/// <summary>
	/// 離す
	/// </summary>
	/// <param name="pThis">接続を切るノードポインタ</param>
	void Leave(Node *pThis) {
		// 切り離す処理
		if (pThis->pNext) pThis->pNext->pPrev = pThis->pPrev;
		if (pThis->pPrev) pThis->pPrev->pNext = pThis->pNext;
		pThis->pNext = pThis->pPrev = nullptr;
	}

	/// <summary>
	/// 離す
	/// </summary>
	/// <param name="thisIter">接続を切るイテレータ</param>
	void Leave(Iterator thisIter) {
		Leave(thisIter.GetNode());
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
