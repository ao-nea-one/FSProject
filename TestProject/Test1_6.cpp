#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../Hash/Dictionary.h"



namespace No01_06_Hash {

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
	size_t HashByLength(const std::string &key) {
		return key.size();
	}





	namespace HashClassTest {

		namespace HashClassTest {

			/// <summary>
			/// テスト項目　　：算出方法の異なる適切なハッシュ関数を渡したときのそれぞれの挙動
			/// 補足　　　　　：挿入、検索、削除を行い、全ての戻り値がTRUEになるかチェック
			/// </summary>
			TEST(StackGetDataNum, ID01_GetEmpty) {
				Dictionary<std::string, int, 2, Hash> dicA;
				Dictionary<std::string, int, 2, HashByLength> dicB;

				// 挿入テスト
				EXPECT_TRUE(dicA.Insert("A", 0));
				EXPECT_TRUE(dicB.Insert("B", 1));

				// 要素を検索
				int a = -1, b = -1;
				EXPECT_TRUE(dicA.Find("A", a));
				EXPECT_TRUE(dicB.Find("B", b));

				// 要素を削除
				EXPECT_TRUE(dicA.Remove("A"));
				EXPECT_TRUE(dicB.Remove("B"));
			}
		}
	}





	namespace HashGetDataNumTest {

		/// <summary>
		/// テスト項目　　：リストが空である場合の戻り値
		/// 想定する戻り値：0
		/// </summary>
		TEST(HashGetDataNum, ID02_GetEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 0);
		}

		/// <summary>
		/// テスト項目　　：要素を挿入した後の戻り値
		/// 想定する戻り値：1
		/// </summary>
		TEST(HashGetDataNum, ID03_Insert) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// テスト項目　　：要素を挿入し、そのキーで削除した後の戻り値
		/// 想定する戻り値：0
		/// </summary>
		TEST(HashGetDataNum, ID04_InsertAndRemove) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));

			// 削除
			EXPECT_TRUE(dic.Remove("A"));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 0);
		}

		/// <summary>
		/// テスト項目　　：既に存在するキーで要素の挿入をし失敗した後の戻り値
		/// 想定する戻り値：1
		/// 補足　　　　　：１回挿入した後、そのキーで再度挿入する
		/// </summary>
		TEST(HashGetDataNum, ID05_InsertTwice) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_FALSE(dic.Insert("A", 0));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// テスト項目　　：リストに要素がある時に存在しないキーを指定し要素の削除に失敗した際の戻り値
		/// 想定する戻り値：1
		/// 補足　　　　　：１回挿入した後、異なるキーで削除する
		/// </summary>
		TEST(HashGetDataNum, ID06_InsertAndNoneRemove) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));

			// 削除
			EXPECT_FALSE(dic.Remove("B"));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// テスト項目　　：リストが空である場合に、削除を行った後の戻り値
		/// 想定する戻り値：0
		/// </summary>
		TEST(HashGetDataNum, ID07_RemoveEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 削除
			EXPECT_FALSE(dic.Remove("A"));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 0);
		}

		/// <summary>
		/// テスト項目　　：要素２つが内部でチェインになっていない時の戻り値
		/// 想定する戻り値：2
		/// 補足　　　　　：チェインによって要素数処理が変化しないことをチェック
		/// </summary>
		TEST(HashGetDataNum, ID08_InsertTwiceNoChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_NE(Hash("A") % 2, Hash("B") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 0));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 2);
		}

		/// <summary>
		/// テスト項目　　：要素２つが内部でチェインになっていない時に一方を削除した後の戻り値
		/// 想定する戻り値：1
		/// </summary>
		TEST(HashGetDataNum, ID09_InsertTwiceAndRemoveNoChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_NE(Hash("A") % 2, Hash("B") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 0));

			// 削除
			EXPECT_TRUE(dic.Remove("A"));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// テスト項目　　：要素２つが内部でチェインになった後の戻り値
		/// 想定する戻り値：2
		/// 補足　　　　　：チェインを辿れていない場合は1が返ってくるはず。同じハッシュ値の別キーを挿入
		/// </summary>
		TEST(HashGetDataNum, ID10_InsertTwiceChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_EQ(Hash("A") % 2, Hash("C") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 0));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 2);
		}

		/// <summary>
		/// テスト項目　　：要素２つが内部でチェインになっている時に一方を削除した後の戻り値
		/// 想定する戻り値：1
		/// </summary>
		TEST(HashGetDataNum, ID11_InsertTwiceAndRemoveChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_EQ(Hash("A") % 2, Hash("C") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 0));

			// 削除
			EXPECT_TRUE(dic.Remove("A"));

			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 1);
		}
	}





	namespace HashInsertTest {

		/// <summary>
		/// テスト項目　　：リストが空である場合に、挿入した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：リストに要素が追加される
		/// </summary>
		TEST(HashInsert, ID13_InsertEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、キーが重複しないで挿入した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：リストに要素が追加される
		/// </summary>
		TEST(HashInsert, ID14_InsertMultipleNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));

			// 重複しないキーで挿入
			EXPECT_TRUE(dic.Insert("C", 2));
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、キーが重複して挿入しようとした際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// </summary>
		TEST(HashInsert, ID15_InsertMultipleContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));

			// 重複したキーで挿入
			EXPECT_FALSE(dic.Insert("A", 2));
		}

		/// <summary>
		/// テスト項目　　：既にリストにある要素とハッシュ値が同じになるキーで挿入した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：リストに要素が挿入される
		/// 補足　　　　　：チェインが内部で作成される。
		/// </summary>
		TEST(HashInsert, ID16_InsertMultipleNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_EQ(Hash("A") % 2, Hash("C") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));

			// 重複したキーで挿入
			EXPECT_FALSE(dic.Insert("A", 2));
		}

		/// <summary>
		/// テスト項目　　：一度挿入し、削除した後再度同じキーで挿入した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：リストに要素が挿入される
		/// 補足　　　　　：削除漏れとか例外処理が変に動いていないか確認
		/// </summary>
		TEST(HashInsert, ID17_InsertRemoveInsert) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));

			// 削除
			EXPECT_TRUE(dic.Remove("A"));

			// 再度挿入
			EXPECT_TRUE(dic.Insert("A", 0));
		}
	}





	namespace HashRemoveTest {

		/// <summary>
		/// テスト項目　　：リストが空である場合に、挿入した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：リストに要素が追加される
		/// </summary>
		TEST(HashRemove, ID19_InsertEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
		}
	}
}
