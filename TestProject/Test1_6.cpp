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

	/// <summary>
	/// 値が存在し、期待する値と同じかチェックする
	/// </summary>
	/// <param name="dic">ハッシュテーブル</param>
	/// <param name="hasKey">キーが存在するか</param>
	/// <param name="key">キー</param>
	/// <param name="value">期待する値　キーがない場合 -1</param>
	/// <returns>
	/// true:hasKey と valueが想定する値
	/// false:hasKey と valueが想定しない値
	/// </returns>
	bool KeyValueCheck(const Dictionary<std::string, int, 2, Hash> &dic, bool hasKey, const std::string &key, const int& value) {
		int tmp = -1;

		return dic.Find(key, tmp) == hasKey && tmp == value;
	}

	/// <summary>
	/// チェイン内の値をチェックする
	/// </summary>
	/// <param name="list">リスト</param>
	/// <param name="expectedParams">期待する値</param>
	void ChainCheck(const List<Dictionary<std::string, int, 2, Hash>::Pair> &list, const std::vector<int> &expectedParams) {
		// サイズが不一致なら終了
		ASSERT_EQ(list.GetCount(), expectedParams.size());

		int i = 0;
		for (const Dictionary<std::string, int, 2, Hash>::Pair &p : list) {
			ASSERT_EQ(p.value, expectedParams[i]);
			++i;
		}
	}





	namespace HashClassTest {

		/// <summary>
		/// テスト項目　　：算出方法の異なる適切なハッシュ関数を渡したときのそれぞれの挙動
		/// 補足　　　　　：挿入、検索、削除を行い、全ての戻り値がTRUEになるかチェック
		/// </summary>
		TEST(HashClass, ID01_HashFunc) {
			Dictionary<std::string, int, 2, Hash> dicA;
			Dictionary<std::string, int, 2, HashByLength> dicB;

			// 挿入テスト
			EXPECT_TRUE(dicA.Insert("A", 0));
			EXPECT_TRUE(dicB.Insert("B", 1));

			// 要素を検索
			int a = -1, b = -1;
			EXPECT_TRUE(dicA.Find("A", a));
			EXPECT_TRUE(dicB.Find("B", b));
			EXPECT_EQ(a, 0);
			EXPECT_EQ(b, 1);


			// 要素を削除
			EXPECT_TRUE(dicA.Remove("A"));
			EXPECT_TRUE(dicB.Remove("B"));

			// 再度検索
			a = -1, b = -1;
			EXPECT_FALSE(dicA.Find("A", a));
			EXPECT_FALSE(dicB.Find("B", b));
			EXPECT_EQ(a, -1);
			EXPECT_EQ(b, -1);
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
			// 要素数をチェック
			EXPECT_EQ(dic.GetCount(), 1);



			EXPECT_FALSE(dic.Insert("A", 1));
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
			EXPECT_NE(dic.CalcHash("A"), dic.CalcHash("B"));
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
			EXPECT_NE(dic.CalcHash("A"), dic.CalcHash("B"));
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

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));

			// 挿入
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

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));

			// 挿入
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

			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
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

			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, true, "B", 1));
			EXPECT_TRUE(KeyValueCheck(dic, true, "C", 2));
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

			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, true, "B", 1));
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
		}

		/// <summary>
		/// テスト項目　　：既にリストにある要素とハッシュ値が同じになるキーで挿入した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：リストに要素が挿入される
		/// 補足　　　　　：チェインが内部で作成される。
		/// </summary>
		TEST(HashInsert, ID16_InsertMultipleNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0)); // チェイン0
			EXPECT_TRUE(dic.Insert("C", 1)); // チェイン0

			// 重複したキーで挿入
			EXPECT_FALSE(dic.Insert("A", 2)); // チェイン0

			// 要素数をチェック
			// チェイン0
			ChainCheck(dic.GetChain(0), { 0, 1 });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());
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
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));



			// 削除
			EXPECT_TRUE(dic.Remove("A"));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, false, "A", -1));



			// 再度挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
		}
	}





	namespace HashRemoveTest {

		/// <summary>
		/// テスト項目　　：リストが空である場合に、挿入した際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// </summary>
		TEST(HashRemove, ID19_RemoveEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 削除
			EXPECT_FALSE(dic.Remove("A"));
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、存在するキーで指定して削除した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：要素が削除される
		/// </summary>
		TEST(HashRemove, ID20_Remove) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));



			// 削除
			EXPECT_TRUE(dic.Remove("A"));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, false, "A", -1));
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、存在しないキーで指定して削除しようとした際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// </summary>
		TEST(HashRemove, ID21_RemoveNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));



			// 削除
			EXPECT_FALSE(dic.Remove("B"));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));
		}

		/// <summary>
		/// テスト項目　　：一度削除したキーで再度削除しようとした際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// 補足　　　　　：削除漏れ等のミスがないかチェック
		/// </summary>
		TEST(HashRemove, ID22_RemoveTwice) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));



			// 削除
			EXPECT_TRUE(dic.Remove("A"));
			EXPECT_FALSE(dic.Remove("A"));
			// 要素数をチェック
			EXPECT_TRUE(KeyValueCheck(dic, false, "A", -1));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));
		}

		/// <summary>
		/// テスト項目　　：チェインになっている要素うちの1つのキーを指定して削除した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：指定した要素だけが削除され、チェインが繋ぎなおされる
		/// </summary>
		TEST(HashRemove, ID23_RemoveChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0)); // チェイン0
			EXPECT_TRUE(dic.Insert("C", 1)); // チェイン0
			EXPECT_TRUE(dic.Insert("E", 2)); // チェイン0
			// チェイン0
			ChainCheck(dic.GetChain(0), { 0, 1, 2 });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// 削除
			EXPECT_TRUE(dic.Remove("C")); // チェイン0
			// チェイン0
			ChainCheck(dic.GetChain(0), { 0, 2 });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());
		}

		/// <summary>
		/// テスト項目　　：チェインになっている要素とハッシュ値が同じだが、存在しないキーを指定して削除した際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// 補足　　　　　：ハッシュ値とキーによる二重検索が機能しているかチェック
		/// </summary>
		TEST(HashRemove, ID24_RemoveNoChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			// チェイン0
			ChainCheck(dic.GetChain(0), { 0, 1 });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// 削除
			EXPECT_FALSE(dic.Remove("E"));
			// チェイン0
			ChainCheck(dic.GetChain(0), { 0, 1 });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());
		}

		/// <summary>
		/// テスト項目　　：チェインになっている要素を順に削除していった際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：全て正常に要素が削除される。
		/// 補足　　　　　：チェインが外れたりして削除できない状態にならないかどうか
		/// </summary>
		TEST(HashRemove, ID25_RemoveAllChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			EXPECT_TRUE(dic.Insert("E", 2));
			// チェイン0
			ChainCheck(dic.GetChain(0), { 0, 1, 2 });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// 削除
			EXPECT_TRUE(dic.Remove("A"));
			EXPECT_TRUE(dic.Remove("C"));
			EXPECT_TRUE(dic.Remove("E"));
			// チェイン0
			ChainCheck(dic.GetChain(0), { });
			EXPECT_FALSE(HasFatalFailure());
			// チェイン1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// 要素数を確認
			EXPECT_EQ(dic.GetCount(), 0);
		}
	}





	namespace HashFindTest {

		/// <summary>
		/// テスト項目　　：リストが空である場合に、キーを指定して検索した際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// </summary>
		TEST(HashFind, ID27_FindEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 検索
			EXPECT_FALSE(dic.Find("A", tmp));

			// 値をチェック
			EXPECT_EQ(tmp, -1);
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、存在するキーで指定して検索した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：指定したキーの要素が引数経由で渡される
		/// </summary>
		TEST(HashFind, ID28_FindMultiple) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// 検索
			EXPECT_TRUE(dic.Find("A", tmp));

			// 値をチェック
			EXPECT_EQ(tmp, 0);
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、存在しないキーで指定して検索した際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// </summary>
		TEST(HashFind, ID29_FindNoContains) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// 検索
			EXPECT_FALSE(dic.Find("D", tmp));

			// 値をチェック
			EXPECT_EQ(tmp, -1);
		}

		/// <summary>
		/// テスト項目　　：リストに複数の要素がある場合に、同じキーで2連続で検索した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：同じ要素が2回とも引数経由で渡される
		/// 意図する結果　：変に削除されていたりしないかチェック
		/// </summary>
		TEST(HashFind, ID30_FindNoContains) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// 検索 と 値をチェック
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);

			// 検索 と 値をチェック
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);
		}

		/// <summary>
		/// テスト項目　　：既に削除されたキーで検索した際の挙動
		/// 想定する戻り値：false
		/// 意図する結果　：何も起こらない
		/// 意図する結果　：削除漏れとかがないかチェック
		/// </summary>
		TEST(HashFind, ID31_FindRemove) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// 検索 と 値をチェック
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);

			// 削除
			EXPECT_TRUE(dic.Remove("A"));


			// 検索 と 値をチェック
			tmp = -1;
			EXPECT_FALSE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, -1);
		}

		/// <summary>
		/// テスト項目　　：チェインになっている要素の内の1つのキーを指定して検索した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：指定したキーの要素が引数経由で渡される
		/// 意図する結果　：ハッシュ値とキーによる二重検索が機能しているかチェック
		/// </summary>
		TEST(HashFind, ID32_FindRemove) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			EXPECT_TRUE(dic.Insert("E", 2));

			// 検索 と 値をチェック
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);

			EXPECT_TRUE(dic.Find("C", tmp));
			EXPECT_EQ(tmp, 1);

			EXPECT_TRUE(dic.Find("E", tmp));
			EXPECT_EQ(tmp, 2);
		}

		/// <summary>
		/// テスト項目　　：チェインになっている要素うちの1つの削除した後に、残っている要素を検索した際の挙動
		/// 想定する戻り値：true
		/// 意図する結果　：指定したキーの要素が引数経由で渡される
		/// </summary>
		TEST(HashFind, ID33_FindRemoveOther) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// 挿入するチェインのインデックスをハッシュから確認する
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// 挿入
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			EXPECT_TRUE(dic.Insert("E", 2));

			// 削除
			EXPECT_TRUE(dic.Remove("A"));

			// 検索 と 値をチェック
			EXPECT_FALSE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, -1);

			EXPECT_TRUE(dic.Find("C", tmp));
			EXPECT_EQ(tmp, 1);

			EXPECT_TRUE(dic.Find("E", tmp));
			EXPECT_EQ(tmp, 2);
		}
	}
}
