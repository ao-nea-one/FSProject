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
Iterator e = end();\
for (Iterator j = begin(); j != e; ++j) {\
	if (j == l || j == r) std::cout << "[";\
	std::cout << *j;\
	if (j == l || j == r) std::cout << "]";\
}\
std::cout << std::endl;\
}\



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
		Node *pNext = nullptr;	// 次のノード
		Node *pPrev = nullptr;	// 前のノード



		/*--- コンストラクタ ---*/

		Node() = default;
		Node(T *pValue) : pValue(pValue) { }
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




	public:
		/*--- コンストラクタ ---*/

		ConstIterator() = default;
		ConstIterator(const ConstIterator &iter) : pNode(iter.pNode) { }

	protected:

		ConstIterator(Node *pNode) : pNode(pNode) { }



	protected:
		/*--- アクセサ関数 ---*/

		/// <summary>
		/// ノードを取得
		/// </summary>
		/// <returns>ノードポインタ</returns>
		Node *GetNode(void) { return pNode; }



	public:
		/*--- オペレータ ---*/

		ConstIterator operator++() {
			assert(pNode);
			assert(pNode->pNext);
			return ConstIterator(pNode = pNode->pNext);
		}

		ConstIterator operator--() {
			assert(pNode);
			assert(pNode->pPrev);
			return ConstIterator(pNode = pNode->pPrev);
		}

		ConstIterator operator++(int) {
			assert(pNode);
			assert(pNode->pNext);
			return ConstIterator(pNode = pNode->pNext);
		}

		ConstIterator operator--(int) {
			assert(pNode);
			assert(pNode->pPrev);
			return ConstIterator(pNode = pNode->pPrev);
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
	/// イテレータクラス
	/// </summary>
	class Iterator : public ConstIterator {

		friend List;

	public:
		/*--- コンストラクタ ---*/

		Iterator() = default;
		Iterator(const Iterator &iter) : ConstIterator(iter.pNode) { }

	protected:

		Iterator(Node *pNode) : ConstIterator(pNode) { }



	public:
		/*--- オペレータ ---*/

		Iterator operator++() {
			assert(ConstIterator::GetNode());
			assert(ConstIterator::GetNode()->pNext);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pNext);
		}

		Iterator operator--() {
			assert(ConstIterator::GetNode());
			assert(ConstIterator::GetNode()->pPrev);
			return Iterator(ConstIterator::pNode = ConstIterator::pNode->pPrev);
		}

		bool operator==(Iterator iter) {
			return ConstIterator::GetNode() == iter.GetNode();
		}

		T &operator*() {
			assert(ConstIterator::GetNode());
			assert(ConstIterator::GetNode()->pValue);
			return *ConstIterator::pNode->pValue;
		}
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
	/// 挿入
	/// </summary>
	/// <param name="iter">挿入先のイテレータ</param>
	/// <param name="value">挿入する値</param>
	/// <returns>
	/// true:挿入成功
	/// false:挿入失敗
	/// </returns>
	bool Insert(ConstIterator iter, const T &value) {
		Node *pNode = new Node(new T(value));

		if (iter.GetNode() == nullptr) {
			return false;
		}

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
		Node *pNode = iter.GetNode();

		if (pNode == &tail || pNode == nullptr) {
			return false;
		}
		// 削除処理
		else if (pNode) {
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

		Node *pNode;

		// ノードを全て削除
		while (pHead != &tail) {
			pNode = pHead;
			pHead = pHead->pNext;

			delete pNode->pValue;
			delete pNode;
		}

		// リセット
		pHead = &tail;
		count = 0;
	}

	void sort(Iterator low, Iterator high, std::function<bool(T &, T &)> func) {
		Iterator pivot = high;

		Iterator sentinel = --Iterator(high);
		for (Iterator l = low; l != sentinel; ++l) {
			if (func(*l, *pivot)) {

			}
		}
	}

	/// <summary>
	/// ソート
	/// </summary>
	/// <param name="func">ソート時の関数</param>
	void Sort(Iterator first, Iterator last, std::function<bool(T &, T &)> func) {
		--last;

		if (first == last) return;

		Iterator pivot = first;
		Iterator l = first;
		Iterator r = last;
		Iterator sentinel = last;
		bool isCross = false;



		while (r != l) {
			print;


			// 先頭から末尾へ調べる
			for (; l != r; ++l) {
				if (l == sentinel) isCross = true;

				if (func(*pivot, *l)) break;
			}




			// 末尾から先頭へ調べる
			for (; r != l; --r) {
				if (r == sentinel) isCross = true;

				if (!func(*pivot, *r)) {
					break;
				}
			}

			print;
			if (r == l) break;

			if (func(*r, *l)) {
				// 先頭を入れ替えるなら firstも更新
				if (l == first) {
					first = r;
				}
				// 末尾を入れ替えるなら lastも更新
				if (r == last) {
					last = l;
				}

				// ノードを入れ替える
				Iterator tmp = ++Iterator(r);
				Leave(r);
				Link(l, r);

				Leave(l);
				Link(tmp, l);

				// 開始位置を入れ替える
				tmp = l;
				l = ++r;
				r = --tmp;

				print;
				if (l == r || l == ++Iterator(r)) break;
			}
		}

		print;


		++last;


		Sort(first, l, func);
		Sort(l, last, func);
		//Sort()
	}


	/// <summary>
	/// 先頭のイテレータを取得
	/// </summary>
	/// <returns>先頭のイテレータ</returns>
	Iterator begin(void) {
		return Iterator(pHead);
	}

	/// <summary>
	/// 末尾のイテレータを取得
	/// </summary>
	/// <returns>末尾のイテレータ</returns>
	Iterator end(void) {
		return Iterator(&tail);
	}

	/// <summary>
	/// 先頭のコンストイテレータを取得
	/// </summary>
	/// <returns>先頭のコンストイテレータ</returns>
	ConstIterator cbegin(void) {
		return ConstIterator(pHead);
	}

	/// <summary>
	/// 末尾のコンストイテレータを取得
	/// </summary>
	/// <returns>末尾のコンストイテレータ</returns>
	ConstIterator cend(void) {
		return ConstIterator(&tail);
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

		// 先頭ポインタの更新
		if (pThis == pHead) pHead = pOther;
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
		// 先頭ポインタの更新
		if (pThis == pHead) pHead = pHead->pNext;


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
