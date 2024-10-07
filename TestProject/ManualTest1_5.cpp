#include "pch.h"
#include "ManualTest1_5.h"
#include <gtest/gtest.h>

/*--- include ---*/
#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"



#ifdef NO01_05_Test

#ifdef ID07_STACK_COMPILE_ERROR_CHECK

	/// <summary>
	/// �e�X�g���ځ@�@�F�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋���
	/// �Ӑ}���錋�ʁ@�F�R���p�C���G���[�ƂȂ�
	/// �⑫�@�@�@�@�@�F�R���p�C���G���[���`�F�b�N�B�����e�X�g�����Ȃ�
	/// </summary>
TEST(QuickSortTest, ID07_WrongKey) {
	List<int> list;

	list.Insert(list.end(), 5);
	list.Insert(list.end(), 1);
	list.Insert(list.end(), 3);

	// �L�[�̎w��Ȃ��Ń\�[�g
}

#endif



#ifdef ID10_STACK_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �Ӑ}���錋�ʁ@�F�R���p�C���G���[�ƂȂ�
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(QuickSortTest, ID08_Const) {
	const List<int> list;

}

#endif

#endif
