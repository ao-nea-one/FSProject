#include "pch.h"
#include <gtest/gtest.h>
#include <functional>

#include "../FSProject/List.h"


namespace No01_2_List {
	void Print(List<int> &list) {
		std::cout << "list : ";

		for (auto &i : list) {
			std::cout << i << ", ";
		}

		std::cout << std::endl;
	}

	void Print(List<int> &list, List<int>::Iterator &iter) {
		if (iter.Get()) {
			for (auto i = list.begin(); i != list.end(); ++i) {
				if (i == iter) {
					std::cout << "[" << *i << "], ";
				}
				else {
					std::cout << *i << ", ";
				}
			}

			std::cout << std::endl;
		}
		else {
			std::cout << "iterator value : nullptr" << std::endl;
		}
	}

	void Print(List<int> &list, List<int>::ConstIterator &iter) {
		if (iter.Get() && !iter.IsDummy()) {
			for (auto i = list.begin(); i != list.end(); ++i) {
				if (i == iter) {
					std::cout << "[" << *i << "], ";
				}
				else {
					std::cout << *i << ", ";
				}
			}

			if (iter.IsDummy()) std::cout << "[ Dummy ], ";

			std::cout << std::endl;
		}
		else {
			std::cout << "iterator value : nullptr" << std::endl;
		}
	}

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
			List<int> list;
			// �����𒴂����}���i���s�j
			EXPECT_DEATH(list.Insert(++list.end(), 0), "Assertion failed:");

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID03_InsertSuccess) {
			List<int> list;
			// �}��
			list.Insert(list.begin(), 0);

			EXPECT_EQ(list.GetCount(), 1);
		}

		TEST(GetDataNum, ID04_InsertFailed) {
			List<int> list;
			// �m�[�h����̏�Ԃł̑}���i���s�j
			list.Insert(List<int>::Iterator(), 0);

			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID05_RemoveSuccess) {
			List<int> list;
			list.PushBack(0);
			// �m�[�h�̍폜
			list.PopBack();


			EXPECT_EQ(list.GetCount(), 0);
		}

		TEST(GetDataNum, ID06_RemoveFailed) {
			List<int> list;
			list.PushBack(0);
			// �����𒴂����m�[�h�̍폜�i���s�j
			EXPECT_DEATH(list.Remove(++list.end()), "Assertion failed:");

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
		TEST(InsertData, ID09_InsertBeginEmpty) {
			List<int> list;
			// �󂩂�}��
			list.PushFront(0);
		}

		TEST(InsertData, ID09_InsertEndEmpty) {
			List<int> list;
			// �󂩂�}��
			list.PushBack(0);
		}

		TEST(InsertData, ID10_InsertBegin) {
			List<int> list;

			list.PushFront(1);
			Print(list);
			list.PushBack(2);
			Print(list);
			// �擪�ɑ}��
			list.Insert(list.begin(), 0);
			Print(list);
		}

		TEST(InsertData, ID11_InsertEnd) {
			List<int> list;

			list.PushFront(0);
			Print(list);
			list.PushBack(1);
			Print(list);
			// �����ɑ}��
			list.Insert(list.end(), 2);
			Print(list);
		}

		TEST(InsertData, ID12_Insert) {
			List<int> list;

			list.PushFront(0);
			Print(list);
			list.PushBack(2);
			Print(list);
			// ���Ԃɑ}��
			list.Insert(++list.begin(), 1);
			Print(list);
		}

		TEST(InsertData, ID13_InsertConstIterator) {
			List<int> list;

			list.PushFront(0);
			list.PushBack(1);
			list.Insert(list.ConstBegin(), 2);
		}

		TEST(InsertData, ID14_InsertNone) {
			List<int> list;

			list.Insert(List<int>::Iterator(), 2);
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
			list.PushFront(0);
			list.PushBack(1);

			// �擪���폜
			EXPECT_EQ(list.Remove(list.begin()), true);
		}

		TEST(RemoveData, ID18_RemoveEnd) {
			List<int> list;
			list.PushFront(0);
			list.PushBack(1);

			// �������폜
			EXPECT_EQ(list.Remove(list.end()), false);
		}

		TEST(RemoveData, ID19_Remove) {
			List<int> list;
			list.PushFront(0);
			list.PushBack(2);
			list.Insert(++list.begin(), 1);
			Print(list);

			// ���Ԃ��폜
			EXPECT_EQ(list.Remove(++list.begin()), true);
			Print(list);
		}

		TEST(RemoveData, ID20_RemoveConstIterator) {
			List<int> list;
			list.PushFront(0);
			list.PushBack(1);
			Print(list);

			// �R���X�g�C�e���[�^�ō폜
			EXPECT_EQ(list.Remove(list.ConstBegin()), true);
			Print(list);
		}

		TEST(RemoveData, ID21_RemoveNone) {
			List<int> list;
			list.PushFront(0);
			list.PushBack(1);

			// �s���ȃC�e���[�^�ō폜
			EXPECT_EQ(list.Remove(List<int>::Iterator()), false);
		}
	}





	namespace GetBeginIteratorTest{
		TEST(GetBeginIterator, ID23_GetEmpty) {
			List<int> list;
			// ��Ŏ擾
			std::cout << "is dummy : " << list.begin().IsDummy() << std::endl;
		}

		TEST(GetBeginIterator, ID24_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.begin());
		}

		TEST(GetBeginIterator, ID25_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.begin());

			list.PushBack(1);
			Print(list, list.begin());
		}

		TEST(GetBeginIterator, ID26_GetIteratorInsert) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushFront(0);
			Print(list, list.begin());

			list.PushBack(1);
			Print(list, list.begin());

			list.Insert(++list.begin(), 2);
			Print(list, list.begin());
		}

		TEST(GetBeginIterator, ID27_GetIteratorRemove) {
			List<int> list;

			list.PushFront(0);
			list.PushBack(1);
			list.Insert(++list.begin(), 2);

			// �v�f�����i�폜�j�̏ꍇ�Ŏ擾
			list.Insert(++list.begin(), 2);
			Print(list, list.begin());

			list.PopBack();
			Print(list, list.begin());

			list.PopFront();
			Print(list, list.begin());
		}
	}





	namespace GetBeginConstIteratorTest {
		TEST(GetBeginConstIteratorTest, ID29_GetEmpty) {
			List<int> list;
			// ��Ŏ擾
			std::cout << "is dummy : " << list.ConstBegin().IsDummy() << std::endl;
		}

		TEST(GetBeginConstIteratorTest, ID30_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.ConstBegin());
		}

		TEST(GetBeginConstIteratorTest, ID31_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.ConstBegin());

			list.PushBack(1);
			Print(list, list.ConstBegin());
		}

		TEST(GetBeginConstIteratorTest, ID32_GetIteratorInsert) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushFront(0);
			Print(list, list.ConstBegin());

			list.PushBack(1);
			Print(list, list.ConstBegin());

			list.Insert(++list.begin(), 2);
			Print(list, list.ConstBegin());
		}

		TEST(GetBeginConstIteratorTest, ID33_GetIteratorRemove) {
			List<int> list;

			list.PushFront(0);
			list.PushBack(1);
			list.Insert(++list.begin(), 2);

			// �v�f�����i�폜�j�̏ꍇ�Ŏ擾
			list.Remove(++list.begin());
			Print(list, list.ConstBegin());

			list.PopBack();
			Print(list, list.ConstBegin());

			list.PopFront();
			Print(list, list.ConstBegin());
		}
	}





	namespace GetEndIteratorTest{
		TEST(GetEndIterator, ID35_GetEmpty) {
			List<int> list;
			// ��Ŏ擾
			std::cout << "is dummy : " << list.end().IsDummy() << std::endl;
		}

		TEST(GetEndIterator, ID36_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.end());
		}

		TEST(GetEndIterator, ID37_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.end());

			list.PushBack(1);
			Print(list, list.end());
		}

		TEST(GetEndIterator, ID38_GetIteratorInsert) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushFront(0);
			Print(list, --list.end());

			list.PushBack(2);
			Print(list, --list.end());

			list.Insert(++list.begin(), 1);
			Print(list, --list.end());
		}

		TEST(GetEndIterator, ID39_GetIteratorRemove) {
			List<int> list;

			list.PushFront(0);
			list.PushBack(2);
			list.Insert(++list.begin(), 1);

			// �v�f�����i�폜�j�̏ꍇ�Ŏ擾
			list.Remove(++list.begin());
			Print(list, list.end());

			list.PopBack();
			Print(list, list.end());

			list.PopFront();
			Print(list, list.end());
		}
	}





	namespace GetEndConstIteratorTest {
		TEST(GetEndConstIteratorTest, ID41_GetEmpty) {
			List<int> list;
			// ��Ŏ擾
			std::cout << "is dummy : " << list.ConstEnd().IsDummy() << std::endl;
		}

		TEST(GetEndConstIteratorTest, ID42_GetIterator1) {
			List<int> list;

			// �v�f1�̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.ConstEnd());
		}

		TEST(GetEndConstIteratorTest, ID43_GetIterator2) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushBack(0);
			Print(list, list.ConstEnd());

			list.PushBack(1);
			Print(list, list.ConstEnd());
		}

		TEST(GetEndConstIteratorTest, ID44_GetIteratorInsert) {
			List<int> list;

			// �v�f�����̏ꍇ�Ŏ擾
			list.PushFront(0);
			Print(list, list.ConstEnd());

			list.PushBack(2);
			Print(list, list.ConstEnd());

			list.Insert(++list.begin(), 1);
			Print(list, list.ConstEnd());
		}

		TEST(GetEndConstIteratorTest, ID45_GetIteratorRemove) {
			List<int> list;

			list.PushFront(0);
			list.PushBack(2);
			list.Insert(++list.begin(), 1);

			// �v�f�����i�폜�j�̏ꍇ�Ŏ擾
			list.Remove(++list.begin());
			Print(list, list.ConstEnd());

			list.PopBack();
			Print(list, list.ConstEnd());

			list.PopFront();
			Print(list, list.ConstEnd());
		}
	}





	namespace UserGetIteratorTest {
		TEST(UserGetIterator, ID00_GetIteratorNone) {
			List<int>::Iterator iter;

			EXPECT_DEATH(*iter, "Assertion failed:");
		}

		TEST(UserGetIterator, ID01_SetIteratorValue) {
			List<int> list;
			list.PushBack(0);

			Print(list);
			*list.begin() = 1;
			Print(list);
		}

		TEST(UserGetIterator, ID03_BeginIterator) {
			List<int> list;

			EXPECT_DEATH(*list.begin(), "Assertion failed:");
		}

		TEST(UserGetIterator, ID04_EndIterator) {
			List<int> list;

			EXPECT_DEATH(*list.end(), "Assertion failed:");
		}
	}





	namespace UserIncrementTest {
		TEST(UserIncrement, ID05_IncrementNone) {
			EXPECT_DEATH(++List<int>::Iterator(), "Assertion failed:");
		}

		TEST(UserIncrement, ID06_IncrementBegin) {
			List<int> list;

			EXPECT_DEATH(++list.begin(), "Assertion failed:");
		}

		TEST(UserIncrement, ID07_IncrementEnd) {
			List<int> list;

			EXPECT_DEATH(++list.end(), "Assertion failed:");
		}

		TEST(UserIncrement, ID08_10_Increment) {
			List<int> list;
			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);

			List<int>::Iterator iter = list.begin();

			Print(list, iter);
			++iter;
			Print(list, iter);
			iter++;
			Print(list, iter);
		}
	}





	namespace UserDecrementTest {
		TEST(UserDecrement, ID11_DecrementNone) {
			EXPECT_DEATH(--List<int>::Iterator(), "Assertion failed:");
		}

		TEST(UserDecrement, ID12_DecrementEnd) {
			List<int> list;

			EXPECT_DEATH(--list.end(), "Assertion failed:");
		}

		TEST(UserDecrement, ID03_DecrementBegin) {
			List<int> list;

			EXPECT_DEATH(--list.begin(), "Assertion failed:");
		}

		TEST(UserDecrement, ID14_16_Decrement) {
			List<int> list;
			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);

			List<int>::Iterator iter = --list.end();

			Print(list, iter);
			--iter;
			Print(list, iter);
			iter--;
			Print(list, iter);
		}
	}





	namespace UserIteratorTest {
		TEST(UserIterator, ID18_Copy) {
			List<int> list;
			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);
			List<int>::Iterator iter = list.end();

			EXPECT_EQ((iter == list.end()), true);
		}

		TEST(UserIterator, ID20_Assin) {
			List<int> list;
			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);
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

			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);

			EXPECT_EQ((list.begin() == list.begin()), true);
		}

		TEST(UserIterator, ID23_Equal) {
			List<int> list;

			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);

			EXPECT_EQ((list.begin() == list.end()), false);
		}

		TEST(UserIterator, ID24_NotEqual) {
			List<int> list;

			EXPECT_EQ((list.begin() != list.end()), false);
		}

		TEST(UserIterator, ID25_NotEqual) {
			List<int> list;

			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);

			EXPECT_EQ((list.begin() != list.begin()), false);
		}

		TEST(UserIterator, ID26_NotEqual) {
			List<int> list;

			list.PushBack(0);
			list.PushBack(1);
			list.PushBack(2);

			EXPECT_EQ((list.begin() != list.end()), true);
		}
	}
}




