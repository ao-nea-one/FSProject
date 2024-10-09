#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../StackAndQueue/Stack.h"
#include "../StackAndQueue/Queue.h"



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
				EXPECT_EQ(stack.Pop(&tmp), true);

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
			TEST(StackPop, ID13_PopTwiceMultiple) {
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






	namespace QueueTest {

		namespace QueueGetDataNumTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(QueueGetDataNum, ID00_GetEmpty) {
				Queue<int> queue;

				// �v�f�����`�F�b�N
				EXPECT_EQ(queue.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f���v�b�V��������̖߂�l
			/// �z�肷��߂�l�F1
			/// </summary>
			TEST(QueueGetDataNum, ID01_PushElement) {
				Queue<int> queue;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));

				// �v�f����̏ꍇ
				EXPECT_EQ(queue.GetCount(), 1);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f���|�b�v������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(QueueGetDataNum, ID02_Pop) {
				Queue<int> queue;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));

				// �v�f���|�b�v
				EXPECT_EQ(queue.Pop(nullptr), true);
				EXPECT_EQ(queue.Pop(&tmp), 0);

				// �v�f�����`�F�b�N
				EXPECT_EQ(queue.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�f�̃v�b�V���Ɏ��s������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(QueueGetDataNum, ID03_PushFailed) {
				// �������̊m�ۂ��ł��Ȃ��ꍇ�������A�v�f�̃v�b�V���Ɏ��s���邱�Ƃ������̂ŃX�L�b�v

				//Queue<int> queue;

				//// �v�f���v�b�V��
				//EXPECT_FALSE(queue.Push(0));

				//// �v�f�����`�F�b�N
				//EXPECT_EQ(queue.GetCount(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�b�V����2��s������̖߂�l
			/// �z�肷��߂�l�F2
			/// </summary>
			TEST(QueueGetDataNum, ID04_PushTwice) {
				Queue<int> queue;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));

				// �v�f�����`�F�b�N
				EXPECT_EQ(queue.GetCount(), 2);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F�v�b�V����2��s������A�P��|�b�v������̖߂�l
			/// �z�肷��߂�l�F1
			/// </summary>
			TEST(QueueGetDataNum, ID05_PushTwiceAndPop) {
				Queue<int> queue;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));

				// �v�f���|�b�v
				EXPECT_EQ(queue.Pop(&tmp), true);
				EXPECT_EQ(tmp, 0);

				// �v�f�����`�F�b�N
				EXPECT_EQ(queue.GetCount(), 1);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
			/// �z�肷��߂�l�F0
			/// </summary>
			TEST(QueueGetDataNum, ID06_PopEmpty) {
				Queue<int> queue;

				// ��Ń|�b�v
				queue.Pop(nullptr);

				// �v�f�����`�F�b�N
				EXPECT_EQ(queue.GetCount(), 0);
			}
		}




		namespace QueuePushTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F���X�g�̖����ɗv�f���ǉ������
			/// </summary>
			TEST(QueuePush, ID08_FirstPush) {
				Queue<int> queue;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));

				// �v�f���`�F�b�N
				EXPECT_EQ(queue.back(), 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F���X�g�̖����ɗv�f���ǉ������
			/// </summary>
			TEST(QueuePush, ID09_PushMultiple) {
				Queue<int> queue;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));

				// �v�f���`�F�b�N
				EXPECT_EQ(queue.back(), 2);
			}
		}




		namespace QueuePopTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
			/// �z�肷��߂�l�Ffalse
			/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
			/// </summary>
			TEST(QueuePop, ID11_PopEmpty) {
				Queue<int> queue;
				int tmp;

				// ��Ń|�b�v
				EXPECT_EQ(queue.Pop(&tmp), false);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F�����v�f�������o�R�œn����A���̗v�f�����X�g����폜�����
			/// </summary>
			TEST(QueuePop, ID12_PopMultiple) {
				Queue<int> queue;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));

				// �v�f���|�b�v
				EXPECT_TRUE(queue.Pop(&tmp));
				EXPECT_EQ(tmp, 0);
			}

			/// <summary>
			/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋���
			/// �z�肷��߂�l�Ftrue
			/// �Ӑ}���錋�ʁ@�F�Ō�ɒǉ������v�f���珇�Ɉ����o�R�œn�����
			/// �⑫�@�@�@�@�@�F�ǉ��������̋t���Ɏ��o����邩�`�F�b�N���A���X�g����ɂȂ�܂Ŏ��o���B
			/// </summary>
			TEST(QueuePop, ID13_PopTwiceMultiple) {
				Queue<int> queue;
				int tmp;

				// �v�f���v�b�V��
				EXPECT_TRUE(queue.Push(0));
				EXPECT_TRUE(queue.Push(1));
				EXPECT_TRUE(queue.Push(2));

				// �v�f���|�b�v
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
