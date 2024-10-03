#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"


namespace No01_2_List {

	namespace GetDataNumTest {
		TEST(GetDataNum, ID00_Empty) {
			List<int> list;

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID01_InsertEndSuccess) {
			List<int> list;
			// 末尾への挿入（成功）
			list.Insert(list.end(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID02_InsertEndFailed) {

			// 失敗しないためスキップ
			
			//List<int> list;
			//// 末尾への挿入（失敗）
			//EXPECT_DEATH(list.Insert(list.end(), 0), "Assertion failed:");

			//EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// 挿入
			list.Insert(list.begin(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// イテレータが空などが理由
			// 挿入（失敗）
			list.Insert(List<int>::Iterator(), 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// ノードの削除
			list.Remove(list.begin());


			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// イテレータが空などが理由
			// ノードの削除（失敗）
			list.Remove(List<int>::Iterator());

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID07_RemoveEmptyFailed) {
			List<int> list;
			// ノードが空で削除
			list.Remove(list.begin());

			EXPECT_EQ(list.GetCount(), 0);
		}
	}





	namespace InsertDataTest {
		TEST(InsertData, ID09_InsertEmpty) {
			{
				List<int> list;
				// 空から挿入
				EXPECT_EQ(list.Insert(list.begin(), 0), true);
			}

			{
				List<int> list;
				// 空から挿入
				EXPECT_EQ(list.Insert(list.end(), 0), true);
			}
		}


		TEST(InsertData, ID10_InsertBegin) {
			List<int> list;

			// リストに複数の要素がある場合
			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// 先頭に挿入
			EXPECT_EQ(list.Insert(list.begin(), 0), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID11_InsertEnd) {
			List<int> list;

			// リストに複数の要素がある場合
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 1), true);
			// 末尾に挿入
			EXPECT_EQ(list.Insert(list.end(), 2), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID12_Insert) {
			List<int> list;

			// リストに複数の要素がある場合
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// 中間に挿入
			EXPECT_EQ(list.Insert(++list.begin(), 1), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID13_InsertConstIterator) {
			List<int> list;

			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			EXPECT_EQ(list.Insert(list.ConstBegin(), 0), true);

			// 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID14_InsertNone) {
			List<int> list, other;

			// 空のイテレータで挿入（失敗）
			EXPECT_EQ(list.Insert(List<int>::Iterator(), 2), false);

			 // ほかのリストの入れテータで挿入
			EXPECT_EQ(list.Insert(other.begin(), 2), false);
		}
	}




	namespace RemoveDataTest {
		TEST(RemoveData, ID16_RemoveEmpty) {
			List<int> list;
			// 空で削除
			EXPECT_EQ(list.Remove(list.begin()), false);
			EXPECT_EQ(list.Remove(list.end()), false);
		}

		TEST(RemoveData, ID17_RemoveBegin) {
			List<int> list;

			// リストに複数の要素がある場合
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 1);
			list.Insert(++list.begin(), 1);

			// 先頭を削除
			EXPECT_EQ(list.Remove(list.begin()), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(RemoveData, ID18_RemoveEnd) {
			List<int> list;

			// リストに複数の要素がある場合
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 1);
			list.Insert(++list.begin(), 1);

			// 末尾を削除
			EXPECT_EQ(list.Remove(list.end()), false);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
		}

		TEST(RemoveData, ID19_Remove) {
			List<int> list;

			// リストに複数の要素がある場合
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 中間を削除
			EXPECT_EQ(list.Remove(++list.begin()), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
		}

		TEST(RemoveData, ID20_RemoveConstIterator) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// コンストイテレータで削除
			EXPECT_EQ(list.Remove(list.ConstBegin()), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(RemoveData, ID21_RemoveNone) {
			List<int> list;
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 不正なイテレータで削除
			EXPECT_EQ(list.Remove(List<int>::Iterator()), false);
		}
	}





	namespace GetBeginIteratorTest{
		TEST(GetBeginIterator, ID23_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.begin() == list.end()), true);
		}

		TEST(GetBeginIterator, ID24_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.end(), 0);

			 // 値をチェック
			EXPECT_EQ(*list.begin(), 0);
		}

		TEST(GetBeginIterator, ID25_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// 値をチェック
			EXPECT_EQ(*list.begin(), 0);
		}

		TEST(GetBeginIterator, ID26_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.begin(), 0);
			EXPECT_EQ(*list.begin(), 0);

			list.Insert(list.begin(), 1);
			EXPECT_EQ(*list.begin(), 1);

			list.Insert(list.begin(), 2);
			EXPECT_EQ(*list.begin(), 2);
		}

		TEST(GetBeginIterator, ID27_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 削除時のイテレータ
			list.Remove(++list.begin());
			EXPECT_EQ(*list.begin(), 0);

			list.Remove(--list.end());
			EXPECT_EQ(*list.begin(), 0);

			list.Remove(list.begin());
			EXPECT_EQ((list.begin() == list.end()), true);
		}
	}





	namespace GetConstBeginIteratorTest {
		TEST(GetConstBeginIterator, ID29_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.ConstBegin() == list.ConstEnd()), true);
		}

		TEST(GetConstBeginIterator, ID30_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.ConstEnd(), 0);

			// 値をチェック
			EXPECT_EQ(*list.ConstBegin(), 0);
		}

		TEST(GetConstBeginIterator, ID31_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.ConstEnd(), 0);
			list.Insert(list.ConstEnd(), 1);

			// 値をチェック
			EXPECT_EQ(*list.ConstBegin(), 0);
		}

