#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"


namespace No01_2_List {

	namespace GetDataNumTest {
		/// <summary>
		/// リストが空である場合の戻り値
		/// </summary>
		TEST(GetDataNum, ID00_Empty) {
			List<int> list;

			EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// リスト末尾への挿入を行った際の戻り値
		/// </summary>
		TEST(GetDataNum, ID01_InsertEndSuccess) {
			List<int> list;
			// 末尾への挿入（成功）
			list.Insert(list.end(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		/// <summary>
		/// リスト末尾への挿入が失敗した際の戻り値
		/// </summary>
		TEST(GetDataNum, ID02_InsertEndFailed) {

			// 失敗しないためスキップ
			
			//List<int> list;
			//// 末尾への挿入（失敗）
			//EXPECT_DEATH(list.Insert(list.end(), 0), "Assertion failed:");

			//EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// データの挿入を行った際の戻り値
		/// </summary>
		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// 挿入
			list.Insert(list.begin(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		/// <summary>
		/// データの挿入に失敗した際の戻り値
		/// </summary>
		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// イテレータが空などが理由
			// 挿入（失敗）
			list.Insert(List<int>::Iterator(), 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// データの削除を行った際の戻り値
		/// </summary>
		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// ノードの削除
			list.Remove(list.begin());


			EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// データの削除が失敗した際の戻り値
		/// </summary>
		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// イテレータが空などが理由
			// ノードの削除（失敗）
			list.Remove(List<int>::Iterator());

			EXPECT_EQ(list.GetCount(), 1);
		}

		/// <summary>
		/// リストが空である場合に、データの削除を行った際の戻り値
		/// </summary>
		TEST(GetDataNum, ID07_RemoveEmptyFailed) {
			List<int> list;
			// ノードが空で削除
			list.Remove(list.begin());

			EXPECT_EQ(list.GetCount(), 0);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// constのメソッドであるか
		/// </summary>
		TEST(GetDataNum, ID08_Const) {
			const List<int> list;

			list.GetCount();
		}
#endif
	}





	namespace InsertDataTest {

		/// <summary>
		/// リストが空である場合に、挿入した際の挙動
		/// </summary>
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

		/// <summary>
		/// リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
		/// </summary>
		TEST(InsertData, ID10_InsertBegin) {
			List<int> list;

			// リストに複数の要素がある場合
			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// 先頭に挿入
			EXPECT_EQ(list.Insert(list.begin(), 0), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
		/// </summary>
		TEST(InsertData, ID11_InsertEnd) {
			List<int> list;

			// リストに複数の要素がある場合
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 1), true);
			// 末尾に挿入
			EXPECT_EQ(list.Insert(list.end(), 2), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
		/// </summary>
		TEST(InsertData, ID12_Insert) {
			List<int> list;

			// リストに複数の要素がある場合
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// 中間に挿入
			EXPECT_EQ(list.Insert(++list.begin(), 1), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ConstIteratorを指定して挿入を行った際の挙動
		/// </summary>
		TEST(InsertData, ID13_InsertConstIterator) {
			List<int> list;

			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			EXPECT_EQ(list.Insert(list.cbegin(), 0), true);

			// 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// 不正なイテレータを渡して、挿入した場合の挙動
		/// </summary>
		TEST(InsertData, ID14_InsertNone) {
			List<int> list, other;

			// 空のイテレータで挿入（失敗）
			EXPECT_EQ(list.Insert(List<int>::Iterator(), 2), false);

			 // ほかのリストの入れテータで挿入
			EXPECT_EQ(list.Insert(other.begin(), 2), false);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// 非constのメソッドであるか
		/// </summary>
		TEST(InsertData, ID15_NoConst) {
			const List<int> list;

			list.Insert(list.begin(), 0);
		}
#endif
	}




	namespace RemoveDataTest {

		/// <summary>
		/// リストが空である場合に、削除を行った際の挙動
		/// </summary>
		TEST(RemoveData, ID16_RemoveEmpty) {
			List<int> list;
			// 空で削除
			EXPECT_EQ(list.Remove(list.begin()), false);
			EXPECT_EQ(list.Remove(list.end()), false);
		}

		/// <summary>
		/// リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
		/// </summary>
		TEST(RemoveData, ID17_RemoveBegin) {
			List<int> list;

			// リストに複数の要素がある場合
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 先頭を削除
			EXPECT_EQ(list.Remove(list.begin()), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
		/// </summary>
		TEST(RemoveData, ID18_RemoveEnd) {
			List<int> list;

			// リストに複数の要素がある場合
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 末尾を削除
			EXPECT_EQ(list.Remove(list.end()), false);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
		}

		/// <summary>
		/// リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
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
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ConstIteratorを指定して削除を行った際の挙動
		/// </summary>
		TEST(RemoveData, ID20_RemoveConstIterator) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// コンストイテレータで削除
			EXPECT_EQ(list.Remove(list.cbegin()), true);

			 // 値をチェック
			auto iter = list.begin();
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// 不正なイテレータを渡して、削除した場合の挙動
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
		TEST(RemoveData, ID21_RemoveNone) {
			List<int> list;
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 不正なイテレータで削除
			EXPECT_EQ(list.Remove(List<int>::Iterator()), false);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// 非constのメソッドであるか
		/// </summary>
		TEST(RemoveData, ID22_NoConst) {
			const List<int> list;

			list.Remove(list.begin());
		}
#endif
	}





	namespace GetBeginIteratorTest{

		/// <summary>
		/// リストが空である場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetBeginIterator, ID23_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.begin() == list.end()), true);
		}

		/// <summary>
		/// リストに要素が一つある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetBeginIterator, ID24_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.end(), 0);

			 // 値をチェック
			EXPECT_EQ(*list.begin(), 0);
		}

		/// <summary>
		/// リストに二つ以上の要素がある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetBeginIterator, ID25_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// 値をチェック
			EXPECT_EQ(*list.begin(), 0);
		}

		/// <summary>
		/// データの挿入を行った後に、呼び出した際の挙動
		/// </summary>
		TEST(GetBeginIterator, ID26_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.begin(), 0);
			EXPECT_EQ(*list.begin(), 0);

			list.Insert(list.end(), 2);
			EXPECT_EQ(*list.begin(), 0);

			list.Insert(++list.begin(), 1);
			EXPECT_EQ(*list.begin(), 0);
		}

		/// <summary>
		/// データの削除を行った後に、呼び出した際の挙動
		/// </summary>
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

#ifdef COMPILE_ERROR

		/// <summary>
		/// constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
		/// </summary>
		TEST(GetBeginIterator, ID28_GetConstIterator) {
			const List<int> list;

			auto iter = list.begin();
		}
#endif
	}





	namespace GetConstBeginIteratorTest {

		/// <summary>
		/// リストが空である場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstBeginIterator, ID29_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.cbegin() == list.cend()), true);
		}

		/// <summary>
		/// リストに要素が一つある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstBeginIterator, ID30_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.cend(), 0);

			// 値をチェック
			EXPECT_EQ(*list.cbegin(), 0);
		}

		/// <summary>
		/// リストに二つ以上の要素がある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstBeginIterator, ID31_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.cend(), 0);
			list.Insert(list.cend(), 1);

			// 値をチェック
			EXPECT_EQ(*list.cbegin(), 0);
		}

		/// <summary>
		/// データの挿入を行った後に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstBeginIterator, ID32_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.cbegin(), 0);
			EXPECT_EQ(*list.cbegin(), 0);

			list.Insert(list.cend(), 2);
			EXPECT_EQ(*list.cbegin(), 0);

			list.Insert(++list.cbegin(), 1);
			EXPECT_EQ(*list.cbegin(), 0);
		}

		/// <summary>
		/// データの削除を行った後に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstBeginIterator, ID33_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.cbegin(), 0);
			list.Insert(list.cend(), 2);
			list.Insert(++list.cbegin(), 1);

			// 削除時のイテレータ
			list.Remove(++list.cbegin());
			EXPECT_EQ(*list.cbegin(), 0);

			list.Remove(--list.cend());
			EXPECT_EQ(*list.cbegin(), 0);

			list.Remove(list.cbegin());
			EXPECT_EQ((list.cbegin() == list.cend()), true);
		}

#ifdef COMPILE_NO_ERROR

		/// <summary>
		/// constのメソッドであるか
		/// </summary>
		TEST(GetConstBeginIterator, ID34_GetConstIterator) {
			const List<int> list;

			auto iter = list.cbegin();
		}
#endif
	}





	namespace GetEndIteratorTest {

		/// <summary>
		/// リストが空である場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetEndIterator, ID35_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.end() == list.end()), true);
		}

		/// <summary>
		/// リストに要素が一つある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetEndIterator, ID36_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.end(), 0);

			// 値をチェック
			EXPECT_EQ(*(--list.end()), 0);
		}

		/// <summary>
		/// リストに二つ以上の要素がある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetEndIterator, ID37_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// 値をチェック
			EXPECT_EQ(*(--list.end()), 1);
		}

		/// <summary>
		/// データの挿入を行った後に、呼び出した際の挙動
		/// </summary>
		TEST(GetEndIterator, ID38_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.begin(), 0);
			EXPECT_EQ(*(--list.end()), 0);

			list.Insert(list.end(), 2);
			EXPECT_EQ(*(--list.end()), 2);

			list.Insert(++list.begin(), 1);
			EXPECT_EQ(*(--list.end()), 2);
		}

		/// <summary>
		/// データの削除を行った後に、呼び出した際の挙動
		/// </summary>
		TEST(GetEndIterator, ID39_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// 削除時のイテレータ
			list.Remove(++list.begin());
			EXPECT_EQ(*(--list.end()), 2);

			list.Remove(--list.end());
			EXPECT_EQ(*(--list.end()), 0);

			list.Remove(list.begin());
			EXPECT_EQ((list.end() == list.begin()), true);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
		/// </summary>
		TEST(GetEndIterator, ID40_GetConstIterator) {
			const List<int> list;

			auto iter = list.end();
		}
#endif
	}





	namespace GetConstEndIteratorTest {

		/// <summary>
		/// リストが空である場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstEndIterator, ID41_GetEmpty) {
			List<int> list;

			// 値をチェック
			EXPECT_EQ((list.cend() == list.cend()), true);
		}

		/// <summary>
		/// リストに要素が一つある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstEndIterator, ID42_GetIterator1) {
			List<int> list;

			// 要素1の場合で取得
			list.Insert(list.cend(), 0);

			// 値をチェック
			EXPECT_EQ(*(--list.cend()), 0);
		}

		/// <summary>
		/// リストに二つ以上の要素がある場合に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstEndIterator, ID43_GetIterator2) {
			List<int> list;

			// 要素複数の場合で取得
			list.Insert(list.cend(), 0);
			list.Insert(list.cend(), 1);

			// 値をチェック
			EXPECT_EQ(*(--list.cend()), 1);
		}

		/// <summary>
		/// データの挿入を行った後に、呼び出した際の挙動
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
		TEST(GetConstEndIterator, ID44_GetIteratorInsert) {
			List<int> list;

			// 挿入時のイテレータ
			list.Insert(list.cbegin(), 0);
			EXPECT_EQ(*(--list.cend()), 0);

			list.Insert(list.cend(), 2);
			EXPECT_EQ(*(--list.cend()), 2);

			list.Insert(++list.cbegin(), 1);
			EXPECT_EQ(*(--list.cend()), 2);
		}

		/// <summary>
		/// データの削除を行った後に、呼び出した際の挙動
		/// </summary>
		TEST(GetConstEndIterator, ID45_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.cbegin(), 0);
			list.Insert(list.cend(), 2);
			list.Insert(++list.cbegin(), 1);

			// 削除時のイテレータ
			list.Remove(++list.cbegin());
			EXPECT_EQ(*(--list.cend()), 2);

			list.Remove(--list.cend());
			EXPECT_EQ(*(--list.cend()), 0);

			list.Remove(list.cbegin());
			EXPECT_EQ((list.cbegin() == list.cend()), true);
		}

#ifdef COMPILE_NO_ERROR

		/// <summary>
		/// constのメソッドであるか
		/// </summary>
		TEST(GetConstBeginIterator, ID46_GetConstIterator) {
			const List<int> list;

			auto iter = list.cend();
		}
#endif
	}





