#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"


namespace No01_2_List {

	namespace GetDataNumTest {
		/// <summary>
		/// ���X�g����ł���ꍇ�̖߂�l
		/// </summary>
		TEST(GetDataNum, ID00_Empty) {
			List<int> list;

			EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// ���X�g�����ւ̑}�����s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID01_InsertEndSuccess) {
			List<int> list;
			// �����ւ̑}���i�����j
			list.Insert(list.end(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		/// <summary>
		/// ���X�g�����ւ̑}�������s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID02_InsertEndFailed) {

			// ���s���Ȃ����߃X�L�b�v
			
			//List<int> list;
			//// �����ւ̑}���i���s�j
			//EXPECT_DEATH(list.Insert(list.end(), 0), "Assertion failed:");

			//EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// �f�[�^�̑}�����s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// �}��
			list.Insert(list.begin(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		/// <summary>
		/// �f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// �C�e���[�^����Ȃǂ����R
			// �}���i���s�j
			list.Insert(List<int>::Iterator(), 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// �f�[�^�̍폜���s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// �m�[�h�̍폜
			list.Remove(list.begin());


			EXPECT_EQ(list.GetCount(), 0);
		}

		/// <summary>
		/// �f�[�^�̍폜�����s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			list.Insert(list.begin(), 0);
			// �C�e���[�^����Ȃǂ����R
			// �m�[�h�̍폜�i���s�j
			list.Remove(List<int>::Iterator());

			EXPECT_EQ(list.GetCount(), 1);
		}

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
		/// </summary>
		TEST(GetDataNum, ID07_RemoveEmptyFailed) {
			List<int> list;
			// �m�[�h����ō폜
			list.Remove(list.begin());

			EXPECT_EQ(list.GetCount(), 0);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// const�̃��\�b�h�ł��邩
		/// </summary>
		TEST(GetDataNum, ID08_Const) {
			const List<int> list;

			list.GetCount();
		}
#endif
	}





	namespace InsertDataTest {

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
		/// </summary>
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

		/// <summary>
		/// ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
		/// </summary>
		TEST(InsertData, ID10_InsertBegin) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// �擪�ɑ}��
			EXPECT_EQ(list.Insert(list.begin(), 0), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
		/// </summary>
		TEST(InsertData, ID11_InsertEnd) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 1), true);
			// �����ɑ}��
			EXPECT_EQ(list.Insert(list.end(), 2), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
		/// </summary>
		TEST(InsertData, ID12_Insert) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			EXPECT_EQ(list.Insert(list.begin(), 0), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			// ���Ԃɑ}��
			EXPECT_EQ(list.Insert(++list.begin(), 1), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ConstIterator���w�肵�đ}�����s�����ۂ̋���
		/// </summary>
		TEST(InsertData, ID13_InsertConstIterator) {
			List<int> list;

			EXPECT_EQ(list.Insert(list.begin(), 1), true);
			EXPECT_EQ(list.Insert(list.end(), 2), true);
			EXPECT_EQ(list.Insert(list.cbegin(), 0), true);

			// �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// �s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
		/// </summary>
		TEST(InsertData, ID14_InsertNone) {
			List<int> list, other;

			// ��̃C�e���[�^�ő}���i���s�j
			EXPECT_EQ(list.Insert(List<int>::Iterator(), 2), false);

			 // �ق��̃��X�g�̓���e�[�^�ő}��
			EXPECT_EQ(list.Insert(other.begin(), 2), false);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// ��const�̃��\�b�h�ł��邩
		/// </summary>
		TEST(InsertData, ID15_NoConst) {
			const List<int> list;

			list.Insert(list.begin(), 0);
		}
#endif
	}




	namespace RemoveDataTest {

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
		/// </summary>
		TEST(RemoveData, ID16_RemoveEmpty) {
			List<int> list;
			// ��ō폜
			EXPECT_EQ(list.Remove(list.begin()), false);
			EXPECT_EQ(list.Remove(list.end()), false);
		}

		/// <summary>
		/// ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
		/// </summary>
		TEST(RemoveData, ID17_RemoveBegin) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �擪���폜
			EXPECT_EQ(list.Remove(list.begin()), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
		/// </summary>
		TEST(RemoveData, ID18_RemoveEnd) {
			List<int> list;

			// ���X�g�ɕ����̗v�f������ꍇ
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �������폜
			EXPECT_EQ(list.Remove(list.end()), false);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 1);
		}

		/// <summary>
		/// ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
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
			EXPECT_EQ(*iter, 0);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// ConstIterator���w�肵�č폜���s�����ۂ̋���
		/// </summary>
		TEST(RemoveData, ID20_RemoveConstIterator) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �R���X�g�C�e���[�^�ō폜
			EXPECT_EQ(list.Remove(list.cbegin()), true);

			 // �l���`�F�b�N
			auto iter = list.begin();
			EXPECT_EQ(*iter, 1);
			iter++;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// �s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
		TEST(RemoveData, ID21_RemoveNone) {
			List<int> list;
			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �s���ȃC�e���[�^�ō폜
			EXPECT_EQ(list.Remove(List<int>::Iterator()), false);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// ��const�̃��\�b�h�ł��邩
		/// </summary>
		TEST(RemoveData, ID22_NoConst) {
			const List<int> list;

			list.Remove(list.begin());
		}
#endif
	}





	namespace GetBeginIteratorTest{

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetBeginIterator, ID23_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.begin() == list.end()), true);
		}

		/// <summary>
		/// ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetBeginIterator, ID24_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);

			 // �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 0);
		}

		/// <summary>
		/// ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetBeginIterator, ID25_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 0);
		}

		/// <summary>
		/// �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetBeginIterator, ID26_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.begin(), 0);
			EXPECT_EQ(*list.begin(), 0);

			list.Insert(list.end(), 2);
			EXPECT_EQ(*list.begin(), 0);

			list.Insert(++list.begin(), 1);
			EXPECT_EQ(*list.begin(), 0);
		}

		/// <summary>
		/// �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
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

#ifdef COMPILE_ERROR

		/// <summary>
		/// const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
		/// </summary>
		TEST(GetBeginIterator, ID28_GetConstIterator) {
			const List<int> list;

			auto iter = list.begin();
		}
#endif
	}





	namespace GetConstBeginIteratorTest {

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstBeginIterator, ID29_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.cbegin() == list.cend()), true);
		}

		/// <summary>
		/// ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstBeginIterator, ID30_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.cend(), 0);

			// �l���`�F�b�N
			EXPECT_EQ(*list.cbegin(), 0);
		}

		/// <summary>
		/// ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstBeginIterator, ID31_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.cend(), 0);
			list.Insert(list.cend(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*list.cbegin(), 0);
		}

		/// <summary>
		/// �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstBeginIterator, ID32_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.cbegin(), 0);
			EXPECT_EQ(*list.cbegin(), 0);

			list.Insert(list.cend(), 2);
			EXPECT_EQ(*list.cbegin(), 0);

			list.Insert(++list.cbegin(), 1);
			EXPECT_EQ(*list.cbegin(), 0);
		}

