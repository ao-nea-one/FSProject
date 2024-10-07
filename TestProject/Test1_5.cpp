#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"

#define NO01_05_Test
#ifdef NO01_05_Test

namespace No01_05_StackAndQueue {

	namespace StackTest {

		namespace GetDataNumTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(GetDataNum, ID00_GetEmpty) {
				Stack<int> stack;

				// 要素が空の場合
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素をプッシュした後の戻り値
			/// 想定する戻り値：1
			/// </summary>
			TEST(GetDataNum, ID01_PushElement) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));

				// 要素が空の場合
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素をポップした後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(GetDataNum, ID02_Pop) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));

				// 要素をポップ
				EXPECT_EQ(stack.Pop(), 0);

				// 要素が空の場合
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素のプッシュに失敗した後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(GetDataNum, ID03_PushFailed) {
				// メモリの確保ができない場合を除き、要素のプッシュに失敗することが無いのでスキップ

				//Stack<int> stack;

				//// 要素をプッシュ
				//EXPECT_FALSE(stack.Push(0));

				//// 要素が空の場合
				//EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：プッシュを2回行った後の戻り値
			/// 想定する戻り値：2
			/// </summary>
			TEST(GetDataNum, ID04_PushTwice) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// 要素が空の場合
				EXPECT_EQ(stack.GetCount(), 2);
			}

			/// <summary>
			/// テスト項目　　：プッシュを2回行った後、１回ポップした後の戻り値
			/// 想定する戻り値：1
			/// </summary>
			TEST(GetDataNum, ID04_PushTwiceAndPop) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// 要素をポップ
				EXPECT_EQ(stack.Pop(), 1);

				// 要素が空の場合
				EXPECT_EQ(stack.GetCount(), 1);
			}

			/// <summary>
			/// テスト項目　　：リストが空である場合に、ポップを行った後の戻り値
			/// 想定する戻り値：
			/// 意図する結果　：
			/// </summary>
			TEST(GetDataNum, ID00_PopEmpty) {

			}

			/// <summary>
			/// テスト項目　　：
			/// 想定する戻り値：
			/// 意図する結果　：
			/// </summary>
			TEST(GetDataNum, ID00_) {

			}
		}
	}
}

#endif