	namespace UserGetIteratorTest {

		/// <summary>
		/// リストの参照がない状態で呼び出した際の挙動
		/// </summary>
		TEST(UserGetIterator, ID00_GetIteratorNone) {
#ifdef _DEBUG
			List<int>::Iterator iter;

			EXPECT_DEATH(*iter, "Assertion failed:");
#endif
		}

		/// <summary>
		/// Iteratorから取得した要素に対して、値の代入が行えるかをチェック
		/// </summary>
		TEST(UserGetIterator, ID01_SetIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// イテレータから代入
			*list.begin() = 1;

			// 値をチェック
			EXPECT_EQ(*list.begin(), 1);
		}

#ifdef COMPILE_ERROR_CHECK

		/// <summary>
		/// ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
		TEST(UserGetIterator, ID02_SetConstIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// イテレータから代入
			*list.ConstBegin() = 1;

			// 値をチェック
			EXPECT_EQ(*list.begin(), 1);
		}

#endif

		/// <summary>
		/// リストが空の際の、先頭イテレータに対して呼び出した際の挙動
		/// </summary>
		TEST(UserGetIterator, ID03_BeginIterator) {
#ifdef _DEBUG
			List<int> list;

			// 空の状態で先頭イテレータを取得（失敗）
			EXPECT_DEATH(*list.begin(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// 末尾イテレータに対して呼び出した際の挙動
		/// </summary>
		TEST(UserGetIterator, ID04_EndIterator) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.end(), 0);

			// 末尾イテレータを取得（失敗）
			EXPECT_DEATH(*list.end(), "Assertion failed:");
#endif
		}
	}





