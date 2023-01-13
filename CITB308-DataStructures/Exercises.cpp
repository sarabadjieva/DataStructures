#include "Exercises.h"
#include <stdio.h>

/*�� �� ������ �������� , ����� ������ ���� ��
���������� �� ������ ����� � ������ ����� �� �����.*/
void Exercises::ex1() {
	Tree<int> t = tree_generateRand<int>();
	Tree<int>::PositionList pl = t.position();
	for (int i = 0; i < pl.size() - 1; i++)
	{
		bool checked = false;
		for (int j = i - 1; j >= 0 ; j--){
			if (*pl.at(j) == *pl.at(i)) checked = true;
		}

		if (checked) continue;

		//naive, could be done with map
		int n = 1;
		for (int j = i + 1; j < pl.size(); j++) {
			if (*pl.at(j) == *pl.at(i)) n++;
		}

		std::cout << *pl[i] << ": " << n << std::endl;
	}
}

/* �� �� ������ �������� , ����� ������� ��������
�� ����� ���������� �� ������ ����� , ����� ���� ����� k ��
���� ����� , ������ k e ������ ���������� �����.*/
void Exercises::ex2() {
	Tree<int> t = tree_generateRand<int>();
	Tree<int>::PositionList pL = t.position();

	int k;

	do {
		std::cout << "Enter k: ";
		std::cin >> k;
	} while (k > t.position().size());

	for (int i = 0; i < t.size(); i++)
	{
		//with or without root?
		if (k == tree_getChildrenCount<int>(pL.at(i)) - 1) { std::cout << "FOUND AT INDEX: " << i << "; " << *pL.at(i) << std::endl; }
	}
}

/*������ � ����� T . ���� i � ������� T ��������
����������� �� ��������� �� , ����� �� ������� �� ���������� i
�� ������ . �� �� �������� �������, ����� ������ ����������
���� � ������ �����*/
void Exercises::ex3() {
	Tree<int> t = tree_generateRand<int>();

	int depth;
	std::cout << "Enter depth: ";
	std::cin >> depth;

	Tree<int>::PositionList pL = t.position();
	for (int i = 0; i < pL.size(); i++)
	{
		if (t.depth(pL.at(i)) == depth) {
			std::cout << "Depth found at idx: " << i << " with value " << *pL.at(i) << std::endl;
		}
	}
}

/*������������ ������� �����, ������ ����� �����
��������� ������� ����������� ��������. �������� ��������
����� �������, ��� �������, ��� �������� � ������ �� ������
��������� � �������*/
void Exercises::ex4() {
	LinkedBinaryTree<int> lTree = binTree_generateRand<int>();
	Vector<LinkedBinaryTree<int>::Position> pL = lTree.positions();

	int sum = 0;
	int max = 0;
	for (int i = 0; i < pL.size(); i++)
	{
		sum += *pL.at(i);
		if (*pL.at(i) > max) max = *pL.at(i);
	}

	int min = max;
	for (int i = 0; i < pL.size(); i++)
	{
		if (*pL.at(i) < min) min = *pL.at(i);
	}

	char buffer[200];
	sprintf_s(buffer, 200, "Min: %d, max: %d, sum: %d",  min, max, sum);
	std::cout << buffer;
}

/*������������ ������� ����� . �����������
�������, ����� ������ ���������� ����� �� ������������� ��
��� ������� �����*/
void Exercises::ex5() {
	LinkedBinaryTree<int> lTree = binTree_generateRand<int>();
	Vector<LinkedBinaryTree<int>::Position> pL = lTree.positions();

	for (int i = 0; i < pL.size(); i++)
	{
		pL.at(i).swapChildren();
	}

	std::cout << std::endl << std::endl << std::endl;
	lTree.print();
}

/*������������ ���������� �� ��������� �
����������� ������, ����� � ������ �� ����*/
void Exercises::ex6() {
	NodeList<int> l1;

	srand(time(0));

	/// Insert random values
	for (int i = 0; i < 10; i++) {
		l1.insert_back(0 + rand() % 101);
	}

	/// Print original list
	typename NodeList<int>::Iterator it = l1.begin();
	while (it != l1.end()) {
		std::cout << *(it) << " ";
		++it;
	}

	std::cout << std::endl;

	PriorityQueue<int, LexCompare> pqueue2;
	l1 = PriorityQueueSort<int, LexCompare>(l1, pqueue2);

	/// Print result list
	it = l1.begin();
	while (it != l1.end()) {
		std::cout << *(it) << " ";
		++it;
	}
}

