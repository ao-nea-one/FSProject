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
			// ––”ö‚Ö‚Ì‘}“üi¬Œ÷j
			list.PushBack(0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID02_InsertEndFailed) {
			List<int> list;
			// ƒm[ƒh‚ª‹ó‚Ìó‘Ô‚Å‚Ì––”ö‚Ö‚Ì‘}“üi¸”sj
			List<int>::Iterator iter = list.end();
			list.Insert(iter, 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// ‘}“ü
			list.PushFront(0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// ƒm[ƒh‚ª‹ó‚Ìó‘Ô‚Å‚Ì‘}“üi¸”sj
			List<int>::Iterator iter;
			list.Insert(iter, 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			// ƒm[ƒh‚Ìíœ
			list.PopBack();

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			// ƒm[ƒh‚Ìíœ¸”s
			list.PushBack(0);
			List<int>::Iterator iter;
			list.Remove(iter);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID07_RemoveEmptyFailed) {
			List<int> list;
			// ƒm[ƒh‚ª‹ó‚Åíœ
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




