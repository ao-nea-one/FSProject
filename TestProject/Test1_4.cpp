#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

/*--- include ---*/
#include "../FSProject/List.h"



namespace No01_04_QuickSort {

	// �v���C���[�N���X
	struct Player {
		/*--- �����o�[�ϐ� ---*/

		int hp;
		float weight;



		/*--- �R���X�g���N�^ ---*/

		Player() = default;
		Player(int hp) : hp(hp) { };
		Player(float weight) : weight(weight) { };
		Player(int hp, float weight) : hp(hp), weight(weight) { };
	};

	auto COMP_HP_ASC = [](Player &a, Player &b) { return a.hp < b.hp; };
	auto COMP_HP_DESC = [](Player &a, Player &b) { return a.hp > b.hp; };
	auto COMP_HP_EQ = [](const Player &a, const int &b) { return a.hp == b; };
	auto COMP_WEIGHT_ASC = [](Player &a, Player &b) { return a.weight < b.weight; };
	auto COMP_WEIGHT_DESC = [](Player &a, Player &b) { return a.weight > b.weight; };
	auto COMP_WEIGHT_EQ = [](const Player &a, const float &b) { return a.weight == b; };

	/// <summary>
	/// HP�̒l�����Ԓʂ肩��r����
	/// </summary>
	/// <param name="list">���X�g</param>
	/// <param name="expectedParams">���҂���l�̔z��</param>
	/// <param name="compEQ">��v���邩��r���鎮</param>
	void CheckEQElementHP(const List<Player> &list, std::vector<int> expectedParams, std::function<bool(const Player &, const int &)> compEQ) {
		// �v�f���������łȂ��Ȃ���s���Ȃ�
		ASSERT_EQ(list.GetCount(), expectedParams.size());

		// �C�e���[�^���g�p���Ă��ׂĂ̗v�f���`�F�b�N
		auto it = list.begin();
		auto expectedIt = expectedParams.cbegin();

		while (it != list.end() && expectedIt != expectedParams.end()) {
			// �l���`�F�b�N
			ASSERT_EQ(compEQ(*it, *expectedIt), true);

			// ���̗v�f�ɐi��
			++it;
			++expectedIt;
		}
	}

	/// <summary>
	/// weight�̒l�����Ԓʂ肩��r����
	/// </summary>
	/// <param name="list">���X�g</param>
	/// <param name="expectedParams">���҂���l�̔z��</param>
	/// <param name="compEQ">��v���邩��r���鎮</param>
	void CheckEQElementWeight(const List<Player> &list, std::vector<float> expectedParams, std::function<bool(const Player &, const float &)> compEQ) {
		// �v�f���������łȂ��Ȃ���s���Ȃ�
		ASSERT_EQ(list.GetCount(), expectedParams.size());

		// �C�e���[�^���g�p���Ă��ׂĂ̗v�f���`�F�b�N
		auto it = list.begin();
		auto expectedIt = expectedParams.begin();

		while (it != list.end() && expectedIt != expectedParams.end()) {
			// �l���`�F�b�N
			ASSERT_TRUE(compEQ(*it, *expectedIt));

			// ���̗v�f�ɐi��
			++it;
			++expectedIt;
		}
	}





	/// <summary>
	/// �e�X�g���ځ@�@�F�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�G���[�܂߂āA�����N����Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID00_SortEmpty) {
		List<Player> list;

		// ��Ń\�[�g
		list.Sort(COMP_HP_ASC);
		EXPECT_EQ((list.begin() == list.end()), true);

		list.Sort(COMP_HP_DESC);
		EXPECT_EQ((list.begin() == list.end()), true);

		list.Sort(COMP_WEIGHT_ASC);
		EXPECT_EQ((list.begin() == list.end()), true);

