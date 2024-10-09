#include "pch.h"
#include "ManualTest1_6.h"
#include <gtest/gtest.h>

/*--- include ---*/
#include "../Hash/Dictionary.h"



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
size_t NoHash(const bool &key) {
	return std::hash<bool>()(key);
}



#ifdef ID00_HASH_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ��
/// �⑫�@�@�@�@�@�F�R���p�C���G���[���`�F�b�N�B�����e�X�g�����Ȃ�
/// </summary>
TEST(StackGetDataNum, ID00_DefineHash) {
	const Dictionary<std::string, int, 2, NoHash> dic;
}

#endif



#ifdef ID12_HASH_NO_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�Fconst�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(StackGetDataNum, ID12_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;

	dic.GetCount();
}

#endif



#ifdef ID18_HASH_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(StackInvert, ID18_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;

	dic.Insert("A", 0);
}

#endif



#ifdef ID26_HASH_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�F��const�̃��\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(StackRemove, ID18_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;

	dic.Remove("A");
}

#endif



#ifdef ID34_HASH_NO_COMPILE_ERROR_CHECK

/// <summary>
/// �e�X�g���ځ@�@�Fconst���\�b�h�ł��邩
/// �⑫�@�@�@�@�@�Fconst�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
/// </summary>
TEST(StackFind, ID34_Const) {
	const Dictionary<std::string, int, 2, Hash> dic;
	int tmp = -1;

	dic.Find("A", tmp);
}

#endif
