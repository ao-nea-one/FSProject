#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

/*--- include ---*/
#include "../FSProject/List.h"



namespace No01_04_QuickSort {

	// プレイヤークラス
	struct Player {
		/*--- メンバー変数 ---*/

		int hp;
		float weight;



		/*--- コンストラクタ ---*/

		Player() = default;
		Player(int hp) : hp(hp) { };
		Player(float weight) : weight(weight) { };
		Player(int hp, float weight) : hp(hp), weight(weight) { };
	};

	auto COMP_HP_ASC = [](Player &a, Player &b) { return a.hp < b.hp; };
	auto COMP_HP_DESC = [](Player &a, Player &b) { return a.hp > b.hp; };
	auto COMP_HP_EQ = [](const Player &a, const int &b) { return a.hp == b; };
	auto COMP_WEIGHT_ASC = [](Player &a, Player &b) { return a.weight < b.weight; };
	auto COMP_WEIGHT_DESC = [](Player &a, Player &b) { return a.weight > b.weight; };
	auto COMP_WEIGHT_EQ = [](const Player &a, const float &b) { return a.weight == b; };

	/// <summary>
	/// HPの値が順番通りか比較する
	/// </summary>
	/// <param name="list">リスト</param>
	/// <param name="expectedParams">期待する値の配列</param>
	/// <param name="compEQ">一致するか比較する式</param>
	void CheckEQElementHP(const List<Player> &list, std::vector<int> expectedParams, std::function<bool(const Player &, const int &)> compEQ) {
		// 要素数が同じでないなら実行しない
		ASSERT_EQ(list.GetCount(), expectedParams.size());

		// イテレータを使用してすべての要素をチェック
		auto it = list.begin();
		auto expectedIt = expectedParams.cbegin();

		while (it != list.end() && expectedIt != expectedParams.end()) {
			// 値をチェック
			ASSERT_EQ(compEQ(*it, *expectedIt), true);

			// 次の要素に進む
			++it;
			++expectedIt;
		}
	}

	/// <summary>
	/// weightの値が順番通りか比較する
	/// </summary>
	/// <param name="list">リスト</param>
	/// <param name="expectedParams">期待する値の配列</param>
	/// <param name="compEQ">一致するか比較する式</param>
	void CheckEQElementWeight(const List<Player> &list, std::vector<float> expectedParams, std::function<bool(const Player &, const float &)> compEQ) {
		// 要素数が同じでないなら実行しない
		ASSERT_EQ(list.GetCount(), expectedParams.size());

		// イテレータを使用してすべての要素をチェック
		auto it = list.begin();
		auto expectedIt = expectedParams.begin();

		while (it != list.end() && expectedIt != expectedParams.end()) {
			// 値をチェック
			ASSERT_TRUE(compEQ(*it, *expectedIt));

			// 次の要素に進む
			++it;
			++expectedIt;
		}
	}





	/// <summary>
	/// テスト項目　　：要素を持たないリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：エラー含めて、何も起こらない
	/// </summary>
	TEST(QuickSortTest, ID00_SortEmpty) {
		List<Player> list;

		// 空でソート
		list.Sort(COMP_HP_ASC);
		EXPECT_EQ((list.begin() == list.end()), true);

		list.Sort(COMP_HP_DESC);
		EXPECT_EQ((list.begin() == list.end()), true);

		list.Sort(COMP_WEIGHT_ASC);
		EXPECT_EQ((list.begin() == list.end()), true);

		list.Sort(COMP_WEIGHT_DESC);
		EXPECT_EQ((list.begin() == list.end()), true);
	}

	/// <summary>
	/// テスト項目　　：要素を1つだけ持つリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：エラー含めて、何も起こらない
	/// </summary>
	TEST(QuickSortTest, ID01_SortOne) {
		List<Player> list;

		list.Insert(list.begin(), { 0, 0.0f });

		// 1要素だけでソート
		list.Sort(COMP_HP_ASC);
		EXPECT_EQ((*list.begin()).hp, 0);

		list.Sort(COMP_HP_DESC);
		EXPECT_EQ((*list.begin()).hp, 0);

		list.Sort(COMP_WEIGHT_ASC);
		EXPECT_EQ((*list.begin()).weight, 0.0f);

		list.Sort(COMP_WEIGHT_DESC);
		EXPECT_EQ((*list.begin()).weight, 0.0f);
	}

