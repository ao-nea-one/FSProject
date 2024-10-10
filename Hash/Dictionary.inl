
#include "../FSProject/List.h"

/*--- �����o�[�֐� ---*/

template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
bool Dictionary<K, V, BUCKET_SIZE, HASH>::Insert(const K &key, const V &value) {
	unsigned int idx = CalcHash(key);


	List<Pair> &list = bucket[idx];
	typename List<Pair>::Iterator iter;


	// �l�����݂��邩���ׂ�
	for (iter = list.begin(); iter != list.cend() && (*iter).key != key; ++iter);

	// �l�����݂��Ȃ��Ȃ�ǉ�
	if (iter == list.cend()) {
		// �}�������Ȃ�v�f���̃J�E���g�A�b�v
		if (list.Insert(list.end(), Pair(key, value))) {
			count++;
			return true;
		}
	}
	// �v�f�����݂���
	return false;
}





template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
bool Dictionary<K, V, BUCKET_SIZE, HASH>::Find(const K &key, V &outValue) const {
	unsigned int idx = CalcHash(key);


	const List<Pair> &list = bucket[idx];
	typename List<Pair>::ConstIterator iter;


	// �l�����݂��邩���ׂ�
	for (iter = list.begin(); iter != list.cend() && (*iter).key != key; ++iter);

	// �l�����݂���
	if (iter != list.cend()) {
		outValue = (*iter).value;
		return true;
	}
	// �l�����݂��Ȃ�
	else return false;
}





template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
bool Dictionary<K, V, BUCKET_SIZE, HASH>::Remove(const K &key) {
	unsigned int idx = CalcHash(key);


	List<Pair> &list = bucket[idx];
	typename List<Pair>::Iterator iter;


	// �l�����݂��邩���ׂ�
	for (iter = list.begin(); iter != list.cend() && (*iter).key != key; ++iter);

	// �l�����݂���Ȃ�폜
	if (iter != list.cend()) {
		// �폜�����Ȃ�v�f���̃J�E���g�_�E��
		if (list.Remove(iter)) {
			count--;
			return true;
		}
	}
	// �l�����݂��Ȃ�
	return false;
}





template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
unsigned int Dictionary<K, V, BUCKET_SIZE, HASH>::CalcHash(const K &key) const {
	return HASH(key) % BUCKET_SIZE;
}





template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
unsigned int Dictionary<K, V, BUCKET_SIZE, HASH>::GetCount(void) const {
	return count;
}