	namespace UserIncrementTest {
		
		/// <summary>
		/// リストの参照がない状態で呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID05_IncrementNone) {
#ifdef _DEBUG
			// 参照がないでインクリメント（失敗）
			EXPECT_DEATH(++List<int>::Iterator(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// リストが空の際の、先頭イテレータに対して呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID06_IncrementBegin) {
#ifdef _DEBUG
			List<int> list;

			// リストが空でインクリメント（失敗）
			EXPECT_DEATH(++list.begin(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// 末尾イテレータに対して呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID07_IncrementEnd) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// 末尾イテレータにインクリメント（失敗）
			EXPECT_DEATH(++list.end(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// リストに二つ以上の要素がある場合に呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID08_Increment) {
			List<int> list;

			// 要素が2つ以上
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 値をチェック
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(*iter, 0);
			++iter;
			EXPECT_EQ(*iter, 1);
			++iter;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// 前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
		/// </summary>
		TEST(UserIncrement, ID09_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 前置インクリメント
			// 値をチェック
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(*(++iter), 1);
			EXPECT_EQ(*(iter), 1);
			EXPECT_EQ(*(++iter), 2);
			EXPECT_EQ(*(iter), 2);
		}

		/// <summary>
		/// 後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
		/// </summary>
		TEST(UserIncrement, ID10_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 後置インクリメント
			// 値をチェック
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(0, *iter++);
			EXPECT_EQ(1, *(iter));
			EXPECT_EQ(1, *(iter++));
			EXPECT_EQ(2, *(iter));
		}
	}





	namespace UserDecrementTest {

		/// <summary>
		/// リストの参照がない状態で呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID11_DecrementNone) {
#ifdef _DEBUG
			// 参照がないでデクリメント（失敗）
			EXPECT_DEATH(--List<int>::Iterator(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// リストが空の際の、末尾イテレータに対して呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID12_DecrementEnd) {
#ifdef _DEBUG
			List<int> list;

			// リストが空でデクリメント（失敗）
			EXPECT_DEATH(--list.end(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// 先頭イテレータに対して呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID13_DecrementBegin) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// 先頭イテレータにデクリメント（失敗）
			EXPECT_DEATH(--list.begin(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// リストに二つ以上の要素がある場合に呼び出した際の挙動
		/// </summary>
		TEST(UserIncrement, ID14_Decrement) {
			List<int> list;

			// 要素が2つ以上
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 値をチェック
			List<int>::Iterator iter = list.end();
			--iter;
			EXPECT_EQ(*iter, 2);
			--iter;
			EXPECT_EQ(*iter, 1);
			--iter;
			EXPECT_EQ(*iter, 0);
		}

		/// <summary>
		/// 前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
		/// </summary>
		TEST(UserIncrement, ID15_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 前置デクリメント
			// 値をチェック
			List<int>::Iterator iter = list.end();
			--iter;
			EXPECT_EQ(*(--iter), 1);
			EXPECT_EQ(*(iter), 1);
			EXPECT_EQ(*(--iter), 0);
			EXPECT_EQ(*(iter), 0);
		}

		/// <summary>
		/// 前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
		/// </summary>
		TEST(UserIncrement, ID16_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// 後置デクリメント
			// 値をチェック
			List<int>::Iterator iter = list.end();
			iter--;
			EXPECT_EQ(*(iter--), 2);
			EXPECT_EQ(*(iter), 1);
			EXPECT_EQ(*(iter--), 1);
			EXPECT_EQ(*(iter), 0);
		}
	}





	namespace UserIteratorTest {

#ifdef COMPILE_ERROR

		/// <summary>
		/// ConstIteratorから、Iteratorのコピーが作成されないかをチェック
		/// </summary>
		TEST(UserIterator, ID17_ConstIteratorToIterator) {
			List<int> list;

			List<int>::Iterator iter = list.cbegin();
		}
#endif

		/// <summary>
		/// コピーコンストラクト後の値がコピー元と等しいことをチェック
		/// </summary>
		TEST(UserIterator, ID18_Copy) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// IteratorにConstIteratorを代入できない事をチェック
		/// </summary>
		TEST(UserIterator, ID19_ConstIteratorToIterator) {
			List<int> list;
			List<int>::Iterator iter;
			iter = list.cbegin();
		}
#endif

		/// <summary>
		/// 代入後の値がコピー元と等しいことをチェック
		/// </summary>
		TEST(UserIterator, ID20_Assin) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.begin();
			iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		/// <summary>
		/// リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
		/// </summary>
		TEST(UserIterator, ID21_Equal) {
			List<int> list;

			EXPECT_EQ((list.begin() == list.end()), true);
		}

		/// <summary>
		/// 同一のイテレータを比較した際の挙動
		/// </summary>
		TEST(UserIterator, ID22_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.begin()), true);
		}

		/// <summary>
		/// 異なるイテレータを比較した際の挙動
		/// </summary>
		TEST(UserIterator, ID23_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.end()), false);
		}

		/// <summary>
		/// リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
		/// </summary>
		TEST(UserIterator, ID24_NotEqual) {
			List<int> list;

			EXPECT_EQ((list.begin() != list.end()), false);
		}

		/// <summary>
		/// 同一のイテレータを比較した際の挙動
		/// </summary>
		TEST(UserIterator, ID25_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.begin()), false);
		}

		/// <summary>
		/// 異なるイテレータを比較した際の挙動
		/// </summary>
		TEST(UserIterator, ID26_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.end()), true);
		}
	}
}