	/// <summary>
	/// テスト項目　　：2つ以上要素を持つリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：要素が指定したキーに準じて指定した順に並ぶ
	/// 補足　　　　　：先頭から順にイテレータで確認し、ノードの差し替えが正常に行えているかチェック
	/// </summary>
	TEST(QuickSortTest, ID02_SortMultiple) {
		List<Player> list;

		list.Insert(list.end(), { 3, 2.0f });
		list.Insert(list.end(), { 1, 4.0f });
		list.Insert(list.end(), { 2, 1.0f });
		list.Insert(list.end(), { 5, 5.0f });
		list.Insert(list.end(), { 4, 3.0f });

		// 複数の要素でソート
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,2,3,4,5 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 5,4,3,2,1 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,2.0f,3.0f,4.0f,5.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 5.0f,4.0f,3.0f,2.0f,1.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());
	}

	/// <summary>
	/// テスト項目　　：同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：要素がソートされて並ぶが、同じ要素の順序は保証されない
	/// </summary>
	TEST(QuickSortTest, ID03_SortSameElement) {
		List<Player> list;

		list.Insert(list.end(), { 3, 3.0f });
		list.Insert(list.end(), { 1, 4.0f });
		list.Insert(list.end(), { 1, 1.0f });
		list.Insert(list.end(), { 5, 5.0f });
		list.Insert(list.end(), { 4, 3.0f });

		// 複数の要素でソート
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,1,3,4,5 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 5,4,3,1,1 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,3.0f,3.0f,4.0f,5.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 5.0f,4.0f,3.0f,3.0f,1.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());
	}

	/// <summary>
	/// テスト項目　　：整列済みリストにソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：同じキーの要素の間以外の順番が変動しない
	/// 補足　　　　　：重複要素なしの整列済みリストを使う
	/// </summary>
	TEST(QuickSortTest, ID04_Resort) {
		List<Player> list;

		list.Insert(list.end(), { 1, 1.0f });
		list.Insert(list.end(), { 2, 2.0f });
		list.Insert(list.end(), { 3, 3.0f });

		// 複数の要素でソート
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,2,3 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 3,2,1 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());



		// 再整列
		list.Clear();
		list.Insert(list.end(), { 3, 3.0f });
		list.Insert(list.end(), { 2, 2.0f });
		list.Insert(list.end(), { 1, 1.0f });


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,2.0f,3.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 3.0f,2.0f,1.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());
	}

	/// <summary>
	/// テスト項目　　：一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動
	/// 想定する戻り値：なし
	/// 意図する結果　：要素がソートされて並ぶ
	/// 補足　　　　　：重複要素なしの整列済みリストを使う
	/// </summary>
	TEST(QuickSortTest, ID05_ResortAndInsert) {
		List<Player> list;

		list.Insert(list.end(), { 4, 3.0f });
		list.Insert(list.end(), { 2, 5.0f });
		list.Insert(list.end(), { 6, 1.0f });

		// 複数の要素でソート
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 2,4,6 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 6,4,2 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,3.0f,5.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 5.0f,3.0f,1.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());






		// 再度挿入
		list.Insert(list.end(), { 3, 4.0f });
		list.Insert(list.end(), { 5, 2.0f });
		list.Insert(list.end(), { 1, 6.0f });

		// 複数の要素でソート
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,2,3,4,5,6 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 6,5,4,3,2,1 }, COMP_HP_EQ);	// HPがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,2.0f,3.0f,4.0f,5.0f,6.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 6.0f,5.0f,4.0f,3.0f,2.0f,1.0f }, COMP_WEIGHT_EQ);	// weightがソートされているかチェック
		EXPECT_FALSE(HasFatalFailure());
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
		list.Sort(nullptr);
	}
}
