#include "pch.h"
#include "ManualTest1_4.h"
#include <gtest/gtest.h>

/*--- include ---*/
#include "../FSProject/List.h"



#ifdef ID07_COMPILE_ERROR_CHECK

	/// <summary>
	/// テスト項目　　：型などが不適切なキー指定が引数で渡された時の挙動
	/// 意図する結果　：コンパイルエラーとなる
	/// 補足　　　　　：コンパイルエラーをチェック。自動テスト化しない
	/// </summary>
TEST(QuickSortTest, ID07_WrongKey) {
	List<int> list;

	list.Insert(list.end(), 5);
	list.Insert(list.end(), 1);
	list.Insert(list.end(), 3);

	// キーの指定なしでソート
	list.Sort([](float &a, bool &b) { return a < b; });
}

#endif



#ifdef ID08_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 意図する結果　：コンパイルエラーとなる
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(QuickSortTest, ID08_Const) {
	const List<int> list;

	// キーの指定なしでソート
	list.Sort([](int &a, int &b) { return a < b; });
}

#endif
