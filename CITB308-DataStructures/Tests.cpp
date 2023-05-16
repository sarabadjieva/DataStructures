#include "Tests.h"

void Tests::testQueue() {
    Queue<int>* q = new Queue<int>(testSize);

    for (int i = 0; i < testSize; i++) {
        q->enqueue(i);
    }

    std::cout << *q;
    delete q;
}

void Tests::testStack() {
    Stack<int>* st = new Stack<int>(testSize);

    for (int i = 0; i < testSize; i++) {
        st->push(i);
    }

    std::cout << *st;
    std::cout << "Reversed " << st->reverse();
    delete st;
}

void Tests::testVector() {
    Vector<int>* vec = new Vector<int>();

    for (int i = 0; i < testSize; i++) {
        vec->insert(i, i);
    }

    std::cout << *vec;
    vec->replaceAtRank(0, 100);
    vec->remove(0);
    vec->insert_back(120);
    std::cout << *vec;
    delete vec;
}

void Tests::testNodeList() {
    NodeList<int>* list = new NodeList<int>();

    for (int i = 0; i < testSize; i++) {
        list->insert_back(i);
    }

    NodeList<int>::Iterator it;

    it = list->begin();
    it.operator++(3);
    list->insert(it, 100);

    it = list->begin();
    it++;
    list->remove(it);
    
    std::cout << *list;
}

void Tests::testTree() {
    Tree<int>* tree = new Tree<int>();

    tree->insert(tree->root(), 1);
    tree->insert(tree->root(), 2);
    tree->insert(tree->root(), 3);

    Tree<int>::PositionList pl = tree->position();
    Tree<int>::Position p = pl.at(2);
    tree->insert(p, 10);
    std::cout << *tree;
}

void Tests::testLinkedBinaryTree() {
    LinkedBinaryTree<int>* lbTree = new LinkedBinaryTree<int>();
    lbTree->setRoot(0);
    lbTree->expandExternal(lbTree->getRoot());
    lbTree->setLeft(lbTree->getRoot(), 1);
    lbTree->setLeft(lbTree->getRoot(), 10);
    lbTree->setRight(lbTree->getRoot(), 2);
    lbTree->expandExternal(lbTree->getRoot().left());
    lbTree->setLeft(lbTree->getRoot().left(), 100);
    lbTree->setRight(lbTree->getRoot().left(), 200);

    std::cout << "\n\n";
    std::cout << *lbTree;
    lbTree->removeAboveExternal(lbTree->getRoot().left().left());
    std::cout << "\n\n";
    std::cout << *lbTree;

    std::cout << "depth: " << lbTree->depth(lbTree->getRoot().left().left()) << std::endl;

    std::cout << "height: " << lbTree->height(lbTree->getRoot()) << std::endl;
}

void Tests::testPriorityQueue() {
    PriorityQueue<int, LexCompare> pqueue;

    std::cout << "Size: " << pqueue.size() << std::endl;

    pqueue.insert(5);
    pqueue.insert(0);
    pqueue.insert(-1);
    pqueue.insert(2);
    pqueue.insert(3);
    pqueue.insert(1);

    pqueue.removeMin();

    std::cout << pqueue.min() << std::endl;

    std::cout << pqueue << "-------------------" << std::endl << std::endl;

    /// Task 1.
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
    l1 = PriorityQueueSort(l1, pqueue2);

    /// Print result list
    it = l1.begin();
    while (it != l1.end()) {
        std::cout << *(it) << " ";
        ++it;
    }

    std::cout << std::endl;
}

void Tests::testVectorCompleteTree() {
    VectorCompleteTree<int>* vcTree = new VectorCompleteTree<int>();
}

void Tests::testHeapPriorityQueue() {

}

void Tests::testListMap() {
    ListMap<int, int> map;
    for (int i = 0; i < testSize; i++)
    {
        map.put(i * 10, i);
    }

    map.print();
}

