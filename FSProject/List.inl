
/*--- ConstIterator ---*/



/*--- �I�y���[�^ ---*/

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

/*--- �I�y�[���^ ---*/

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

/*--- �����o�[�֐� ---*/

template<class T>
bool List<T>::Insert(List<T>::ConstIterator iter, const T &value) {
	// null�`�F�b�N
	if (iter.GetNode() == nullptr) return false;
	// ���֌W�̃��X�g
	if (iter.pParent != this) return false;

	Node *pNode = new Node(value);


	// �ǉ�����
	Link(iter.GetNode(), pNode);


	count++;

	return true;
}





template<class T>
bool List<T>::Remove(List<T>::ConstIterator iter) {
	// null�`�F�b�N
	if (iter.GetNode() == nullptr) return false;
	// �_�~�[�`�F�b�N
	if (iter.GetNode() == &dummy) return false;
	// ���֌W�̃��X�g
	if (iter.pParent != this) return false;



	Node *pNode = iter.GetNode();

	// �폜����
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
	// null�`�F�b�N
	if (func == nullptr) return;

	if (first == last || first == --Iterator(last)) return;

	Iterator pivot = first;
	Iterator tmp;

	// �擪���Ɩ������Ńf�[�^�𕪊�������

	for (auto i = ++Iterator(first); i != last; ++i) {
		// ������l�Ɣ�r�������ʓ��Ă͂܂�Ȃ���΁A�擪���Ɉړ�
		if (func(*i, *pivot)) {
			tmp = i--;

			// �擪�ֈړ�
			Leave(tmp);
			Link(first, tmp);

			// �擪�C�e���[�^���X�V
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

	// �m�[�h��S�č폜
	while (pNode != &dummy) {
		pTmp = pNode;
		pNode = pNode->pNext;

		delete pTmp;
	}

	// ���Z�b�g
	count = 0;
	dummy.pNext = dummy.pPrev = &dummy;
}





template<class T>
void List<T>::Link(Node *pThis, Node *pOther) {
	if (pThis == pOther) return;

	// �q���鏈��
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
	// �؂藣������
	if (pThis->pNext) pThis->pNext->pPrev = pThis->pPrev;
	if (pThis->pPrev) pThis->pPrev->pNext = pThis->pNext;
	pThis->pNext = pThis->pPrev = nullptr;
}





template<class T>
void List<T>::Leave(Iterator thisIter) {
	Leave(thisIter.GetNode());
}





/*--- �A�N�Z�T�֐� ---*/

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
