#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"

#define NO01_04_Test
#ifdef NO01_04_Test

namespace No01_04_QuickSort {

	/// <summary>
	/// �e�X�g���ځ@�@�F�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�G���[�܂߂āA�����N����Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID00_SortEmpty) {
		List<int> list;

		// ��Ń\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		list.Insert(list.begin(), 0);
		list.Insert(list.begin(), 1);
		list.Insert(list.begin(), 2);
		list.Insert(list.begin(), 3);
		list.Insert(list.begin(), 4);
		list.Insert(list.begin(), 5);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F�v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�G���[�܂߂āA�����N����Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID01_SortOne) {
		List<int> list;

		list.Insert(list.begin(), 0);

		// 1�v�f�����Ń\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		EXPECT_EQ(*list.begin(), 0);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ���
	/// �⑫�@�@�@�@�@�F�擪���珇�ɃC�e���[�^�Ŋm�F���A�m�[�h�̍����ւ�������ɍs���Ă��邩�`�F�b�N
	/// </summary>
	TEST(QuickSortTest, ID02_SortMultiple) {
		List<int> list;

		list.Insert(list.end(), 3);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 2);
		list.Insert(list.end(), 5);
		list.Insert(list.end(), 4);

		// �����̗v�f�Ń\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// �l���`�F�b�N
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 4);
		EXPECT_EQ(*iter++, 5);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�v�f���\�[�g����ĕ��Ԃ��A�����v�f�̏����͕ۏ؂���Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID03_SortSameElement) {
		List<int> list;

		list.Insert(list.end(), 3);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 4);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 5);

		// �����v�f�����郊�X�g�Ń\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// �l���`�F�b�N
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 4);
		EXPECT_EQ(*iter++, 5);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F����ς݃��X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ�
	/// �⑫�@�@�@�@�@�F�d���v�f�Ȃ��̐���ς݃��X�g���g��
	/// </summary>
	TEST(QuickSortTest, ID04_Resort) {
		List<int> list;

		list.Insert(list.end(), 2);
		list.Insert(list.end(), 7);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 8);

		// 1�x�ڂ̃\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// �l���`�F�b�N
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 7);
		EXPECT_EQ(*iter++, 8);

		// ����ς݂̃��X�g�ōēx�\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// �l���`�F�b�N
		iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 7);
		EXPECT_EQ(*iter++, 8);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�v�f���\�[�g����ĕ���
	/// �⑫�@�@�@�@�@�F�d���v�f�Ȃ��̐���ς݃��X�g���g��
	/// </summary>
	TEST(QuickSortTest, ID05_ResortAndInsert) {
		List<int> list;

		list.Insert(list.end(), 5);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 3);

		// 1�x�ڂ̃\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// �l���`�F�b�N
		auto iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 5);


		// �ēx�}��
		iter = list.begin();
		list.Insert(++iter, 2);
		list.Insert(++iter, 4);
		list.Insert(++iter, 6);

		// �ēx�\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });

		// �l���`�F�b�N
		iter = list.begin();
		EXPECT_EQ(*iter++, 1);
		EXPECT_EQ(*iter++, 2);
		EXPECT_EQ(*iter++, 3);
		EXPECT_EQ(*iter++, 4);
		EXPECT_EQ(*iter++, 5);
		EXPECT_EQ(*iter++, 6);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F�L�[�w������Ȃ�����(nullptr��n����)���̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�G���[�܂߂āA�����N����Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID06_ResortAndInsert) {
		List<int> list;

		list.Insert(list.end(), 5);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 3);

		// �L�[�̎w��Ȃ��Ń\�[�g
		list.Sort(list.begin(), list.end(), nullptr);
	}

#ifdef COMPILE_ERROR

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
		list.Sort(list.begin(), list.end(), [](float &a, bool &b) { return a < b; });
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
	/// �Ӑ}���錋�ʁ@�F�R���p�C���G���[�ƂȂ�
	/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	/// </summary>
	TEST(QuickSortTest, ID07_WrongKey) {
		const List<int> list;

		list.Insert(list.end(), 5);
		list.Insert(list.end(), 1);
		list.Insert(list.end(), 3);

		// �L�[�̎w��Ȃ��Ń\�[�g
		list.Sort(list.begin(), list.end(), [](int &a, int &b) { return a < b; });
	}

#endif
}

#endif
