#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"

#define NO01_05_Test
#ifdef NO01_05_Test

namespace No01_05_StackAndQueue {

	namespace StackTest {

		namespace StackGetDataNumTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(StackGetDataNum, ID00_GetEmpty) {
				Stack<int> stack;

				// �v�f�����`�F�b�N
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f���v�b�V��������̖߂�l
			/// �z�肷��߂�l�F1
			/// </summary>
			TEST(StackGetDataNum, ID01_PushElement) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));

				// �v�f����̏ꍇ
				EXPECT_EQ(stack.GetCount(), 1);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f���|�b�v������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(StackGetDataNum, ID02_Pop) {
				Stack<int> stack;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));

				// �v�f���|�b�v
				EXPECT_EQ(stack.Pop(nullptr), true);
				EXPECT_EQ(stack.Pop(&tmp), 0);

				// �v�f�����`�F�b�N
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f�̃v�b�V���Ɏ��s������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(StackGetDataNum, ID03_PushFailed) {
				// �������̊m�ۂ��ł��Ȃ��ꍇ�������A�v�f�̃v�b�V���Ɏ��s���邱�Ƃ������̂ŃX�L�b�v

				//Stack<int> stack;

				//// �v�f���v�b�V��
				//EXPECT_FALSE(stack.Push(0));

				//// �v�f�����`�F�b�N
				//EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�b�V����2��s������̖߂�l
			/// �z�肷��߂�l�F2
			/// </summary>
			TEST(StackGetDataNum, ID04_PushTwice) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// �v�f�����`�F�b�N
				EXPECT_EQ(stack.GetCount(), 2);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�b�V����2��s������A�P��|�b�v������̖߂�l
			/// �z�肷��߂�l�F1
			/// </summary>
			TEST(StackGetDataNum, ID05_PushTwiceAndPop) {
				Stack<int> stack;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// �v�f���|�b�v
				EXPECT_EQ(stack.Pop(&tmp), true);
				EXPECT_EQ(tmp, 1);

				// �v�f�����`�F�b�N
				EXPECT_EQ(stack.GetCount(), 1);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(StackGetDataNum, ID06_PopEmpty) {
				Stack<int> stack;

				// ��Ń|�b�v
				stack.Pop(nullptr);

				// �v�f�����`�F�b�N
				EXPECT_EQ(stack.GetCount(), 0);
			}
		}




		namespace StackPushTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F���X�g�̖����ɗv�f���ǉ������
			/// </summary>
			TEST(StackPush, ID08_FirstPush) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));

				// �v�f���`�F�b�N
				EXPECT_EQ(stack.back(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F���X�g�̖����ɗv�f���ǉ������
			/// </summary>
			TEST(StackPush, ID09_PushMultiple) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));

				// �v�f���`�F�b�N
				EXPECT_EQ(stack.back(), 2);
			}
		}




		namespace StackPopTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
			/// �z�肷��߂�l�Ffalse
			/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
			/// </summary>
			TEST(StackPop, ID11_PopEmpty) {
				Stack<int> stack;
				int tmp;

				// ��Ń|�b�v
				EXPECT_EQ(stack.Pop(&tmp), false);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F�����v�f�������o�R�œn����A���̗v�f�����X�g����폜�����
			/// </summary>
			TEST(StackPop, ID12_PopMultiple) {
				Stack<int> stack;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));

				// �v�f���|�b�v
				EXPECT_TRUE(stack.Pop(&tmp));
				EXPECT_EQ(tmp, 2);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F�Ō�ɒǉ������v�f���珇�Ɉ����o�R�œn�����
			/// �⑫�@�@�@�@�@�F�ǉ��������̋t���Ɏ��o����邩�`�F�b�N���A���X�g����ɂȂ�܂Ŏ��o���B
			/// </summary>
			TEST(GetDataNum, ID13_PopTwiceMultiple) {
				Stack<int> stack;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));
				EXPECT_TRUE(stack.Push(2));

				// �v�f���|�b�v
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
}



/// <summary>
/// �e�X�g���ځ@�@�F
/// �z�肷��߂�l�F
/// �Ӑ}���錋�ʁ@�F
/// </summary>
TEST(GetDataNum, ID00_) {

}

#endif
