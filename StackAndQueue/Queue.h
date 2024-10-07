/*--------------------------------------------------
	Name : Queue
	Date : 2024/10/04
--------------------------------------------------*/

#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

/*--- include ---*/
#include "../FSProject/List.h"



/// <summary>
/// Queueクラス
/// </summary>
template<class T>
class Queue {
private:
	/*--- メンバー変数 ---*/

	List<T> list;		// リスト



public:
	/*--- メンバー関数 ---*/

	/// <summary>
	/// 末尾に要素を追加
	/// </summary>
	/// <param name="value">プッシュする値</param>
	/// <returns>
	/// true:プッシュ成功
	/// false:プッシュ失敗
	/// </returns>
	bool Push(const T &value) {
		// 末尾に挿入
		return list.Insert(list.end(), value)
	}

	/// <summary>
	/// 先頭から要素を取り出す
	/// </summary>
	/// <param name="pDst">先頭の値を返すポインタ</param>
	/// <returns>
	/// true:ポップ成功
	/// false:ポップ失敗
	/// </returns>
	bool Pop(T *pDst) {
		// 要素が何もないなら
		if (list.GetCount() == 0) return false;

		// 先頭の値を取得
		if (pDst) *pDst = list.front();

		// 先頭のノードを削除
		return list.Remove(--list.end());
	}

	/// <summary>
	/// 先頭の値を取得
	/// </summary>
	/// <returns>
	/// 先頭の値
	/// </returns>
	T &front(void) {
		return list.front();
	}

	/// <summary>
	/// 末尾の値を取得
	/// </summary>
	/// <returns>
	/// 末尾の値
	/// </returns>
	T &back(void) {
		return list.back();
	}



public:
	/*--- アクセサ関数 ---*/

	/// <summary>
	/// 要素数を取得
	/// </summary>
	/// <returns>要素数</returns>
	unsigned int GetCount(void) const {
		return list.GetCount();
	}
};

#endif