		TEST(GetConstBeginIterator, ID32_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.ConstBegin(), 0);
			EXPECT_EQ(*list.ConstBegin(), 0);

			list.Insert(list.ConstBegin(), 1);
			EXPECT_EQ(*list.ConstBegin(), 1);

			list.Insert(list.ConstBegin(), 2);
			EXPECT_EQ(*list.ConstBegin(), 2);
		}

		TEST(GetConstBeginIterator, ID33_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.ConstBegin(), 0);
			list.Insert(list.ConstEnd(), 2);
			list.Insert(++list.ConstBegin(), 1);

			// 削除時のイテレータ
			list.Remove(++list.ConstBegin());
			EXPECT_EQ(*list.ConstBegin(), 0);

			list.Remove(--list.ConstEnd());
			EXPECT_EQ(*list.ConstBegin(), 0);

			list.Remove(list.ConstBegin());
			EXPECT_EQ((list.ConstBegin() == list.ConstEnd()), true);
		}
	}





	namespace GetEndIteratorTest {
		TEST(GetEndIterator, ID35_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.end() == list.end()), true);
		}

		TEST(GetEndIterator, ID36_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.end(), 0);

			// 値をチェック
			EXPECT_EQ(*--list.end(), 0);
		}

		TEST(GetEndIterator, ID37_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// 値をチェック
			EXPECT_EQ(*list.end(), 0);
		}

		TEST(GetEndIterator, ID38_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.end(), 0);
			EXPECT_EQ(*list.end(), 0);

			list.Insert(list.end(), 1);
			EXPECT_EQ(*list.end(), 1);

			list.Insert(list.end(), 2);
			EXPECT_EQ(*list.end(), 2);
		}

		TEST(GetEndIterator, ID39_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(++list.end(), 2);

			// 削除時のイテレータ
			list.Remove(++list.end());
			EXPECT_EQ(*list.end(), 0);

			list.Remove(list.end());
			EXPECT_EQ(*list.end(), 0);

			list.Remove(list.end());
			EXPECT_EQ((list.end() == list.end()), true);
		}
	}





	namespace GetConstEndIteratorTest {
		TEST(GetConstEndIterator, ID41_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.ConstEnd() == list.ConstEnd()), true);
		}

		TEST(GetConstEndIterator, ID42_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.ConstEnd(), 0);

			// 値をチェック
			EXPECT_EQ(*list.ConstEnd(), 0);
		}

		TEST(GetConstEndIterator, ID43_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.ConstEnd(), 0);
			list.Insert(list.ConstEnd(), 1);

			// 値をチェック
			EXPECT_EQ(*list.ConstEnd(), 0);
		}

		TEST(GetConstEndIterator, ID44_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.ConstEnd(), 0);
			EXPECT_EQ(*list.ConstEnd(), 0);

			list.Insert(list.ConstEnd(), 1);
			EXPECT_EQ(*list.ConstEnd(), 1);

			list.Insert(list.ConstEnd(), 2);
			EXPECT_EQ(*list.ConstEnd(), 2);
		}

		TEST(GetConstEndIterator, ID45_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.ConstEnd(), 0);
			list.Insert(list.ConstEnd(), 1);
			list.Insert(++list.ConstEnd(), 2);

			// 削除時のイテレータ
			list.Remove(++list.ConstEnd());
			EXPECT_EQ(*list.ConstEnd(), 0);

			list.Remove(list.ConstEnd());
			EXPECT_EQ(*list.ConstEnd(), 0);

			list.Remove(list.ConstEnd());
			EXPECT_EQ((list.ConstBegin() == list.ConstEnd()), true);
		}
	}





	namespace UserGetIteratorTest {
		TEST(UserGetIterator, ID00_GetIteratorNone) {
#ifdef _DEBUG
			List<int>::Iterator iter;

			EXPECT_DEATH(*iter, "Assertion failed:");
#endif
		}

		TEST(UserGetIterator, ID01_SetIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// イテレータから代入
			*list.begin() = 1;

			// 値をチェック
			EXPECT_EQ(*list.begin(), 1);
		}

#ifdef COMPILE_ERROR_CHECK

		TEST(UserGetIterator, ID02_SetConstIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// イテレータから代入
			*list.ConstBegin() = 1;

			// 値をチェック
			EXPECT_EQ(*list.begin(), 1);
		}

#endif

		TEST(UserGetIterator, ID03_BeginIterator) {
#ifdef _DEBUG
			List<int> list;

			// 空の状態で先頭イテレータを取得（失敗）
			EXPECT_DEATH(*list.begin(), "Assertion failed:");
#endif
		}

		TEST(UserGetIterator, ID04_EndIterator) {
#ifdef _DEBUG
			List<int> list;

			// 末尾イテレータを取得（失敗）
			EXPECT_DEATH(*list.end(), "Assertion failed:");
#endif
		}
	}





	namespace UserIncrementTest {
		TEST(UserIncrement, ID05_IncrementNone) {
#ifdef _DEBUG
			// 参照がないでインクリメント（失敗）
			EXPECT_DEATH(++List<int>::Iterator(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID06_IncrementBegin) {
#ifdef _DEBUG
			List<int> list;

			// リストが空でインクリメント（失敗）
			EXPECT_DEATH(++list.begin(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID07_IncrementEnd) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// 末尾イテレータにインクリメント（失敗）
			EXPECT_DEATH(++list.end(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID08_Increment) {
			List<int> list;

			// 要素が2つ以上
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 値をチェック
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(++(*iter), 0);
			EXPECT_EQ(++(*iter), 1);
			EXPECT_EQ(++(*iter), 2);
		}

		TEST(UserIncrement, ID09_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 前置インクリメント
			// 値をチェック
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(++(*iter), 0);
			EXPECT_EQ(++(*iter), 1);
			EXPECT_EQ(++(*iter), 2);
		}

		TEST(UserIncrement, ID10_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 後置インクリメント
			// 値をチェック
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}
	}





	namespace UserDecrementTest {
		TEST(UserIncrement, ID11_DecrementNone) {
#ifdef _DEBUG
			// 参照がないでデクリメント（失敗）
			EXPECT_DEATH(--List<int>::Iterator(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID12_DecrementBegin) {
#ifdef _DEBUG
			List<int> list;

			// リストが空でデクリメント（失敗）
			EXPECT_DEATH(--list.end(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID13_DecrementEnd) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// 先頭イテレータにデクリメント（失敗）
			EXPECT_DEATH(--list.begin(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID14_Decrement) {
			List<int> list;

			// 要素が2つ以上
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 値をチェック
			List<int>::Iterator iter = list.end();
			--iter;
			EXPECT_EQ(--(*iter), 0);
			EXPECT_EQ(--(*iter), 1);
			EXPECT_EQ(--(*iter), 2);
		}

		TEST(UserIncrement, ID15_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 前置インクリメント
			// 値をチェック
			List<int>::Iterator iter = list.begin();
			--iter;
			EXPECT_EQ(--(*iter), 0);
			EXPECT_EQ(--(*iter), 1);
			EXPECT_EQ(--(*iter), 2);
		}

		TEST(UserIncrement, ID16_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 後置インクリメント
			// 値をチェック
			List<int>::Iterator iter = list.begin();
			--iter;
			EXPECT_EQ((*iter)--, 0);
			EXPECT_EQ((*iter)--, 1);
			EXPECT_EQ((*iter)--, 2);
		}
	}





	namespace UserIteratorTest {
		TEST(UserIterator, ID18_Copy) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		TEST(UserIterator, ID20_Assin) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.begin();
			iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		TEST(UserIterator, ID21_Equal) {
			List<int> list;

			EXPECT_EQ((list.begin() == list.end()), true);
		}

		TEST(UserIterator, ID22_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.begin()), true);
		}

		TEST(UserIterator, ID23_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.end()), false);
		}

		TEST(UserIterator, ID24_NotEqual) {
			List<int> list;

			EXPECT_EQ((list.begin() != list.end()), false);
		}

		TEST(UserIterator, ID25_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.begin()), false);
		}

		TEST(UserIterator, ID26_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.end()), true);
		}
	}
}




