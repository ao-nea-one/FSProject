#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"


namespace No01_2_List {

	namespace GetDataNumTest {
		TEST(GetDataNum, ID00_Empty) {
			List<int> list;

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID01_InsertEndSuccess) {
			List<int> list;
			// �����ւ̑}���i�����j
			list.Insert(list.end(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID02_InsertEndFailed) {

			// ���s���Ȃ����߃X�L�b�v
			
			//List<int> list;
			//// �����ւ̑}���i���s�j
			//EXPECT_DEATH(list.Insert(list.end(), 0), "Assertion failed:");

			//EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// �}��
			list.Insert(list.begin(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// �C�e���[�^����Ȃǂ����R
			// �}���i���s�j
			list.Insert(List<int>::Iterator(), 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// �m�[�h�̍폜
			list.Remove(list.begin());


			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// �C�e���[�^����Ȃǂ����R
			// �m�[�h�̍폜�i���s�j
			list.Remove(List<int>::Iterator());

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID07_RemoveEmptyFailed) {
			List<int> list;
			// �m�[�h����ō폜
			list.Remove(list.begin());

			EXPECT_EQ(list.GetCount(), 0);
		}
	}





	namespace InsertDataTest {
		TEST(InsertData, ID09_InsertEmpty) {
			{
				List<int> list;
				// �󂩂�}��
				EXPECT_EQ(list.Insert(list.begin(), 0), true);
			}

			{
				List<int> list;
				// �󂩂�}��
				EXPECT_EQ(list.Insert(list.end(), 0), true);
			}
		}


		TEST(InsertData, ID10_InsertBegin) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// �擪�ɑ}��
			EXPECT_EQ(list.Insert(list.begin(), 0), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID11_InsertEnd) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 1), true);
			// �����ɑ}��
			EXPECT_EQ(list.Insert(list.end(), 2), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID12_Insert) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// ���Ԃɑ}��
			EXPECT_EQ(list.Insert(++list.begin(), 1), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID13_InsertConstIterator) {
			List<int> list;

			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			EXPECT_EQ(list.Insert(list.ConstBegin(), 0), true);

			// �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(InsertData, ID14_InsertNone) {
			List<int> list, other;

			// ��̃C�e���[�^�ő}���i���s�j
			EXPECT_EQ(list.Insert(List<int>::Iterator(), 2), false);

			 // �ق��̃��X�g�̓���e�[�^�ő}��
			EXPECT_EQ(list.Insert(other.begin(), 2), false);
		}
	}




	namespace RemoveDataTest {
		TEST(RemoveData, ID16_RemoveEmpty) {
			List<int> list;
			// ��ō폜
			EXPECT_EQ(list.Remove(list.begin()), false);
			EXPECT_EQ(list.Remove(list.end()), false);
		}

		TEST(RemoveData, ID17_RemoveBegin) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 1);
			list.Insert(++list.begin(), 1);

			// �擪���폜
			EXPECT_EQ(list.Remove(list.begin()), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(RemoveData, ID18_RemoveEnd) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 1);
			list.Insert(++list.begin(), 1);

			// �������폜
			EXPECT_EQ(list.Remove(list.end()), false);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
		}

		TEST(RemoveData, ID19_Remove) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// ���Ԃ��폜
			EXPECT_EQ(list.Remove(++list.begin()), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
		}

		TEST(RemoveData, ID20_RemoveConstIterator) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �R���X�g�C�e���[�^�ō폜
			EXPECT_EQ(list.Remove(list.ConstBegin()), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}

		TEST(RemoveData, ID21_RemoveNone) {
			List<int> list;
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �s���ȃC�e���[�^�ō폜
			EXPECT_EQ(list.Remove(List<int>::Iterator()), false);
		}
	}





	namespace GetBeginIteratorTest{
		TEST(GetBeginIterator, ID23_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.begin() == list.end()), true);
		}

		TEST(GetBeginIterator, ID24_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);

			 // �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 0);
		}

		TEST(GetBeginIterator, ID25_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 0);
		}

		TEST(GetBeginIterator, ID26_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.begin(), 0);
			EXPECT_EQ(*list.begin(), 0);

			list.Insert(list.begin(), 1);
			EXPECT_EQ(*list.begin(), 1);

