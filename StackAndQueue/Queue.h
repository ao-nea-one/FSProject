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
	/// <returns>
	/// 末尾の値
	/// </returns>
	T Pop(void) {
		// 末尾の値を取得
		T result = list.front();

		// 末尾のノードを削除
		list.Remove(--list.end());

		return result;
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
