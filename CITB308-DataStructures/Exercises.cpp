#include "Exercises.h"
#include <stdio.h>

/*Да се напише програма , която намира броя на
срещанията на дадено число в дадено дърво от числа.*/
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

/* Да се напише програма , която извежда корените
на онези поддървета на дадено дърво , които имат точно k на
брой върха , където k e дадено естествено число.*/
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

/*Дадено е дърво T . Ниво i в дървото T наричаме
множеството от върховете му , които се намират на разстояние i
от корена . Да се дефинира функция, която намира произволно
ниво в дадено дърво*/
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

/*Реализирайте двоично дърво, където всеки възел
съхранява някаква целочислена стойност. Напишете програма
която извежда, най малката, най голямата и сумата от всички
стойности в дървото*/
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

/*Реализирайте двоично дърво . Дефинирайте
функция, която намира огледалния образ на реализираното от
вас двоично дърво*/
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

/*Реализирайте алгоритъма за сортиране с
приоритетна опашка, който е описан по горе*/
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

/*Реализирайте приоритетна опашка, с помощта на
която да намерите медианата на редица от числа.
Дефиниция : 
Медиана на редица от n числа [ a 1 , a 2 , ..., a n ] e средата на сортираната редица
Когато n е нечетно число, медианата е средният елемент на позиция n / 2 в
сортираната редица от числа.
Когато n е четно число, медианата е средно аритметичното на двата средни
елемента в сортираната редица от числа.*/
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

/*Напишете програма, която позволява на потребителя
да въведе редица А от n числа, цяло число k и цяло число l .
Програмата трябва да изведе k ти най малък елемент l ти най
голям елемент в А , сумата и средноаритметичната стойност на
k тия най малък и l тия най голям*/
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

/*Напишете програма , която позволява на потребителя
да въведе M редици от числа. След това програмата трябва да
слее въведените M редици в една редица , която да бъде
подредена във възходящ ред. Изведе получената нова редица .
Използвайте Приоритетна опашка базирана на Хип*/
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

/*Даден е файла zipcodes.txt , който съдържа пощенски
кодове на градове. Напишете програма, която прочита файла
zipcodes.txt и съхранява пощенските кодове във вектор. След това
програмата трябва да обходи вектора и да създаде Map , където
пощенските кодове са ключове, а броя на срещанията на даде ключ
във файла zipcodes.txt е стойността, т.е. за двойката ( ключ ,
стойност ), ключ пощенски код, стойност брой повторения на
пощенския код (ключа) във файла zipcodes.txt.*/
void Exercises::ex10() {

}

/* HashMap Напишете програма , която премахва всички числа, които се срещат
нечетен брой пъти в дадена редица . Например, ако имаме началната редица
{4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 6, 6, трябва да я редуцираме до редицата {5, 3, 3,
5*/
void Exercises::ex11() {

}

/*HashMap Напишете програма , която брои колко пъти се среща всяко число в
дадена редица от числа.
Пример
: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
2
--> 2 пъти
3
--> 4 пъти
4
--> 3 пъти*/
void Exercises::ex12() {

}