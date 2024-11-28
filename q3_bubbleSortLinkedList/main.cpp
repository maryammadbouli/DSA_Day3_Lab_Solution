#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList myList, myList_sort2;

    myList.add(3);
    myList.add(2);
    myList.add(4);
    myList.add(5);
    myList.add(8);
    myList.add(6);

    cout<<"\nList before Sorting..\n";
    myList.display();

    cout<<"\n\nList after Sorting (swapping data only)..\n";
    if(myList.bubbleSort_dataSwap())
        myList.display();
    else
        cout<<"\nSorting Failed\n\n";
    return 0;
}
