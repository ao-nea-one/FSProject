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

	/// <summary>
	/// �l�����݂��A���҂���l�Ɠ������`�F�b�N����
	/// </summary>
	/// <param name="dic">�n�b�V���e�[�u��</param>
	/// <param name="hasKey">�L�[�����݂��邩</param>
	/// <param name="key">�L�[</param>
	/// <param name="value">���҂���l�@�L�[���Ȃ��ꍇ -1</param>
	/// <returns>
	/// true:hasKey �� value���z�肷��l
	/// false:hasKey �� value���z�肵�Ȃ��l
	/// </returns>
	bool KeyValueCheck(const Dictionary<std::string, int, 2, Hash> &dic, bool hasKey, const std::string &key, const int& value) {
		int tmp = -1;

		return dic.Find(key, tmp) == hasKey && tmp == value;
	}

	/// <summary>
	/// �`�F�C�����̒l���`�F�b�N����
	/// </summary>
	/// <param name="list">���X�g</param>
	/// <param name="expectedParams">���҂���l</param>
	void ChainCheck(const List<Dictionary<std::string, int, 2, Hash>::Pair> &list, const std::vector<int> &expectedParams) {
		// �T�C�Y���s��v�Ȃ�I��
		ASSERT_EQ(list.GetCount(), expectedParams.size());

		int i = 0;
		for (const Dictionary<std::string, int, 2, Hash>::Pair &p : list) {
			ASSERT_EQ(p.value, expectedParams[i]);
			++i;
		}
	}





	namespace HashClassTest {

		/// <summary>
		/// �e�X�g���ځ@�@�F�Z�o���@�̈قȂ�K�؂ȃn�b�V���֐���n�����Ƃ��̂��ꂼ��̋���
		/// �⑫�@�@�@�@�@�F�}���A�����A�폜���s���A�S�Ă̖߂�l��TRUE�ɂȂ邩�`�F�b�N
		/// </summary>
		TEST(HashClass, ID01_HashFunc) {
			Dictionary<std::string, int, 2, Hash> dicA;
			Dictionary<std::string, int, 2, HashByLength> dicB;

			// �}���e�X�g
			EXPECT_TRUE(dicA.Insert("A", 0));
			EXPECT_TRUE(dicB.Insert("B", 1));

			// �v�f������
			int a = -1, b = -1;
			EXPECT_TRUE(dicA.Find("A", a));
			EXPECT_TRUE(dicB.Find("B", b));
			EXPECT_EQ(a, 0);
			EXPECT_EQ(b, 1);


			// �v�f���폜
			EXPECT_TRUE(dicA.Remove("A"));
			EXPECT_TRUE(dicB.Remove("B"));

			// �ēx����
			a = -1, b = -1;
			EXPECT_FALSE(dicA.Find("A", a));
			EXPECT_FALSE(dicB.Find("B", b));
			EXPECT_EQ(a, -1);
			EXPECT_EQ(b, -1);
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
			// �v�f�����`�F�b�N
			EXPECT_EQ(dic.GetCount(), 1);



			EXPECT_FALSE(dic.Insert("A", 1));
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
			EXPECT_NE(dic.CalcHash("A"), dic.CalcHash("B"));
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
			EXPECT_NE(dic.CalcHash("A"), dic.CalcHash("B"));
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

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));

			// �}��
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

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));

			// �}��
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

			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
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

			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, true, "B", 1));
			EXPECT_TRUE(KeyValueCheck(dic, true, "C", 2));
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

			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, true, "B", 1));
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���Ƀ��X�g�ɂ���v�f�ƃn�b�V���l�������ɂȂ�L�[�ő}�������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F���X�g�ɗv�f���}�������
		/// �⑫�@�@�@�@�@�F�`�F�C���������ō쐬�����B
		/// </summary>
		TEST(HashInsert, ID16_InsertMultipleNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0)); // �`�F�C��0
			EXPECT_TRUE(dic.Insert("C", 1)); // �`�F�C��0

			// �d�������L�[�ő}��
			EXPECT_FALSE(dic.Insert("A", 2)); // �`�F�C��0

			// �v�f�����`�F�b�N
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { 0, 1 });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());
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
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));



			// �폜
			EXPECT_TRUE(dic.Remove("A"));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, false, "A", -1));



			// �ēx�}��
			EXPECT_TRUE(dic.Insert("A", 0));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
		}
	}





	namespace HashRemoveTest {

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// </summary>
		TEST(HashRemove, ID19_RemoveEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �폜
			EXPECT_FALSE(dic.Remove("A"));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�č폜�����ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�v�f���폜�����
		/// </summary>
		TEST(HashRemove, ID20_Remove) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));



			// �폜
			EXPECT_TRUE(dic.Remove("A"));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, false, "A", -1));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�č폜���悤�Ƃ����ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// </summary>
		TEST(HashRemove, ID21_RemoveNoContainsKey) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));



			// �폜
			EXPECT_FALSE(dic.Remove("B"));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F��x�폜�����L�[�ōēx�폜���悤�Ƃ����ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// �⑫�@�@�@�@�@�F�폜�R�ꓙ�̃~�X���Ȃ����`�F�b�N
		/// </summary>
		TEST(HashRemove, ID22_RemoveTwice) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, true, "A", 0));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));



			// �폜
			EXPECT_TRUE(dic.Remove("A"));
			EXPECT_FALSE(dic.Remove("A"));
			// �v�f�����`�F�b�N
			EXPECT_TRUE(KeyValueCheck(dic, false, "A", -1));
			EXPECT_TRUE(KeyValueCheck(dic, false, "B", -1));
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�`�F�C���ɂȂ��Ă���v�f������1�̃L�[���w�肵�č폜�����ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�w�肵���v�f�������폜����A�`�F�C�����q���Ȃ������
		/// </summary>
		TEST(HashRemove, ID23_RemoveChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0)); // �`�F�C��0
			EXPECT_TRUE(dic.Insert("C", 1)); // �`�F�C��0
			EXPECT_TRUE(dic.Insert("E", 2)); // �`�F�C��0
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { 0, 1, 2 });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// �폜
			EXPECT_TRUE(dic.Remove("C")); // �`�F�C��0
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { 0, 2 });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�`�F�C���ɂȂ��Ă���v�f�ƃn�b�V���l�����������A���݂��Ȃ��L�[���w�肵�č폜�����ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// �⑫�@�@�@�@�@�F�n�b�V���l�ƃL�[�ɂ���d�������@�\���Ă��邩�`�F�b�N
		/// </summary>
		TEST(HashRemove, ID24_RemoveNoChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { 0, 1 });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// �폜
			EXPECT_FALSE(dic.Remove("E"));
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { 0, 1 });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�`�F�C���ɂȂ��Ă���v�f�����ɍ폜���Ă������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�S�Đ���ɗv�f���폜�����B
		/// �⑫�@�@�@�@�@�F�`�F�C�����O�ꂽ�肵�č폜�ł��Ȃ���ԂɂȂ�Ȃ����ǂ���
		/// </summary>
		TEST(HashRemove, ID25_RemoveAllChain) {
			Dictionary<std::string, int, 2, Hash> dic;

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			EXPECT_TRUE(dic.Insert("E", 2));
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { 0, 1, 2 });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// �폜
			EXPECT_TRUE(dic.Remove("A"));
			EXPECT_TRUE(dic.Remove("C"));
			EXPECT_TRUE(dic.Remove("E"));
			// �`�F�C��0
			ChainCheck(dic.GetChain(0), { });
			EXPECT_FALSE(HasFatalFailure());
			// �`�F�C��1
			ChainCheck(dic.GetChain(1), { });
			EXPECT_FALSE(HasFatalFailure());



			// �v�f�����m�F
			EXPECT_EQ(dic.GetCount(), 0);
		}
	}





	namespace HashFindTest {

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g����ł���ꍇ�ɁA�L�[���w�肵�Č��������ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// </summary>
		TEST(HashFind, ID27_FindEmpty) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// ����
			EXPECT_FALSE(dic.Find("A", tmp));

			// �l���`�F�b�N
			EXPECT_EQ(tmp, -1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�Č��������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�w�肵���L�[�̗v�f�������o�R�œn�����
		/// </summary>
		TEST(HashFind, ID28_FindMultiple) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// ����
			EXPECT_TRUE(dic.Find("A", tmp));

			// �l���`�F�b�N
			EXPECT_EQ(tmp, 0);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�Č��������ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// </summary>
		TEST(HashFind, ID29_FindNoContains) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// ����
			EXPECT_FALSE(dic.Find("D", tmp));

			// �l���`�F�b�N
			EXPECT_EQ(tmp, -1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���X�g�ɕ����̗v�f������ꍇ�ɁA�����L�[��2�A���Ō��������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�����v�f��2��Ƃ������o�R�œn�����
		/// �Ӑ}���錋�ʁ@�F�ςɍ폜����Ă����肵�Ȃ����`�F�b�N
		/// </summary>
		TEST(HashFind, ID30_FindNoContains) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// ���� �� �l���`�F�b�N
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);

			// ���� �� �l���`�F�b�N
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F���ɍ폜���ꂽ�L�[�Ō��������ۂ̋���
		/// �z�肷��߂�l�Ffalse
		/// �Ӑ}���錋�ʁ@�F�����N����Ȃ�
		/// �Ӑ}���錋�ʁ@�F�폜�R��Ƃ����Ȃ����`�F�b�N
		/// </summary>
		TEST(HashFind, ID31_FindRemove) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("B", 1));
			EXPECT_TRUE(dic.Insert("C", 2));

			// ���� �� �l���`�F�b�N
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);

			// �폜
			EXPECT_TRUE(dic.Remove("A"));


			// ���� �� �l���`�F�b�N
			tmp = -1;
			EXPECT_FALSE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, -1);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�`�F�C���ɂȂ��Ă���v�f�̓���1�̃L�[���w�肵�Č��������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�w�肵���L�[�̗v�f�������o�R�œn�����
		/// �Ӑ}���錋�ʁ@�F�n�b�V���l�ƃL�[�ɂ���d�������@�\���Ă��邩�`�F�b�N
		/// </summary>
		TEST(HashFind, ID32_FindRemove) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			EXPECT_TRUE(dic.Insert("E", 2));

			// ���� �� �l���`�F�b�N
			EXPECT_TRUE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, 0);

			EXPECT_TRUE(dic.Find("C", tmp));
			EXPECT_EQ(tmp, 1);

			EXPECT_TRUE(dic.Find("E", tmp));
			EXPECT_EQ(tmp, 2);
		}

		/// <summary>
		/// �e�X�g���ځ@�@�F�`�F�C���ɂȂ��Ă���v�f������1�̍폜������ɁA�c���Ă���v�f�����������ۂ̋���
		/// �z�肷��߂�l�Ftrue
		/// �Ӑ}���錋�ʁ@�F�w�肵���L�[�̗v�f�������o�R�œn�����
		/// </summary>
		TEST(HashFind, ID33_FindRemoveOther) {
			Dictionary<std::string, int, 2, Hash> dic;
			int tmp = -1;

			// �}������`�F�C���̃C���f�b�N�X���n�b�V������m�F����
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("C"));
			EXPECT_EQ(dic.CalcHash("A"), dic.CalcHash("E"));

			// �}��
			EXPECT_TRUE(dic.Insert("A", 0));
			EXPECT_TRUE(dic.Insert("C", 1));
			EXPECT_TRUE(dic.Insert("E", 2));

			// �폜
			EXPECT_TRUE(dic.Remove("A"));

			// ���� �� �l���`�F�b�N
			EXPECT_FALSE(dic.Find("A", tmp));
			EXPECT_EQ(tmp, -1);

			EXPECT_TRUE(dic.Find("C", tmp));
			EXPECT_EQ(tmp, 1);

			EXPECT_TRUE(dic.Find("E", tmp));
			EXPECT_EQ(tmp, 2);
		}
	}
}
