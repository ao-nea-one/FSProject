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
template<class K, class V>
class Dictionary {
private:
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

	unsigned int BUCKET_SIZE = 10;
	std::vector<List<Pair>> bucket = std::vector<List<Pair>>(BUCKET_SIZE);



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
	/// <returns>キーに対応する値</returns>
	V &Find(const K &key);
};

#include "Dictionary.inl"

#endif