		/// <summary>
		/// �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstBeginIterator, ID33_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.cbegin(), 0);
			list.Insert(list.cend(), 2);
			list.Insert(++list.cbegin(), 1);

			// �폜���̃C�e���[�^
			list.Remove(++list.cbegin());
			EXPECT_EQ(*list.cbegin(), 0);

			list.Remove(--list.cend());
			EXPECT_EQ(*list.cbegin(), 0);

			list.Remove(list.cbegin());
			EXPECT_EQ((list.cbegin() == list.cend()), true);
		}

#ifdef COMPILE_NO_ERROR

		/// <summary>
		/// const�̃��\�b�h�ł��邩
		/// </summary>
		TEST(GetConstBeginIterator, ID34_GetConstIterator) {
			const List<int> list;

			auto iter = list.cbegin();
		}
#endif
	}





	namespace GetEndIteratorTest {

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetEndIterator, ID35_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.end() == list.end()), true);
		}

		/// <summary>
		/// ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetEndIterator, ID36_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);

			// �l���`�F�b�N
			EXPECT_EQ(*(--list.end()), 0);
		}

		/// <summary>
		/// ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetEndIterator, ID37_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*(--list.end()), 1);
		}

		/// <summary>
		/// �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetEndIterator, ID38_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.begin(), 0);
			EXPECT_EQ(*(--list.end()), 0);

			list.Insert(list.end(), 2);
			EXPECT_EQ(*(--list.end()), 2);

			list.Insert(++list.begin(), 1);
			EXPECT_EQ(*(--list.end()), 2);
		}

		/// <summary>
		/// �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetEndIterator, ID39_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.begin(), 0);
			list.Insert(list.end(), 2);
			list.Insert(++list.begin(), 1);

			// �폜���̃C�e���[�^
			list.Remove(++list.begin());
			EXPECT_EQ(*(--list.end()), 2);

			list.Remove(--list.end());
			EXPECT_EQ(*(--list.end()), 0);

			list.Remove(list.begin());
			EXPECT_EQ((list.end() == list.begin()), true);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
		/// </summary>
		TEST(GetEndIterator, ID40_GetConstIterator) {
			const List<int> list;

			auto iter = list.end();
		}
