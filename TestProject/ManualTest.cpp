#include "pch.h"
#include "ManualTest.h"
#include <gtest/gtest.h>

#include "../FSProject/List.h"



#ifdef ID08_NO_COMPILE_ERROR_CHECK
/// <summary>
/// const�̃��\�b�h�ł��邩
/// </summary>
TEST(GetDataNum, ID08_Const) {
	const List<int> list = List<int>();

	list.GetCount();
}
#endif



#ifdef ID15_COMPILE_ERROR_CHECK
/// <summary>
/// ��const�̃��\�b�h�ł��邩
/// </summary>
TEST(InsertData, ID15_NoConst) {
	const List<int> list;

	list.Insert(list.begin(), 0);
}
#endif



#ifdef ID22_COMPILE_ERROR_CHECK
/// <summary>
/// ��const�̃��\�b�h�ł��邩
/// </summary>
TEST(RemoveData, ID22_NoConst) {
	const List<int> list;

	list.Remove(list.begin());
}
#endif



#ifdef ID28_COMPILE_ERROR_CHECK
/// <summary>
/// const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
/// </summary>
TEST(GetBeginIterator, ID28_GetConstIterator) {
	const List<int> list;

	auto iter = list.begin();
}
#endif



#ifdef ID34_NO_COMPILE_ERROR_CHECK
/// <summary>
/// const�̃��\�b�h�ł��邩
/// </summary>
TEST(GetConstBeginIterator, ID34_GetConstIterator) {
	const List<int> list;

	auto iter = list.cbegin();
}
#endif



#ifdef ID40_COMPILE_ERROR_CHECK
/// <summary>
/// const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
/// </summary>
TEST(GetEndIterator, ID40_GetConstIterator) {
	const List<int> list;

	auto iter = list.end();
}
#endif



#ifdef ID46_NO_COMPILE_ERROR_CHECK
/// <summary>
/// const�̃��\�b�h�ł��邩
/// </summary>
TEST(GetConstBeginIterator, ID46_GetConstIterator) {
	const List<int> list;

	auto iter = list.cend();
}
#endif







#ifdef ID02_USER_COMPILE_ERROR_CHECK
/// <summary>
/// ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(UserGetIterator, ID02_SetConstIteratorValue) {
	List<int> list;
	list.Insert(list.begin(), 0);

	// �C�e���[�^������
	*list.cbegin() = 1;

	// �l���`�F�b�N
	EXPECT_EQ(*list.begin(), 1);
}
#endif



#ifdef ID17_USER_COMPILE_ERROR_CHECK
/// <summary>
/// ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
/// </summary>
TEST(UserIterator, ID17_ConstIteratorToIterator) {
	List<int> list;

	List<int>::Iterator iter = list.cbegin();
}
#endif



#ifdef ID19_USER_COMPILE_ERROR_CHECK
/// <summary>
/// Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
/// </summary>
TEST(UserIterator, ID19_ConstIteratorToIterator) {
	List<int> list;
	List<int>::Iterator iter;
	iter = list.cbegin();
}
#endif