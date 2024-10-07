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

		T value = T();
		Node *pNext = this;		// 次のノード
		Node *pPrev = this;		// 前のノード



		/*--- コンストラクタ ---*/

		Node() = default;
		Node(const T &value) : value(value) { }
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
		Node *GetNode(void) { return pNode; }



	public:
		/*--- オペレータ ---*/

		ConstIterator &operator++();

		ConstIterator &operator--();

		ConstIterator operator++(int);

		ConstIterator operator--(int);

		T const &operator* () const;

		ConstIterator operator=(const ConstIterator &iter);

		bool operator==(ConstIterator &iter) const;

		bool operator!=(ConstIterator &iter) const;
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

		Iterator &operator++();

		Iterator &operator--();

		Iterator operator++(int);

		Iterator operator--(int);

		T &operator*();

		bool operator==(Iterator &iter);

		bool operator!=(Iterator &iter);
	};



private:
	/*--- メンバー変数 ---*/

	Node dummy;				// ダミーノード
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
	/// 挿入
	/// </summary>
	/// <param name="iter">挿入先のイテレータ</param>
	/// <param name="value">挿入する値</param>
	/// <returns>
	/// true:挿入成功
	/// false:挿入失敗
	/// </returns>
	bool Insert(ConstIterator iter, const T &value);

	/// <summary>
	/// 削除する
	/// </summary>
	/// <param name="iter">削除するイテレータ</param>
	/// <returns>
	/// true:削除成功
	/// false:削除失敗
	/// </returns>
	bool Remove(ConstIterator iter);

	/// <summary>
	/// ソート
	/// </summary>
	/// <param name="func">ソート時の関数</param>
	void Sort(Iterator first, Iterator last, std::function<bool(T &, T &)> func);


	/// <summary>
	/// 全て削除
	/// </summary>
	void Clear(void);

private:
	
	/// <summary>
	/// 繋げる
	/// </summary>
	/// <param name="pThis">場所を指定するノードポインタ</param>
	/// <param name="pOther">新しく繋げたいノードポインタ</param>
	void Link(Node *pThis, Node *pOther);
	
	/// <summary>
	/// 繋げる
	/// </summary>
	/// <param name="thisIter">場所を指定するイテレータ</param>
	/// <param name="otherIter">新しく繋げたいイテレータ</param>
	void Link(Iterator thisIter, Iterator otherIter);

	/// <summary>
	/// 離す
	/// </summary>
	/// <param name="pThis">接続を切るノードポインタ</param>
	void Leave(Node *pThis);

	/// <summary>
	/// 離す
	/// </summary>
	/// <param name="thisIter">接続を切るイテレータ</param>
	void Leave(Iterator thisIter);



public:
	/*--- アクセサ関数 ---*/

	/// <summary>
	/// 先頭のイテレータを取得
	/// </summary>
	/// <returns>先頭のイテレータ</returns>
	Iterator begin(void);

	/// <summary>
	/// 末尾のイテレータを取得
	/// </summary>
	/// <returns>末尾のイテレータ</returns>
	Iterator end(void);

	/// <summary>
	/// 先頭のコンストイテレータを取得
	/// </summary>
	/// <returns>先頭のイテレータ</returns>
	ConstIterator begin(void) const;

	/// <summary>
	/// 末尾のコンストイテレータを取得
	/// </summary>
	/// <returns>末尾のイテレータ</returns>
	ConstIterator end(void) const;

	/// <summary>
	/// 先頭のコンストイテレータを取得
	/// </summary>
	/// <returns>先頭のコンストイテレータ</returns>
	ConstIterator cbegin(void) const;

	/// <summary>
	/// 末尾のコンストイテレータを取得
	/// </summary>
	/// <returns>末尾のコンストイテレータ</returns>
	ConstIterator cend(void) const;

	/// <summary>
	/// 先頭の値を取得
	/// </summary>
	/// <returns>先頭の値</returns>
	T &front(void);

	/// <summary>
	/// 末尾の値を取得
	/// </summary>
	/// <returns>末尾の値</returns>
	T &back(void);

	/// <summary>
	/// 要素数を取得
	/// </summary>
	/// <returns>要素数</returns>
	unsigned int GetCount(void) const { return count; }
};


#include "List.inl"

#endif