#endif
	}





	namespace GetConstEndIteratorTest {

		/// <summary>
		/// ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstEndIterator, ID41_GetEmpty) {
			List<int> list;

			// �l���`�F�b�N
			EXPECT_EQ((list.cend() == list.cend()), true);
		}

		/// <summary>
		/// ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstEndIterator, ID42_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.Insert(list.cend(), 0);

			// �l���`�F�b�N
			EXPECT_EQ(*(--list.cend()), 0);
		}

		/// <summary>
		/// ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstEndIterator, ID43_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.Insert(list.cend(), 0);
			list.Insert(list.cend(), 1);

			// �l���`�F�b�N
			EXPECT_EQ(*(--list.cend()), 1);
		}

		/// <summary>
		/// �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
		TEST(GetConstEndIterator, ID44_GetIteratorInsert) {
			List<int> list;

			// �}�����̃C�e���[�^
			list.Insert(list.cbegin(), 0);
			EXPECT_EQ(*(--list.cend()), 0);

			list.Insert(list.cend(), 2);
			EXPECT_EQ(*(--list.cend()), 2);

			list.Insert(++list.cbegin(), 1);
			EXPECT_EQ(*(--list.cend()), 2);
		}

		/// <summary>
		/// �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		/// </summary>
		TEST(GetConstEndIterator, ID45_GetIteratorRemove) {
			List<int> list;

			list.Insert(list.cbegin(), 0);
			list.Insert(list.cend(), 2);
			list.Insert(++list.cbegin(), 1);

			// �폜���̃C�e���[�^
			list.Remove(++list.cbegin());
			EXPECT_EQ(*(--list.cend()), 2);

			list.Remove(--list.cend());
			EXPECT_EQ(*(--list.cend()), 0);

			list.Remove(list.cbegin());
			EXPECT_EQ((list.cbegin() == list.cend()), true);
		}

#ifdef COMPILE_NO_ERROR

		/// <summary>
		/// const�̃��\�b�h�ł��邩
		/// </summary>
		TEST(GetConstBeginIterator, ID46_GetConstIterator) {
			const List<int> list;

			auto iter = list.cend();
		}
