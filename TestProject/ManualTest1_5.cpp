#include "pch.h"
#include "ManualTest1_5.h"
#include <gtest/gtest.h>

/*--- include ---*/
#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"



#ifdef NO01_05_Test

#ifdef ID07_STACK_NO_COMPILE_ERROR_CHECK

	/// <summary>
	/// テスト項目　　：constのメソッドであるか
	/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとならないかをチェック。自動テスト化しなくてよい。
	/// </summary>
TEST(StackGetDataNum, ID07_Const) {
	const Stack<int> stack;

	stack.GetCount();
}

#endif



#ifdef ID10_STACK_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(StackPush, ID10_Const) {
	const Stack<int> stack;

	stack.Push(0);
}

#endif



#ifdef ID14_STACK_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(StackPush, ID14_Const) {
	const Stack<int> stack;
	int tmp;

	stack.Pop(&tmp);
}

#endif





#ifdef ID07_QUEUE_NO_COMPILE_ERROR_CHECK

	/// <summary>
	/// テスト項目　　：constのメソッドであるか
	/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとならないかをチェック。自動テスト化しなくてよい。
	/// </summary>
TEST(QueueGetDataNum, ID07_Const) {
	const Queue<int> queue;

	queue.GetCount();
}

#endif



#ifdef ID10_QUEUE_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(QueuePush, ID10_Const) {
	const Queue<int> queue;

	queue.Push(0);
}

#endif



#ifdef ID14_QUEUE_COMPILE_ERROR_CHECK

/// <summary>
/// テスト項目　　：非constのメソッドであるか
/// 補足　　　　　：constのリストから呼び出して、コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
/// </summary>
TEST(QueuePush, ID14_Const) {
	const Queue<int> queue;
	int tmp;

	queue.Pop(&tmp);
}

#endif

#endif
