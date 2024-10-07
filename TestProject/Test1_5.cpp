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
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(GetDataNum, ID00_GetEmpty) {
				Stack<int> stack;

				// �v�f����̏ꍇ
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f���v�b�V��������̖߂�l
			/// �z�肷��߂�l�F1
			/// </summary>
			TEST(GetDataNum, ID01_PushElement) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));

				// �v�f����̏ꍇ
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f���|�b�v������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(GetDataNum, ID02_Pop) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));

				// �v�f���|�b�v
				EXPECT_EQ(stack.Pop(), 0);

				// �v�f����̏ꍇ
				EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f�̃v�b�V���Ɏ��s������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(GetDataNum, ID03_PushFailed) {
				// �������̊m�ۂ��ł��Ȃ��ꍇ�������A�v�f�̃v�b�V���Ɏ��s���邱�Ƃ������̂ŃX�L�b�v

				//Stack<int> stack;

				//// �v�f���v�b�V��
				//EXPECT_FALSE(stack.Push(0));

				//// �v�f����̏ꍇ
				//EXPECT_EQ(stack.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�b�V����2��s������̖߂�l
			/// �z�肷��߂�l�F2
			/// </summary>
			TEST(GetDataNum, ID04_PushTwice) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// �v�f����̏ꍇ
				EXPECT_EQ(stack.GetCount(), 2);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�b�V����2��s������A�P��|�b�v������̖߂�l
			/// �z�肷��߂�l�F1
			/// </summary>
			TEST(GetDataNum, ID04_PushTwiceAndPop) {
				Stack<int> stack;

				// �v�f���v�b�V��
				EXPECT_TRUE(stack.Push(0));
				EXPECT_TRUE(stack.Push(1));

				// �v�f���|�b�v
				EXPECT_EQ(stack.Pop(), 1);

				// �v�f����̏ꍇ
				EXPECT_EQ(stack.GetCount(), 1);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
			/// �z�肷��߂�l�F
			/// �Ӑ}���錋�ʁ@�F
			/// </summary>
			TEST(GetDataNum, ID00_PopEmpty) {

			}

			/// <summary>
			/// �e�X�g���ځ@�@�F
			/// �z�肷��߂�l�F
			/// �Ӑ}���錋�ʁ@�F
			/// </summary>
			TEST(GetDataNum, ID00_) {

			}
		}
	}
}

#endif