			list.Insert(list.begin(), 2);
			EXPECT_EQ(*list.begin(), 2);
		}

		TEST(GetBeginIterator, ID27_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �폜���̃C�e���[�^
			list.Remove(++list.begin());
			EXPECT_EQ(*list.begin(), 0);

			list.Remove(--list.end());
			EXPECT_EQ(*list.begin(), 0);

			list.Remove(list.begin());
			EXPECT_EQ((list.begin() == list.end()), true);
		}
	}





	namespace GetConstBeginIteratorTest {
		TEST(GetConstBeginIterator, ID29_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.ConstBegin() == list.ConstEnd()), true);
		}

		TEST(GetConstBeginIterator, ID30_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.ConstEnd(), 0);

			// �l���`�F�b�N
			EXPECT_EQ(*list.ConstBegin(), 0);
		}

		TEST(GetConstBeginIterator, ID31_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.ConstEnd(), 0);
			list.Insert(list.ConstEnd(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*list.ConstBegin(), 0);
		}

		TEST(GetConstBeginIterator, ID32_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.ConstBegin(), 0);
			EXPECT_EQ(*list.ConstBegin(), 0);

			list.Insert(list.ConstBegin(), 1);
			EXPECT_EQ(*list.ConstBegin(), 1);

			list.Insert(list.ConstBegin(), 2);
			EXPECT_EQ(*list.ConstBegin(), 2);
		}

		TEST(GetConstBeginIterator, ID33_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.ConstBegin(), 0);
			list.Insert(list.ConstEnd(), 2);
			list.Insert(++list.ConstBegin(), 1);

			// �폜���̃C�e���[�^
			list.Remove(++list.ConstBegin());
			EXPECT_EQ(*list.ConstBegin(), 0);

			list.Remove(--list.ConstEnd());
			EXPECT_EQ(*list.ConstBegin(), 0);

			list.Remove(list.ConstBegin());
			EXPECT_EQ((list.ConstBegin() == list.ConstEnd()), true);
		}
	}





	namespace GetEndIteratorTest {
		TEST(GetEndIterator, ID35_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.end() == list.end()), true);
		}

		TEST(GetEndIterator, ID36_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);

			// �l���`�F�b�N
			EXPECT_EQ(*--list.end(), 0);
		}

		TEST(GetEndIterator, ID37_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*list.end(), 0);
		}

		TEST(GetEndIterator, ID38_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.end(), 0);
			EXPECT_EQ(*list.end(), 0);

			list.Insert(list.end(), 1);
			EXPECT_EQ(*list.end(), 1);

			list.Insert(list.end(), 2);
			EXPECT_EQ(*list.end(), 2);
		}

		TEST(GetEndIterator, ID39_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(++list.end(), 2);

			// �폜���̃C�e���[�^
			list.Remove(++list.end());
			EXPECT_EQ(*list.end(), 0);

			list.Remove(list.end());
			EXPECT_EQ(*list.end(), 0);

			list.Remove(list.end());
			EXPECT_EQ((list.end() == list.end()), true);
		}
	}





	namespace GetConstEndIteratorTest {
		TEST(GetConstEndIterator, ID41_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.ConstEnd() == list.ConstEnd()), true);
		}

		TEST(GetConstEndIterator, ID42_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.ConstEnd(), 0);

			// �l���`�F�b�N
			EXPECT_EQ(*list.ConstEnd(), 0);
		}

		TEST(GetConstEndIterator, ID43_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.ConstEnd(), 0);
			list.Insert(list.ConstEnd(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*list.ConstEnd(), 0);
		}

		TEST(GetConstEndIterator, ID44_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.ConstEnd(), 0);
			EXPECT_EQ(*list.ConstEnd(), 0);

			list.Insert(list.ConstEnd(), 1);
			EXPECT_EQ(*list.ConstEnd(), 1);

			list.Insert(list.ConstEnd(), 2);
			EXPECT_EQ(*list.ConstEnd(), 2);
		}

		TEST(GetConstEndIterator, ID45_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.ConstEnd(), 0);
			list.Insert(list.ConstEnd(), 1);
			list.Insert(++list.ConstEnd(), 2);

			// �폜���̃C�e���[�^
			list.Remove(++list.ConstEnd());
			EXPECT_EQ(*list.ConstEnd(), 0);

			list.Remove(list.ConstEnd());
			EXPECT_EQ(*list.ConstEnd(), 0);

			list.Remove(list.ConstEnd());
			EXPECT_EQ((list.ConstBegin() == list.ConstEnd()), true);
		}
	}





	namespace UserGetIteratorTest {
		TEST(UserGetIterator, ID00_GetIteratorNone) {
#ifdef _DEBUG
			List<int>::Iterator iter;

			EXPECT_DEATH(*iter, "Assertion failed:");
#endif
		}

		TEST(UserGetIterator, ID01_SetIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// �C�e���[�^������
			*list.begin() = 1;

			// �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 1);
		}

#ifdef COMPILE_ERROR_CHECK

		TEST(UserGetIterator, ID02_SetConstIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// �C�e���[�^������
			*list.ConstBegin() = 1;

			// �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 1);
		}

#endif

		TEST(UserGetIterator, ID03_BeginIterator) {
#ifdef _DEBUG
			List<int> list;

			// ��̏�ԂŐ擪�C�e���[�^���擾�i���s�j
			EXPECT_DEATH(*list.begin(), "Assertion failed:");
#endif
		}

		TEST(UserGetIterator, ID04_EndIterator) {
#ifdef _DEBUG
			List<int> list;

			// �����C�e���[�^���擾�i���s�j
			EXPECT_DEATH(*list.end(), "Assertion failed:");
#endif
		}
	}





	namespace UserIncrementTest {
		TEST(UserIncrement, ID05_IncrementNone) {
#ifdef _DEBUG
			// �Q�Ƃ��Ȃ��ŃC���N�������g�i���s�j
			EXPECT_DEATH(++List<int>::Iterator(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID06_IncrementBegin) {
#ifdef _DEBUG
			List<int> list;

			// ���X�g����ŃC���N�������g�i���s�j
			EXPECT_DEATH(++list.begin(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID07_IncrementEnd) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// �����C�e���[�^�ɃC���N�������g�i���s�j
			EXPECT_DEATH(++list.end(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID08_Increment) {
			List<int> list;

			// �v�f��2�ȏ�
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(++(*iter), 0);
			EXPECT_EQ(++(*iter), 1);
			EXPECT_EQ(++(*iter), 2);
		}

		TEST(UserIncrement, ID09_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �O�u�C���N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(++(*iter), 0);
			EXPECT_EQ(++(*iter), 1);
			EXPECT_EQ(++(*iter), 2);
		}

		TEST(UserIncrement, ID10_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// ��u�C���N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ((*iter)++, 0);
			EXPECT_EQ((*iter)++, 1);
			EXPECT_EQ((*iter)++, 2);
		}
	}





	namespace UserDecrementTest {
		TEST(UserIncrement, ID11_DecrementNone) {
#ifdef _DEBUG
			// �Q�Ƃ��Ȃ��Ńf�N�������g�i���s�j
			EXPECT_DEATH(--List<int>::Iterator(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID12_DecrementBegin) {
#ifdef _DEBUG
			List<int> list;

			// ���X�g����Ńf�N�������g�i���s�j
			EXPECT_DEATH(--list.end(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID13_DecrementEnd) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// �擪�C�e���[�^�Ƀf�N�������g�i���s�j
			EXPECT_DEATH(--list.begin(), "Assertion failed:");
#endif
		}

		TEST(UserIncrement, ID14_Decrement) {
			List<int> list;

			// �v�f��2�ȏ�
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �l���`�F�b�N
			List<int>::Iterator iter = list.end();
			--iter;
			EXPECT_EQ(--(*iter), 0);
			EXPECT_EQ(--(*iter), 1);
			EXPECT_EQ(--(*iter), 2);
		}

		TEST(UserIncrement, ID15_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �O�u�C���N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			--iter;
			EXPECT_EQ(--(*iter), 0);
			EXPECT_EQ(--(*iter), 1);
			EXPECT_EQ(--(*iter), 2);
		}

		TEST(UserIncrement, ID16_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// ��u�C���N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			--iter;
			EXPECT_EQ((*iter)--, 0);
			EXPECT_EQ((*iter)--, 1);
			EXPECT_EQ((*iter)--, 2);
		}
	}





	namespace UserIteratorTest {
		TEST(UserIterator, ID18_Copy) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		TEST(UserIterator, ID20_Assin) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.begin();
			iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		TEST(UserIterator, ID21_Equal) {
			List<int> list;

			EXPECT_EQ((list.begin() == list.end()), true);
		}

		TEST(UserIterator, ID22_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.begin()), true);
		}

		TEST(UserIterator, ID23_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.end()), false);
		}

		TEST(UserIterator, ID24_NotEqual) {
			List<int> list;

			EXPECT_EQ((list.begin() != list.end()), false);
		}

		TEST(UserIterator, ID25_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.begin()), false);
		}

		TEST(UserIterator, ID26_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.end()), true);
		}
	}
}




