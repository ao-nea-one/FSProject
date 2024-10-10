
#include "../FSProject/List.h"

/*--- メンバー関数 ---*/

template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
bool Dictionary<K, V, BUCKET_SIZE, HASH>::Insert(const K &key, const V &value) {
	unsigned int idx = CalcHash(key);


	List<Pair> &list = bucket[idx];
	typename List<Pair>::Iterator iter;


	// 値が存在するか調べる
	for (iter = list.begin(); iter != list.cend() && (*iter).key != key; ++iter);

	// 値が存在しないなら追加
	if (iter == list.cend()) {
		// 挿入成功なら要素数のカウントアップ
		if (list.Insert(list.end(), Pair(key, value))) {
			count++;
			return true;
		}
	}
	// 要素が存在する
	return false;
}





template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
bool Dictionary<K, V, BUCKET_SIZE, HASH>::Find(const K &key, V &outValue) const {
	unsigned int idx = CalcHash(key);


	const List<Pair> &list = bucket[idx];
	typename List<Pair>::ConstIterator iter;


	// 値が存在するか調べる
	for (iter = list.begin(); iter != list.cend() && (*iter).key != key; ++iter);

	// 値が存在する
	if (iter != list.cend()) {
		outValue = (*iter).value;
		return true;
	}
	// 値が存在しない
	else return false;
}





template<class K, class V, unsigned int BUCKET_SIZE, size_t(*HASH)(const K &)>
bool Dictionary<K, V, BUCKET_SIZE, HASH>::Remove(const K &key) {
	unsigned int idx = CalcHash(key);


	List<Pair> &list = bucket[idx];
	typename List<Pair>::Iterator iter;


	// 値が存在するか調べる
	for (iter = list.begin(); iter != list.cend() && (*iter).key != key; ++iter);

	// 値が存在するなら削除
	if (iter != list.cend()) {
		// 削除成功なら要素数のカウントダウン
		if (list.Remove(iter)) {
			count--;
			return true;
		}
	}
	// 値が存在しない
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
