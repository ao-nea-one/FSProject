#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"

#define NO01_04_Test
#ifdef NO01_04_Test

namespace No01_04_QuickSort {

	/// <summary>
	/// テスト項目　　：要素を持たないリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：エラー含めて、何も起こらない
	/// </summary>
	TEST(QuickSortTest, ID00_SortEmpty) {
		List<int> list;

		// 空でソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		list.Insert(list.begin(), 0);
		list.Insert(list.begin(), 1);
		list.Insert(list.begin(), 2);
		list.Insert(list.begin(), 3);
		list.Insert(list.begin(), 4);
		list.Insert(list.begin(), 5);
	}

	/// <summary>
	/// テスト項目　　：要素を1つだけ持つリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：エラー含めて、何も起こらない
	/// </summary>
	TEST(QuickSortTest, ID01_SortOne) {
		List<int> list;

		list.Insert(list.begin(), 0);

		// 1要素だけでソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		EXPECT_EQ(*list.begin(), 0);
	}

	/// <summary>
	/// テスト項目　　：2つ以上要素を持つリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：要素が指定したキーに準じて指定した順に並ぶ
	/// 補足　　　　　：先頭から順にイテレータで確認し、ノードの差し替えが正常に行えているかチェック
	/// </summary>
	TEST(QuickSortTest, ID02_SortMultiple) {
		List<int> list;

		list.Insert(list.end(), 3);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 2);
		list.Insert(list.end(), 5);
		list.Insert(list.end(), 4);

		// 複数の要素でソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// 値をチェック
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 4);
		EXPECT_EQ(*iter++, 5);
	}

	/// <summary>
	/// テスト項目　　：同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：要素がソートされて並ぶが、同じ要素の順序は保証されない
	/// </summary>
	TEST(QuickSortTest, ID03_SortSameElement) {
		List<int> list;

		list.Insert(list.end(), 3);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 4);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 5);

		// 同じ要素があるリストでソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// 値をチェック
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 4);
		EXPECT_EQ(*iter++, 5);
	}

	/// <summary>
	/// テスト項目　　：整列済みリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：同じキーの要素の間以外の順番が変動しない
	/// 補足　　　　　：重複要素なしの整列済みリストを使う
	/// </summary>
	TEST(QuickSortTest, ID04_Resort) {
		List<int> list;

		list.Insert(list.end(), 2);
		list.Insert(list.end(), 7);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 8);

		// 1度目のソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// 値をチェック
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 7);
		EXPECT_EQ(*iter++, 8);

		// 整列済みのリストで再度ソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// 値をチェック
		iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 7);
		EXPECT_EQ(*iter++, 8);
	}

	/// <summary>
	/// テスト項目　　：一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：要素がソートされて並ぶ
	/// 補足　　　　　：重複要素なしの整列済みリストを使う
	/// </summary>
	TEST(QuickSortTest, ID05_ResortAndInsert) {
		List<int> list;

		list.Insert(list.end(), 5);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 3);

		// 1度目のソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// 値をチェック
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 5);


		// 再度挿入
		iter = list.begin();
		list.Insert(++iter, 2);
		list.Insert(++iter, 4);
		list.Insert(++iter, 6);

		// 再度ソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// 値をチェック
		iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 4);
		EXPECT_EQ(*iter++, 5);
		EXPECT_EQ(*iter++, 6);
	}

	/// <summary>
	/// テスト項目　　：キー指定をしなかった(nullptrを渡した)時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：エラー含めて、何も起こらない
	/// </summary>
	TEST(QuickSortTest, ID06_ResortAndInsert) {
		List<int> list;

		list.Insert(list.end(), 5);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 3);

		// キーの指定なしでソート
		list.Sort(list.begin(), list.end(), nullptr);
	}

#ifdef COMPILE_ERROR

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
		list.Sort(list.begin(), list.end(), [](float &a, bool &b) { return a < b; });
	}

	/// <summary>
	/// テスト項目　　：非constのメソッドであるか
	/// 意図する結果　：コンパイルエラーとなる
	/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
	/// </summary>
	TEST(QuickSortTest, ID07_WrongKey) {
		const List<int> list;

		list.Insert(list.end(), 5);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 3);

		// キーの指定なしでソート
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });
	}

#endif
}

#endif
