
/*--- ƒƒ“ƒo[ŠÖ” ---*/

template<class K, class V>
bool Dictionary<K, V>::Insert(const K &key, const V &value) {
	size_t hashValue = std::hash<K>()(key);
	unsigned int idx = hashValue % BUCKET_SIZE;


	List<Pair> &list = List<Pair>::bucket[idx];
	auto iter = list.begin();
	for (; (*iter).key == key && iter != list.end(); ++iter);


	//
	if (iter != list.end()) {
		(*iter).value = value;
		return true;
	}
	else return Dictionary<K, V>::bucket[idx].Insert(Pair(key, value));
}





template<class K, class V>
V &Dictionary<K, V>::Find(const K &key) {
	size_t hashValue = std::hash<K>()(key);
	unsigned int idx = hashValue % BUCKET_SIZE;


	Dictionary<K, V>::bucket[idx].Insert(Pair(key, value));
}
