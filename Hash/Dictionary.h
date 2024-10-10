/*--------------------------------------------------
	Name : Dictionary
	Date : 2024/10/07
--------------------------------------------------*/

#pragma once
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

/*--- include ---*/
#include "../FSProject/List.h"
#include <cassert>
#include <vector>
#include <functional>



/// <summary>
/// リストクラス
/// </summary>
template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
class Dictionary {
public:
	/*--- インナークラス ---*/

	struct Pair {
		/*--- メンバー変数 ---*/

		K key = K();
		V value = V();



	public:
		/*--- コンストラクタ ---*/

		Pair() = default;
		Pair(const K &key, const V &value) : key(key), value(value) { };
	};



private:
	/*--- メンバー変数 ---*/

	std::vector<List<Pair>> bucket = std::vector<List<Pair>>(BUCKET_SIZE);
	unsigned int count = 0;	// 全てのリスト内の要素数



public:
	/*--- メンバー関数 ---*/

	/// <summary>
	/// 挿入
	/// </summary>
	/// <param name="key">挿入するキー</param>
	/// <param name="value">挿入する値</param>
	/// <returns>
	/// true:挿入成功
	/// false:挿入失敗
	/// </returns>
	bool Insert(const K &key, const V &value);

	/// <summary>
	/// 検索
	/// </summary>
	/// <param name="key">検索するキー</param>
	/// <param name="outValue">キーに対応する値を返す</param>
	/// <returns>
	/// true:検索成功
	/// false:検索失敗
	/// </returns>
	bool Find(const K &key, V &outValue) const;

	/// <summary>
	/// 削除
	/// </summary>
	/// <param name="key">削除するキー</param>
	/// <returns>
	/// true:削除成功
	/// false:削除失敗
	/// </returns>
	bool Remove(const K &key);

	/// <summary>
	/// ハッシュ値の計算
	/// </summary>
	/// <param name="key">キー</param>
	/// <returns>ハッシュの値</returns>
	unsigned int CalcHash(const K &key) const;



public:
	/*--- アクセサ関数 ---*/

	/// <summary>
	/// 要素数を取得
	/// </summary>
	/// <returns>要素数</returns>
	unsigned int GetCount(void) const;
};

#include "Dictionary.inl"

#endif
