#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"



namespace No01_05_StackAndQueue {

	namespace StackTest {

		namespace StackGetDataNumTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(StackGetDataNum, ID00_GetEmpty) {
				Stack<int> stack;

				// 要素数をチェック
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素をプッシュした後の戻り値
			/// 想定する戻り値：1
			/// </summary>
			TEST(StackGetDataNum, ID01_PushElement) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));

				// 要素が空の場合
				EXPECT_EQ(stack.GetCount(), 1);
			}

			/// <summary>
			/// テスト項目　　：要素をポップした後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(StackGetDataNum, ID02_Pop) {
				Stack<int> stack;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));

				// 要素をポップ
				EXPECT_EQ(stack.Pop(&tmp), true);

				// 要素数をチェック
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素のプッシュに失敗した後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(StackGetDataNum, ID03_PushFailed) {
				// メモリの確保ができない場合を除き、要素のプッシュに失敗することが無いのでスキップ

				//Stack<int> stack;

				//// 要素をプッシュ
				//EXPECT_FALSE(stack.Push(0));

				//// 要素数をチェック
				//EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：プッシュを2回行った後の戻り値
			/// 想定する戻り値：2
			/// </summary>
			TEST(StackGetDataNum, ID04_PushTwice) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// 要素数をチェック
				EXPECT_EQ(stack.GetCount(), 2);
			}

			/// <summary>
			/// テスト項目　　：プッシュを2回行った後、１回ポップした後の戻り値
			/// 想定する戻り値：1
			/// </summary>
			TEST(StackGetDataNum, ID05_PushTwiceAndPop) {
				Stack<int> stack;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// 要素をポップ
				EXPECT_EQ(stack.Pop(&tmp), true);
				EXPECT_EQ(tmp, 1);

				// 要素数をチェック
				EXPECT_EQ(stack.GetCount(), 1);
			}

			/// <summary>
			/// テスト項目　　：リストが空である場合に、ポップを行った後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(StackGetDataNum, ID06_PopEmpty) {
				Stack<int> stack;

				// 空でポップ
				stack.Pop(nullptr);

				// 要素数をチェック
				EXPECT_EQ(stack.GetCount(), 0);
			}
		}




		namespace StackPushTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合に、プッシュした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：リストの末尾に要素が追加される
			/// </summary>
			TEST(StackPush, ID08_FirstPush) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));

				// 要素をチェック
				EXPECT_EQ(stack.back(), 0);
			}

			/// <summary>
			/// テスト項目　　：リストに複数の要素がある場合に、プッシュした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：リストの末尾に要素が追加される
			/// </summary>
			TEST(StackPush, ID09_PushMultiple) {
				Stack<int> stack;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));

				// 要素をチェック
				EXPECT_EQ(stack.back(), 2);
			}
		}




		namespace StackPopTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合に、ポップした際の挙動
			/// 想定する戻り値：false
			/// 意図する結果　：何も起こらない
			/// </summary>
			TEST(StackPop, ID11_PopEmpty) {
				Stack<int> stack;
				int tmp;

				// 空でポップ
				EXPECT_EQ(stack.Pop(&tmp), false);
			}

			/// <summary>
			/// テスト項目　　：リストに複数の要素がある場合に、ポップした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：末尾要素が引数経由で渡され、その要素がリストから削除される
			/// </summary>
			TEST(StackPop, ID12_PopMultiple) {
				Stack<int> stack;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));

				// 要素をポップ
				EXPECT_TRUE(stack.Pop(&tmp));
				EXPECT_EQ(tmp, 2);
			}

			/// <summary>
			/// テスト項目　　：リストに複数の要素がある場合に、複数回ポップした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：最後に追加した要素から順に引数経由で渡される
			/// 補足　　　　　：追加した順の逆順に取り出されるかチェックし、リストが空になるまで取り出す。
			/// </summary>
			TEST(StackPop, ID13_PopTwiceMultiple) {
				Stack<int> stack;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));

				// 要素をポップ
				EXPECT_TRUE(stack.Pop(&tmp));
				EXPECT_EQ(tmp, 2);
				EXPECT_TRUE(stack.Pop(&tmp));
				EXPECT_EQ(tmp, 1);
				EXPECT_TRUE(stack.Pop(&tmp));
				EXPECT_EQ(tmp, 0);
				EXPECT_EQ(stack.GetCount(), 0);
			}
		}
	}






	namespace QueueTest {

		namespace QueueGetDataNumTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(QueueGetDataNum, ID00_GetEmpty) {
				Queue<int> queue;

				// 要素数をチェック
				EXPECT_EQ(queue.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素をプッシュした後の戻り値
			/// 想定する戻り値：1
			/// </summary>
			TEST(QueueGetDataNum, ID01_PushElement) {
				Queue<int> queue;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));

				// 要素が空の場合
				EXPECT_EQ(queue.GetCount(), 1);
			}

			/// <summary>
			/// テスト項目　　：要素をポップした後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(QueueGetDataNum, ID02_Pop) {
				Queue<int> queue;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));

				// 要素をポップ
				EXPECT_EQ(queue.Pop(nullptr), true);
				EXPECT_EQ(queue.Pop(&tmp), 0);

				// 要素数をチェック
				EXPECT_EQ(queue.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：要素のプッシュに失敗した後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(QueueGetDataNum, ID03_PushFailed) {
				// メモリの確保ができない場合を除き、要素のプッシュに失敗することが無いのでスキップ

				//Queue<int> queue;

				//// 要素をプッシュ
				//EXPECT_FALSE(queue.Push(0));

				//// 要素数をチェック
				//EXPECT_EQ(queue.GetCount(), 0);
			}

			/// <summary>
			/// テスト項目　　：プッシュを2回行った後の戻り値
			/// 想定する戻り値：2
			/// </summary>
			TEST(QueueGetDataNum, ID04_PushTwice) {
				Queue<int> queue;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));

				// 要素数をチェック
				EXPECT_EQ(queue.GetCount(), 2);
			}

			/// <summary>
			/// テスト項目　　：プッシュを2回行った後、１回ポップした後の戻り値
			/// 想定する戻り値：1
			/// </summary>
			TEST(QueueGetDataNum, ID05_PushTwiceAndPop) {
				Queue<int> queue;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));

				// 要素をポップ
				EXPECT_EQ(queue.Pop(&tmp), true);
				EXPECT_EQ(tmp, 0);

				// 要素数をチェック
				EXPECT_EQ(queue.GetCount(), 1);
			}

			/// <summary>
			/// テスト項目　　：リストが空である場合に、ポップを行った後の戻り値
			/// 想定する戻り値：0
			/// </summary>
			TEST(QueueGetDataNum, ID06_PopEmpty) {
				Queue<int> queue;

				// 空でポップ
				queue.Pop(nullptr);

				// 要素数をチェック
				EXPECT_EQ(queue.GetCount(), 0);
			}
		}




		namespace QueuePushTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合に、プッシュした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：リストの末尾に要素が追加される
			/// </summary>
			TEST(QueuePush, ID08_FirstPush) {
				Queue<int> queue;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));

				// 要素をチェック
				EXPECT_EQ(queue.back(), 0);
			}

			/// <summary>
			/// テスト項目　　：リストに複数の要素がある場合に、プッシュした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：リストの末尾に要素が追加される
			/// </summary>
			TEST(QueuePush, ID09_PushMultiple) {
				Queue<int> queue;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));

				// 要素をチェック
				EXPECT_EQ(queue.back(), 2);
			}
		}




		namespace QueuePopTest {

			/// <summary>
			/// テスト項目　　：リストが空である場合に、ポップした際の挙動
			/// 想定する戻り値：false
			/// 意図する結果　：何も起こらない
			/// </summary>
			TEST(QueuePop, ID11_PopEmpty) {
				Queue<int> queue;
				int tmp;

				// 空でポップ
				EXPECT_EQ(queue.Pop(&tmp), false);
			}

			/// <summary>
			/// テスト項目　　：リストに複数の要素がある場合に、ポップした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：末尾要素が引数経由で渡され、その要素がリストから削除される
			/// </summary>
			TEST(QueuePop, ID12_PopMultiple) {
				Queue<int> queue;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));

				// 要素をポップ
				EXPECT_TRUE(queue.Pop(&tmp));
				EXPECT_EQ(tmp, 0);
			}

			/// <summary>
			/// テスト項目　　：リストに複数の要素がある場合に、複数回ポップした際の挙動
			/// 想定する戻り値：true
			/// 意図する結果　：最後に追加した要素から順に引数経由で渡される
			/// 補足　　　　　：追加した順の逆順に取り出されるかチェックし、リストが空になるまで取り出す。
			/// </summary>
			TEST(QueuePop, ID13_PopTwiceMultiple) {
				Queue<int> queue;
				int tmp;

				// 要素をプッシュ
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));

				// 要素をポップ
				EXPECT_TRUE(queue.Pop(&tmp));
				EXPECT_EQ(tmp, 0);
				EXPECT_TRUE(queue.Pop(&tmp));
				EXPECT_EQ(tmp, 1);
				EXPECT_TRUE(queue.Pop(&tmp));
				EXPECT_EQ(tmp, 2);
				EXPECT_EQ(queue.GetCount(), 0);
			}
		}
	}
}
