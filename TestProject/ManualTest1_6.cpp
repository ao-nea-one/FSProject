#include "pch.h"
#include "ManualTest1_6.h"
#include <gtest/gtest.h>

/*--- include ---*/
#include "../Hash/Dictionary.h"



/// <summary>
/// ハッシュ関数
/// </summary>
/// <param name="key">キー</param>
/// <returns>値</returns>
size_t Hash(const std::string &key) {
	return std::hash<std::string>()(key);
}

/// <summary>
/// ハッシュ関数
/// </summary>
/// <param name="key">キー</param>
/// <returns>値</returns>
size_t NoHash(const bool &key) {
	return std::hash<bool>()(key);
}



#ifdef ID00_HASH_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：不適切なハッシュ関数がテンプレート引数で渡された時
/// 補足　　　　　：コンパイルエラーをチェック。自動テスト化しない
/// </summary>
TEST(StackGetDataNum, ID00_DefineHash) {
	const Dictionary<std::string, int, 2, NoHash> dic;
}

#endif



#ifdef ID12_HASH_NO_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとならないかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(StackGetDataNum, ID12_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;

	dic.GetCount();
}

#endif



#ifdef ID18_HASH_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(StackInvert, ID18_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;

	dic.Insert("A", 0);
}

#endif



#ifdef ID26_HASH_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(StackRemove, ID18_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;

	dic.Remove("A");
}

#endif



#ifdef ID34_HASH_NO_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：constメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとならないかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(StackFind, ID34_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;
	int tmp = -1;

	dic.Find("A", tmp);
}

#endif
