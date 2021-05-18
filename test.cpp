#include <iostream>
#include <exception>
#include <ctime>

#include "lista.hpp"
using namespace std;

int getRandomNuber(int max) {
    int number = rand() % max;
    return number;
}

void printList(Lista<int> &list) {
    for(int i=0;i<list.size();i++)
    {
        if(i !=0 ) {
            cout << ", ";
        }

        cout<<"{[" << i << "]=" << list.get(i) << "}";
    }

    cout << endl;
}

// fills list with random data
void fillListWithData(int elementsCount, Lista<int> &list) {
    for(int i=0;i<elementsCount;i++)
    {
        list.push(getRandomNuber(1000));
    }
}

void testSimple() {
    cout << "doing simple test ..." << endl;
    Lista<int> list;
    fillListWithData(getRandomNuber(20), list);
    printList(list);
    cout << "simple test done" << endl;
}

bool testPush() {
    cout << "testing function push ..." << endl;
    Lista<int> list;
    int tab[10];
    for(int i=0;i<10;i++)
    {
        tab[i]=getRandomNuber(1000);
        list.push(tab[i]);
    }
    printList(list);
    for(int i=0;i<10;i++)
    {
        if(tab[i]!=list.get(i))
        {
            cout << "push test failed" << endl;
            return false;
        }
    }

    cout << "push test passed" << endl;
    return true;
}

bool testRemove() {
    Lista<int> list;
    int n=getRandomNuber(997)+3;
    fillListWithData(n,list);
    int elem0 = list.get(0);
    list.remove(elem0);
    int elemlast = list.get(list.size()-1);
    list.remove(elemlast);
    int elemrandom = list.get(getRandomNuber(list.size()-2)+1);
    list.remove(elemrandom);

    if((n-3)==list.size())
    {
        cout << "remove test passed" << endl;
        return true;
    }
    
    cout << "remove test failed" << endl;
    return false;    

}

bool testContains() {
    Lista<int> list;
}

bool testSize() {
    Lista<int> list;
}

bool testInsert() {
    Lista<int> list;
}


int main(int argc, char* argv[]) {
    srand((unsigned)time(NULL));

    testSimple();
    if(!testPush()) {
        return -1;
    }
    if(testRemove())  {
        return -1;
    }
    if(testContains())  {
        return -1;
    }
    if(testSize())  {
        return -1;
    } 
    if(testInsert())  {
        return -1;
    }
    return 0;
}