#endif
	}





	namespace UserGetIteratorTest {

		/// <summary>
		/// ���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
		/// </summary>
		TEST(UserGetIterator, ID00_GetIteratorNone) {
#ifdef _DEBUG
			List<int>::Iterator iter;

			EXPECT_DEATH(*iter, "Assertion failed:");
#endif
		}

		/// <summary>
		/// Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
		/// </summary>
		TEST(UserGetIterator, ID01_SetIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// �C�e���[�^������
			*list.begin() = 1;

			// �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 1);
		}

#ifdef COMPILE_ERROR_CHECK

		/// <summary>
		/// ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
		/// </summary>
		/// <param name=""></param>
		/// <param name=""></param>
		TEST(UserGetIterator, ID02_SetConstIteratorValue) {
			List<int> list;
			list.Insert(list.begin(), 0);

			// �C�e���[�^������
			*list.ConstBegin() = 1;

			// �l���`�F�b�N
			EXPECT_EQ(*list.begin(), 1);
		}

#endif

		/// <summary>
		/// ���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		/// </summary>
		TEST(UserGetIterator, ID03_BeginIterator) {
#ifdef _DEBUG
			List<int> list;

			// ��̏�ԂŐ擪�C�e���[�^���擾�i���s�j
			EXPECT_DEATH(*list.begin(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// �����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		/// </summary>
		TEST(UserGetIterator, ID04_EndIterator) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.end(), 0);

			// �����C�e���[�^���擾�i���s�j
			EXPECT_DEATH(*list.end(), "Assertion failed:");
#endif
		}
	}





	namespace UserIncrementTest {
		
		/// <summary>
		/// ���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID05_IncrementNone) {
#ifdef _DEBUG
			// �Q�Ƃ��Ȃ��ŃC���N�������g�i���s�j
			EXPECT_DEATH(++List<int>::Iterator(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// ���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID06_IncrementBegin) {
#ifdef _DEBUG
			List<int> list;

			// ���X�g����ŃC���N�������g�i���s�j
			EXPECT_DEATH(++list.begin(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// �����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID07_IncrementEnd) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// �����C�e���[�^�ɃC���N�������g�i���s�j
			EXPECT_DEATH(++list.end(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID08_Increment) {
			List<int> list;

			// �v�f��2�ȏ�
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(*iter, 0);
			++iter;
			EXPECT_EQ(*iter, 1);
			++iter;
			EXPECT_EQ(*iter, 2);
		}

		/// <summary>
		/// �O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
		/// </summary>
		TEST(UserIncrement, ID09_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �O�u�C���N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(*(++iter), 1);
			EXPECT_EQ(*(iter), 1);
			EXPECT_EQ(*(++iter), 2);
			EXPECT_EQ(*(iter), 2);
		}

		/// <summary>
		/// ��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
		/// </summary>
		TEST(UserIncrement, ID10_Increment) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// ��u�C���N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.begin();
			EXPECT_EQ(0, *iter++);
			EXPECT_EQ(1, *(iter));
			EXPECT_EQ(1, *(iter++));
			EXPECT_EQ(2, *(iter));
		}
	}





	namespace UserDecrementTest {

		/// <summary>
		/// ���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID11_DecrementNone) {
#ifdef _DEBUG
			// �Q�Ƃ��Ȃ��Ńf�N�������g�i���s�j
			EXPECT_DEATH(--List<int>::Iterator(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// ���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID12_DecrementEnd) {
#ifdef _DEBUG
			List<int> list;

			// ���X�g����Ńf�N�������g�i���s�j
			EXPECT_DEATH(--list.end(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// �擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID13_DecrementBegin) {
#ifdef _DEBUG
			List<int> list;
			list.Insert(list.begin(), 0);

			// �擪�C�e���[�^�Ƀf�N�������g�i���s�j
			EXPECT_DEATH(--list.begin(), "Assertion failed:");
#endif
		}

		/// <summary>
		/// ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
		/// </summary>
		TEST(UserIncrement, ID14_Decrement) {
			List<int> list;

			// �v�f��2�ȏ�
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �l���`�F�b�N
			List<int>::Iterator iter = list.end();
			--iter;
			EXPECT_EQ(*iter, 2);
			--iter;
			EXPECT_EQ(*iter, 1);
			--iter;
			EXPECT_EQ(*iter, 0);
		}

		/// <summary>
		/// �O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
		/// </summary>
		TEST(UserIncrement, ID15_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// �O�u�f�N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.end();
			--iter;
			EXPECT_EQ(*(--iter), 1);
			EXPECT_EQ(*(iter), 1);
			EXPECT_EQ(*(--iter), 0);
			EXPECT_EQ(*(iter), 0);
		}

		/// <summary>
		/// �O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
		/// </summary>
		TEST(UserIncrement, ID16_Decrement) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);


			// ��u�f�N�������g
			// �l���`�F�b�N
			List<int>::Iterator iter = list.end();
			iter--;
			EXPECT_EQ(*(iter--), 2);
			EXPECT_EQ(*(iter), 1);
			EXPECT_EQ(*(iter--), 1);
			EXPECT_EQ(*(iter), 0);
		}
	}





	namespace UserIteratorTest {

#ifdef COMPILE_ERROR

		/// <summary>
		/// ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
		/// </summary>
		TEST(UserIterator, ID17_ConstIteratorToIterator) {
			List<int> list;

			List<int>::Iterator iter = list.cbegin();
		}
#endif

		/// <summary>
		/// �R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
		/// </summary>
		TEST(UserIterator, ID18_Copy) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

#ifdef COMPILE_ERROR

		/// <summary>
		/// Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
		/// </summary>
		TEST(UserIterator, ID19_ConstIteratorToIterator) {
			List<int> list;
			List<int>::Iterator iter;
			iter = list.cbegin();
		}
#endif

		/// <summary>
		/// �����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
		/// </summary>
		TEST(UserIterator, ID20_Assin) {
			List<int> list;
			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);
			List<int>::Iterator iter = list.begin();
			iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		/// <summary>
		/// ���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
		/// </summary>
		TEST(UserIterator, ID21_Equal) {
			List<int> list;

			EXPECT_EQ((list.begin() == list.end()), true);
		}

		/// <summary>
		/// ����̃C�e���[�^���r�����ۂ̋���
		/// </summary>
		TEST(UserIterator, ID22_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.begin()), true);
		}

		/// <summary>
		/// �قȂ�C�e���[�^���r�����ۂ̋���
		/// </summary>
		TEST(UserIterator, ID23_Equal) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() == list.end()), false);
		}

		/// <summary>
		/// ���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
		/// </summary>
		TEST(UserIterator, ID24_NotEqual) {
			List<int> list;

			EXPECT_EQ((list.begin() != list.end()), false);
		}

		/// <summary>
		/// ����̃C�e���[�^���r�����ۂ̋���
		/// </summary>
		TEST(UserIterator, ID25_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.begin()), false);
		}

		/// <summary>
		/// �قȂ�C�e���[�^���r�����ۂ̋���
		/// </summary>
		TEST(UserIterator, ID26_NotEqual) {
			List<int> list;

			list.Insert(list.end(), 0);
			list.Insert(list.end(), 1);
			list.Insert(list.end(), 2);

			EXPECT_EQ((list.begin() != list.end()), true);
		}
	}
}




