#include "pch.h"
#include <gtest/gtest.h>

#include "../FSProject/ScoreManager.h"


namespace No01_2_List {
	namespace GetDataNumTest {
		TEST(GetDataNum, ID00_Empty) {
			List<int> list;

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID01_InsertEndSuccess) {
			List<int> list;
			// 末尾への挿入（成功）
			list.PushBack(0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID02_InsertEndFailed) {
			List<int> list;
			// ノードが空の状態での末尾への挿入（失敗）
			List<int>::Iterator iter = list.end();
			list.Insert(iter, 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// 挿入
			list.PushFront(0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// ノードが空の状態での挿入（失敗）
			List<int>::Iterator iter;
			list.Insert(iter, 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			// ノードの削除
			list.PopBack();

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			// ノードの削除失敗
			list.PushBack(0);
			List<int>::Iterator iter;
			list.Remove(iter);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID07_RemoveEmptyFailed) {
			List<int> list;
			// ノードが空で削除
			List<int>::Iterator iter;
			list.Remove(iter);

			EXPECT_EQ(list.GetCount(), 0);
		}
	}




	namespace InsertDataTest {
		TEST(InsertData, ID09_InsertEmpty) {
			List<int> list;

			list.PushBack(0);
		}

		TEST(InsertData, ID10_InsertBegin) {
			List<int> list;

			list.PushBack(0);
			list.PushBack(1);
			list.Insert(list.begin(), 2);
		}

		TEST(InsertData, ID11_InsertEnd) {
			List<int> list;

			list.PushBack(0);
			list.PushBack(1);
			list.Insert(list.end(), 2);
		}

		TEST(InsertData, ID12_Insert) {
			List<int> list;

			list.PushBack(0);
			list.PushBack(1);
			List<int>::Iterator iter = list.begin();
			list.Insert(++iter, 2);
		}
	}
}