/*������������ ����������� ������, � ������� ��
����� �� �������� ��������� �� ������ �� �����.
��������� : 
������� �� ������ �� n ����� [ a 1 , a 2 , ..., a n ] e ������� �� ����������� ������
������ n � ������� �����, ��������� � �������� ������� �� ������� n / 2 �
����������� ������ �� �����.
������ n � ����� �����, ��������� � ������ ������������� �� ����� ������
�������� � ����������� ������ �� �����.*/
void Exercises::ex7() {
	PriorityQueue<int, LexCompare> pq = pQueue_generateRand<int, LexCompare>();
	NodeList<int>* nL = pq.getList();
	NodeList<int>::Iterator it = nL->begin();
	int size = nL->size();

	int midIdx = size / 2;
	while (--midIdx > 0) {
		it++;
	}
	int mid = *it;

	if (size % 2 == 0) {
		int b = *(++it);
		std::cout << "Mid: " << (mid + b)/2;
	}
	else {
		std::cout << "Mid: " << mid;
	}
}

/*�������� ��������, ����� ��������� �� �����������
�� ������ ������ � �� n �����, ���� ����� k � ���� ����� l .
���������� ������ �� ������ k �� ��� ����� ������� l �� ���
����� ������� � � , ������ � ������������������� �������� ��
k ��� ��� ����� � l ��� ��� �����*/
void Exercises::ex8() {
	PriorityQueue<int, LexCompare> pq = pQueue_generateRand<int, LexCompare>();

	int k, l;
	do {
		std::cout << "Enter k: ";
		std::cin >> k;
		std::cout << "Enter l: ";
		std::cin >> l;
	} while (k <= 0 || l <= 0 || k > pq.size() || l > pq.size());

	NodeList<int>* nL = pq.getList();
	NodeList<int>::Iterator it = nL->begin();
	while (--k > 0) {
		it++;
	}
	int min = *it;

	it = nL->end();
	while (l-- > 0) {
		it--;
	}
	int max = *it;

	std::cout << "K and L: " << min << " " << max;
}

/*�������� �������� , ����� ��������� �� �����������
�� ������ M ������ �� �����. ���� ���� ���������� ������ ��
���� ���������� M ������ � ���� ������ , ����� �� ����
��������� ��� �������� ���. ������ ���������� ���� ������ .
����������� ����������� ������ �������� �� ���*/
void Exercises::ex9() {
	int M;
	do {
		std::cout << "Enter M: ";
		std::cin >> M;
	} while (M <= 0);

	HeapPriorityQueue<int, LexCompare> heapQ;
	for (int i = 0; i < M; i++)
	{
		HeapPriorityQueue<int, LexCompare>& pq = heap_generateRand<int, LexCompare>();
		heapQ.append(pq);
	}

	for (int i = 0; i < M; i++)
	{

	}
}

/*����� � ����� zipcodes.txt , ����� ������� ��������
������ �� �������. �������� ��������, ����� ������� �����
zipcodes.txt � ��������� ���������� ������ ��� ������. ���� ����
���������� ������ �� ������ ������� � �� ������� Map , ������
���������� ������ �� �������, � ���� �� ���������� �� ���� ����
��� ����� zipcodes.txt � ����������, �.�. �� �������� ( ���� ,
�������� ), ���� �������� ���, �������� ���� ���������� ��
��������� ��� (�����) ��� ����� zipcodes.txt.*/
void Exercises::ex10() {

}

/* HashMap �������� �������� , ����� �������� ������ �����, ����� �� ������
������� ���� ���� � ������ ������ . ��������, ��� ����� ��������� ������
{4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 6, 6, ������ �� � ���������� �� �������� {5, 3, 3,
5*/
void Exercises::ex11() {

}

/*HashMap �������� �������� , ����� ���� ����� ���� �� ����� ����� ����� �
������ ������ �� �����.
������
: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
2
--> 2 ����
3
--> 4 ����
4
--> 3 ����*/
void Exercises::ex12() {

}