#include "pch.h"
#include "ManualTest1_5.h"
#include <gtest/gtest.h>

/*--- include ---*/
#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"



#ifdef NO01_05_Test

#ifdef ID07_STACK_NO_COMPILE_ERROR_CHECK

	/// <summary>
	/// �e�X�g���ځ@�@�Fconst�̃��\�b�h�ł��邩
	/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	/// </summary>
TEST(StackGetDataNum, ID07_Const) {
	const Stack<int> stack;

	stack.GetCount();
}

#endif



#ifdef ID10_STACK_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(StackPush, ID10_Const) {
	const Stack<int> stack;

	stack.Push(0);
}

#endif



#ifdef ID14_STACK_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(StackPush, ID14_Const) {
	const Stack<int> stack;
	int tmp;

	stack.Pop(&tmp);
}

#endif





#ifdef ID07_QUEUE_NO_COMPILE_ERROR_CHECK

	/// <summary>
	/// �e�X�g���ځ@�@�Fconst�̃��\�b�h�ł��邩
	/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	/// </summary>
TEST(QueueGetDataNum, ID07_Const) {
	const Queue<int> queue;

	queue.GetCount();
}

#endif



#ifdef ID10_QUEUE_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(QueuePush, ID10_Const) {
	const Queue<int> queue;

	queue.Push(0);
}

#endif



#ifdef ID14_QUEUE_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(QueuePush, ID14_Const) {
	const Queue<int> queue;
	int tmp;

	queue.Pop(&tmp);
}

#endif

#endif
