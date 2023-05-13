#pragma once

#include <iostream>
#include "Pair.h"
#include "Queue.h"
#include "Stack.h"
#include "Vector.h"
#include "NodeList.h"
#include "Tree.h"
#include "LinkedBinaryTree.h"
#include "PriorityQueue.h"
#include "VectorCompleteTree.h"
#include "HeapPriorityQueue.h"
#include "ListMap.h"
#include "HashMap.h"
#include "SearchTree.h"
#include "Sorting.h"
#include <cstdlib>

class Tests
{
public:
	static void run(){
        /*testQueue();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testStack();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testVector();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testNodeList();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testTree();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testLinkedBinaryTree();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testPriorityQueue();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testVectorCompleteTree();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testHeapPriorityQueue();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testListMap();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testHashMap();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";
        testSearchTree();
        std::cout << "--------------------\n";
        std::cout << "--------------------\n";*/
        testSorting();
    }

    static void testQueue();
    static void testStack();
    static void testVector();
    static void testNodeList();
    static void testTree();
    static void testLinkedBinaryTree();
    static void testPriorityQueue();
    static void testVectorCompleteTree();
    static void testHeapPriorityQueue();
    static void testListMap();
    static void testHashMap();
    static void testSearchTree();

    static void testSorting();

private:
    static const int testSize = 10;
};