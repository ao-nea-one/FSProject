#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../Hash/Dictionary.h"



namespace No01_06_Hash {

	/// <summary>
	/// �n�b�V���֐�
	/// </summary>
	/// <param name="key">�L�[</param>
	/// <returns>�l</returns>
	size_t Hash(const std::string &key) {
		return std::hash<std::string>()(key);
	}

	/// <summary>
	/// �n�b�V���֐�
	/// </summary>
	/// <param name="key">�L�[</param>
	/// <returns>�l</returns>
	size_t HashByLength(const std::string &key) {
		return key.size();
	}





	namespace HashClassTest {

		namespace HashClassTest {

			/// <summary>
			/// �e�X�g���ځ@�@�F�Z�o���@�̈قȂ�K�؂ȃn�b�V���֐���n�����Ƃ��̂��ꂼ��̋���
			/// �⑫�@�@�@�@�@�F�}���A�����A�폜���s���A�S�Ă̖߂�l��TRUE�ɂȂ邩�`�F�b�N
			/// </summary>
			TEST(StackGetDataNum, ID01_GetEmpty) {
				Dictionary<std::string, int, 2, Hash> dicA;
				Dictionary<std::string, int, 2, HashByLength> dicB;

				// �}���e�X�g
				EXPECT_TRUE(dicA.Insert("A", 0));
				EXPECT_TRUE(dicB.Insert("B", 1));

				// �v�f������
				int a = -1, b = -1;
				EXPECT_TRUE(dicA.Find("A", a));
				EXPECT_TRUE(dicB.Find("B", b));

				// �v�f���폜
				EXPECT_TRUE(dicA.Remove("A"));
				EXPECT_TRUE(dicB.Remove("B"));
			}
		}
	}





	namespace HashGetDataNumTest {

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�̖߂�l
		/// �z�肷��߂�l�F0
		/// </summary>
		TEST(HashGetDataNum, ID02_GetEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 0);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�v�f��}��������̖߂�l
		/// �z�肷��߂�l�F1
		/// </summary>
		TEST(HashGetDataNum, ID03_Insert) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�v�f��}�����A���̃L�[�ō폜������̖߂�l
		/// �z�肷��߂�l�F0
		/// </summary>
		TEST(HashGetDataNum, ID04_InsertAndRemove) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));

			// �폜
			EXPECT_TRUE(dic.Remove("A"));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 0);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���ɑ��݂���L�[�ŗv�f�̑}���������s������̖߂�l
		/// �z�肷��߂�l�F1
		/// �⑫�@�@�@�@�@�F�P��}��������A���̃L�[�ōēx�}������
		/// </summary>
		TEST(HashGetDataNum, ID05_InsertTwice) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_FALSE(dic.Insert("A", 0));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɗv�f�����鎞�ɑ��݂��Ȃ��L�[���w�肵�v�f�̍폜�Ɏ��s�����ۂ̖߂�l
		/// �z�肷��߂�l�F1
		/// �⑫�@�@�@�@�@�F�P��}��������A�قȂ�L�[�ō폜����
		/// </summary>
		TEST(HashGetDataNum, ID06_InsertAndNoneRemove) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));

			// �폜
			EXPECT_FALSE(dic.Remove("B"));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�폜���s������̖߂�l
		/// �z�肷��߂�l�F0
		/// </summary>
		TEST(HashGetDataNum, ID07_RemoveEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �폜
			EXPECT_FALSE(dic.Remove("A"));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 0);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����̖߂�l
		/// �z�肷��߂�l�F2
		/// �⑫�@�@�@�@�@�F�`�F�C���ɂ���ėv�f���������ω����Ȃ����Ƃ��`�F�b�N
		/// </summary>
		TEST(HashGetDataNum, ID08_InsertTwiceNoChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_NE(Hash("A") % 2, Hash("B") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 0));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 2);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����Ɉ�����폜������̖߂�l
		/// �z�肷��߂�l�F1
		/// </summary>
		TEST(HashGetDataNum, ID09_InsertTwiceAndRemoveNoChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_NE(Hash("A") % 2, Hash("B") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 0));

			// �폜
			EXPECT_TRUE(dic.Remove("A"));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�v�f�Q�������Ń`�F�C���ɂȂ�����̖߂�l
		/// �z�肷��߂�l�F2
		/// �⑫�@�@�@�@�@�F�`�F�C����H��Ă��Ȃ��ꍇ��1���Ԃ��Ă���͂��B�����n�b�V���l�̕ʃL�[��}��
		/// </summary>
		TEST(HashGetDataNum, ID10_InsertTwiceChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_EQ(Hash("A") % 2, Hash("C") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 0));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 2);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�v�f�Q�������Ń`�F�C���ɂȂ��Ă��鎞�Ɉ�����폜������̖߂�l
		/// �z�肷��߂�l�F1
		/// </summary>
		TEST(HashGetDataNum, ID11_InsertTwiceAndRemoveChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_EQ(Hash("A") % 2, Hash("C") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 0));

			// �폜
			EXPECT_TRUE(dic.Remove("A"));

			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 1);
		}
	}





	namespace HashInsertTest {

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F���X�g�ɗv�f���ǉ������
		/// </summary>
		TEST(HashInsert, ID13_InsertEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����Ȃ��ő}�������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F���X�g�ɗv�f���ǉ������
		/// </summary>
		TEST(HashInsert, ID14_InsertMultipleNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));

			// �d�����Ȃ��L�[�ő}��
			EXPECT_TRUE(dic.Insert("C", 2));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����đ}�����悤�Ƃ����ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// </summary>
		TEST(HashInsert, ID15_InsertMultipleContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));

			// �d�������L�[�ő}��
			EXPECT_FALSE(dic.Insert("A", 2));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���Ƀ��X�g�ɂ���v�f�ƃn�b�V���l�������ɂȂ�L�[�ő}�������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F���X�g�ɗv�f���}�������
		/// �⑫�@�@�@�@�@�F�`�F�C���������ō쐬�����B
		/// </summary>
		TEST(HashInsert, ID16_InsertMultipleNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_EQ(Hash("A") % 2, Hash("C") % 2);
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));

			// �d�������L�[�ő}��
			EXPECT_FALSE(dic.Insert("A", 2));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F��x�}�����A�폜������ēx�����L�[�ő}�������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F���X�g�ɗv�f���}�������
		/// �⑫�@�@�@�@�@�F�폜�R��Ƃ���O�������ςɓ����Ă��Ȃ����m�F
		/// </summary>
		TEST(HashInsert, ID17_InsertRemoveInsert) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));

			// �폜
			EXPECT_TRUE(dic.Remove("A"));

			// �ēx�}��
			EXPECT_TRUE(dic.Insert("A", 0));
		}
	}





	namespace HashRemoveTest {

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F���X�g�ɗv�f���ǉ������
		/// </summary>
		TEST(HashRemove, ID19_InsertEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
		}
	}
}