		list.Sort(COMP_WEIGHT_DESC);
		EXPECT_EQ((list.begin() == list.end()), true);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F�v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�G���[�܂߂āA�����N����Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID01_SortOne) {
		List<Player> list;

		list.Insert(list.begin(), { 0, 0.0f });

		// 1�v�f�����Ń\�[�g
		list.Sort(COMP_HP_ASC);
		EXPECT_EQ((*list.begin()).hp, 0);

		list.Sort(COMP_HP_DESC);
		EXPECT_EQ((*list.begin()).hp, 0);

		list.Sort(COMP_WEIGHT_ASC);
		EXPECT_EQ((*list.begin()).weight, 0.0f);

		list.Sort(COMP_WEIGHT_DESC);
		EXPECT_EQ((*list.begin()).weight, 0.0f);
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ���
	/// �⑫�@�@�@�@�@�F�擪���珇�ɃC�e���[�^�Ŋm�F���A�m�[�h�̍����ւ�������ɍs���Ă��邩�`�F�b�N
	/// </summary>
	TEST(QuickSortTest, ID02_SortMultiple) {
		List<Player> list;

		list.Insert(list.end(), { 3, 2.0f });
		list.Insert(list.end(), { 1, 4.0f });
		list.Insert(list.end(), { 2, 1.0f });
		list.Insert(list.end(), { 5, 5.0f });
		list.Insert(list.end(), { 4, 3.0f });

		// �����̗v�f�Ń\�[�g
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,2,3,4,5 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 5,4,3,2,1 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,2.0f,3.0f,4.0f,5.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 5.0f,4.0f,3.0f,2.0f,1.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�v�f���\�[�g����ĕ��Ԃ��A�����v�f�̏����͕ۏ؂���Ȃ�
	/// </summary>
	TEST(QuickSortTest, ID03_SortSameElement) {
		List<Player> list;

		list.Insert(list.end(), { 3, 3.0f });
		list.Insert(list.end(), { 1, 4.0f });
		list.Insert(list.end(), { 1, 1.0f });
		list.Insert(list.end(), { 5, 5.0f });
		list.Insert(list.end(), { 4, 3.0f });

		// �����̗v�f�Ń\�[�g
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,1,3,4,5 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 5,4,3,1,1 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,3.0f,3.0f,4.0f,5.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 5.0f,4.0f,3.0f,3.0f,1.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F����ς݃��X�g�Ƀ\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ�
	/// �⑫�@�@�@�@�@�F�d���v�f�Ȃ��̐���ς݃��X�g���g��
	/// </summary>
	TEST(QuickSortTest, ID04_Resort) {
		List<Player> list;

		list.Insert(list.end(), { 1, 1.0f });
		list.Insert(list.end(), { 2, 2.0f });
		list.Insert(list.end(), { 3, 3.0f });

		// �����̗v�f�Ń\�[�g
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,2,3 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 3,2,1 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());



		// �Đ���
		list.Clear();
		list.Insert(list.end(), { 3, 3.0f });
		list.Insert(list.end(), { 2, 2.0f });
		list.Insert(list.end(), { 1, 1.0f });


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,2.0f,3.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 3.0f,2.0f,1.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());
	}

	/// <summary>
	/// �e�X�g���ځ@�@�F��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
	/// �z�肷��߂�l�F�Ȃ�
	/// �Ӑ}���錋�ʁ@�F�v�f���\�[�g����ĕ���
	/// �⑫�@�@�@�@�@�F�d���v�f�Ȃ��̐���ς݃��X�g���g��
	/// </summary>
	TEST(QuickSortTest, ID05_ResortAndInsert) {
		List<Player> list;

		list.Insert(list.end(), { 4, 3.0f });
		list.Insert(list.end(), { 2, 5.0f });
		list.Insert(list.end(), { 6, 1.0f });

		// �����̗v�f�Ń\�[�g
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 2,4,6 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 6,4,2 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,3.0f,5.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 5.0f,3.0f,1.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());






		// �ēx�}��
		list.Insert(list.end(), { 3, 4.0f });
		list.Insert(list.end(), { 5, 2.0f });
		list.Insert(list.end(), { 1, 6.0f });

		// �����̗v�f�Ń\�[�g
		list.Sort(COMP_HP_ASC);
		CheckEQElementHP(list, { 1,2,3,4,5,6 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_HP_DESC);
		CheckEQElementHP(list, { 6,5,4,3,2,1 }, COMP_HP_EQ);	// HP���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_ASC);
		CheckEQElementWeight(list, { 1.0f,2.0f,3.0f,4.0f,5.0f,6.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());


		list.Sort(COMP_WEIGHT_DESC);
		CheckEQElementWeight(list, { 6.0f,5.0f,4.0f,3.0f,2.0f,1.0f }, COMP_WEIGHT_EQ);	// weight���\�[�g����Ă��邩�`�F�b�N
		EXPECT_FALSE(HasFatalFailure());
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
		list.Sort(nullptr);
	}
}
