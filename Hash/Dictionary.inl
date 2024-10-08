
#include "../FSProject/List.h"

/*--- ƒƒ“ƒo[ŠÖ” ---*/

template<class K, class V>
bool Dictionary<K, V>::Insert(const K &key, const V &value) {
	//size_t hashValue = std::hash<K>()(key);
	//unsigned int idx = hashValue % BUCKET_SIZE;


	//List<Pair> list;// = List<Pair>::bucket[idx];
	//List<Pair>::ConstIterator iter = list.begin();

	//
	//for (; (*iter).key == key && iter != list.cend(); ++iter);

	////
	//if (iter != list.cend()) {
	//	(*iter).value = value;
	//	return true;
	//}
	//else return Dictionary<K, V>::bucket[idx].Insert(Pair(key, value));

	List<V> list;
	List<typename V>::Iterator;
	auto iter = list.cbegin();
	bool is = iter == list.cbegin();

	return true;
}





template<class K, class V>
V &Dictionary<K, V>::Find(const K &key) {
	size_t hashValue = std::hash<K>()(key);
	unsigned int idx = hashValue % BUCKET_SIZE;


	//Dictionary<K, V>::bucket[idx].Insert(Pair(key, value));
	return V();
}
