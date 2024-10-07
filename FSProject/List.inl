
/*--- ConstIterator ---*/



/*--- オペレータ ---*/

template<class T>
typename List<T>::ConstIterator &List<T>::ConstIterator::operator++() {
	assert(pNode);
	assert(pNode != &pParent->dummy);

	pNode = pNode->pNext;
	return *this;
}





template<class T>
typename List<T>::ConstIterator &List<T>::ConstIterator::operator--() {
	assert(pNode);
	assert(pNode->pPrev != &pParent->dummy);

	pNode = pNode->pPrev;
	return *this;
}





template<class T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int) {
	assert(pNode);
	assert(pNode != &pParent->dummy);

	pNode = pNode->pNext;
	return ConstIterator(pNode->pPrev, pParent);
}





template<class T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int) {
	assert(pNode);
	assert(pNode->pPrev != &pParent->dummy);

	pNode = pNode->pPrev;
	return ConstIterator(pNode->pNext, pParent);
}





template<class T>
T const &List<T>::ConstIterator::operator* () const {
	assert(pNode);
	assert(pNode != &pParent->dummy);

	return pNode->value;
}





template<class T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator=(const List<T>::ConstIterator &iter) {
	pParent = iter.pParent;
	pNode = iter.pNode;
	return *this;
}





template<class T>
bool List<T>::ConstIterator::operator==(List<T>::ConstIterator &iter) const {
	return pNode == iter.pNode;
}





template<class T>
bool List<T>::ConstIterator::operator!=(List<T>::ConstIterator &iter) const {
	return !(*this == iter);
}




/*--- Iterator ---*/

/*--- オペーレタ ---*/

template<class T>
typename List<T>::Iterator &List<T>::Iterator::operator++() {
	++(*((ConstIterator *)this));

	return *this;
}

template<class T>
typename List<T>::Iterator &List<T>::Iterator::operator--() {
	--(*((ConstIterator *)this));

	return *this;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
	Iterator old = *this;

	(*((ConstIterator *)this))++;

	return old;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
	Iterator old = *this;

	(*((ConstIterator *)this))--;

	return old;
}

template<class T>
T &List<T>::Iterator::operator*() {
	assert(ConstIterator::pNode);
	assert(ConstIterator::pNode != &ConstIterator::pParent->dummy);

	return ConstIterator::pNode->value;
}

template<class T>
bool List<T>::Iterator::operator==(List<T>::Iterator &iter) {
	return *((ConstIterator *)(this)) == *((ConstIterator *)(&iter));
}

template<class T>
bool List<T>::Iterator::operator!=(List<T>::Iterator &iter) {
	return *((ConstIterator *)(this)) != *((ConstIterator *)(&iter));
}





/*--- List ---*/

/*--- メンバー関数 ---*/

template<class T>
bool List<T>::Insert(List<T>::ConstIterator iter, const T &value) {
	// nullチェック
	if (iter.GetNode() == nullptr) return false;
	// 無関係のリスト
	if (iter.pParent != this) return false;

	Node *pNode = new Node(value);


	// 追加処理
	Link(iter.GetNode(), pNode);


	count++;

	return true;
}





template<class T>
bool List<T>::Remove(List<T>::ConstIterator iter) {
	// nullチェック
	if (iter.GetNode() == nullptr) return false;
	// ダミーチェック
	if (iter.GetNode() == &dummy) return false;
	// 無関係のリスト
	if (iter.pParent != this) return false;



	Node *pNode = iter.GetNode();

	// 削除処理
	if (pNode) {
		Leave(pNode);
		delete pNode;

		count--;
		return true;
	}

	return false;
}





template<class T>
void List<T>::Sort(Iterator first, Iterator last, std::function<bool(T &, T &)> func) {
	// nullチェック
	if (func == nullptr) return;

	if (first == last || first == --Iterator(last)) return;

	Iterator pivot = first;
	Iterator tmp;

	// 先頭側と末尾側でデータを分割をする

	for (auto i = ++Iterator(first); i != last; ++i) {
		// もし基準値と比較した結果当てはまらなければ、先頭側に移動
		if (func(*i, *pivot)) {
			tmp = i--;

			// 先頭へ移動
			Leave(tmp);
			Link(first, tmp);

			// 先頭イテレータを更新
			first = tmp;
		}
	}

	if (first != pivot) Sort(first, pivot, func);
	if (last != pivot) Sort(++Iterator(pivot), last, func);
}





template<class T>
void List<T>::Clear(void) {
	if (count == 0) return;

	Node *pNode = dummy.pNext;
	Node *pTmp = nullptr;

	// ノードを全て削除
	while (pNode != &dummy) {
		pTmp = pNode;
		pNode = pNode->pNext;

		delete pTmp;
	}

	// リセット
	count = 0;
	dummy.pNext = dummy.pPrev = &dummy;
}





template<class T>
void List<T>::Link(Node *pThis, Node *pOther) {
	if (pThis == pOther) return;

	// 繋げる処理
	pOther->pPrev = pThis->pPrev;
	pThis->pPrev = pOther;
	pOther->pNext = pThis;
	if (pOther->pPrev) pOther->pPrev->pNext = pOther;
}





template<class T>
void List<T>::Link(Iterator thisIter, Iterator otherIter) {
	Link(thisIter.GetNode(), otherIter.GetNode());
}





template<class T>
void List<T>::Leave(Node *pThis) {
	// 切り離す処理
	if (pThis->pNext) pThis->pNext->pPrev = pThis->pPrev;
	if (pThis->pPrev) pThis->pPrev->pNext = pThis->pNext;
	pThis->pNext = pThis->pPrev = nullptr;
}





template<class T>
void List<T>::Leave(Iterator thisIter) {
	Leave(thisIter.GetNode());
}





/*--- アクセサ関数 ---*/

template<class T>
typename List<T>::Iterator List<T>::begin(void) {
	return Iterator(dummy.pNext, this);
}





template<class T>
typename List<T>::Iterator List<T>::end(void) {
	return Iterator(&dummy, this);
}





template<class T>
typename List<T>::ConstIterator List<T>::begin(void) const {
	return ConstIterator(dummy.pNext, this);
}





template<class T>
typename List<T>::ConstIterator List<T>::end(void)const {
	return ConstIterator(&dummy, this);
}





template<class T>
typename List<T>::ConstIterator List<T>::cbegin(void) const {
	return ConstIterator(dummy.pNext, this);
}





template<class T>
typename List<T>::ConstIterator List<T>::cend(void) const {
	return ConstIterator(const_cast<Node *>(&dummy), this);
}





template<class T>
T &List<T>::front(void) {
	assert(dummy.pNext->value);
	return *dummy.pPrev->value;
}





template<class T>
T &List<T>::back(void) {
	assert(dummy.pPrev->value);
	return *dummy.pPrev->value;
}