void Tests::testHashMap() {
    HashMap<int, int, HComp> hash;
    for (int i = 0; i < testSize; i++)
    {
        hash.put(i*100, i);
        hash.put(i*100, i*10);
    }

    HashMap<int, char, HComp> hMap = HashMap<int, char, HComp>(200);
    char c = 'a';

    for (int i = 1; i <= 26; i++)
    {
        int key = i;
        hMap.put(key, c);
        c = c + 1;
    }

    hMap.print();
}

void Tests::testSearchTree() {
    SearchTree< Pair<int, std::string> > tree;
    tree.insert(1, "ONE");
    tree.insert(10, "TEN");
    tree.insert(100, "HUNDRED");
    tree.insert(1000, "THOUSAND");
    tree.insert(2, "TWO");
    std::cout << std::endl;
    std::cout << std::endl;
    tree.print();
    tree.insert(0, "ZERO");
    tree.insert(0, "ZERO");
    tree.insert(1, "ONE");
    std::cout << std::endl;
    std::cout << std::endl;
    tree.print();
    tree.erase(1);
    tree.erase(1);

    std::cout << std::endl << std::endl << (*tree.find(2)).value() << std::endl << std::endl;
    tree.print();
    std::cout << tree.size() << std::endl;
}

void Tests::testSorting()
{
    int size = 10;
    int arr[] = {1, 9, 2, 7, 6, 43, 6, 8, 5, 1};
    int testArr[10] = {};

    std::cout << "Bubble sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::bubble_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Insertion sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::insertion_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Cocktail sort - bubble\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::cocktail_sort_bubble(testArr, size);
    //std::cout << '\n';

    std::cout << "Selection sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::selection_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Cocktail sort - selection\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::cocktail_sort_selection(testArr, size);
    //std::cout << '\n';

    std::cout << "Gnome sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::gnome_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Merge\n";
    //std::copy(arr, arr + size, testArr);
    //int b[] = { 4, 5, 6, 70, 1, 0, 5, 2, 6, 7 };
    //Sorting::merge(testArr, b, size, size);
    //std::cout << '\n';

    std::cout << "Merge sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::merge_sort(testArr, 0, size - 1);
    //std::cout << '\n';

    std::cout << "Natural merge sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::natural_merge_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Count sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::count_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Radix sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::radix_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Heap sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::heap_sort(testArr, size);
    //std::cout << '\n';

    std::cout << "Binary insertion sort\n";
    std::copy(arr, arr + size, testArr);
    Sorting::binary_insertion_sort(testArr, size);
    std::cout << '\n';

    std::cout << "Intro sort\n";
    std::copy(arr, arr + size, testArr);
    Sorting::intro_sort(testArr, size);
    std::cout << '\n';

    std::cout << "Quick sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::quick_sort(testArr, 0, size - 1);
    //std::cout << '\n';

    std::cout << "Bucket sort\n";
    //std::copy(arr, arr + size, testArr);
    //Sorting::bucket_sort(testArr, size);
    //std::cout << '\n';
}

void Tests::testGraphs()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    std::cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);
    std::cout << "\nFollowing is Depth First Traversal "
        << "(starting from vertex 2) \n";
    g.DFS(2);

    std::cout << std::endl << std::endl;
    int V = 9;
    Graph wG(V);

    // making above shown graph
    wG.addEdge(0, 1, 4);
    wG.addEdge(0, 7, 8);
    wG.addEdge(1, 2, 8);
    wG.addEdge(1, 7, 11);
    wG.addEdge(2, 3, 7);
    wG.addEdge(2, 8, 2);
    wG.addEdge(2, 5, 4);
    wG.addEdge(3, 4, 9);
    wG.addEdge(3, 5, 14);
    wG.addEdge(4, 5, 10);
    wG.addEdge(5, 6, 2);
    wG.addEdge(6, 7, 1);
    wG.addEdge(6, 8, 6);
    wG.addEdge(7, 8, 7);

    wG.dijkstra(0);

    wG.floyd();
}