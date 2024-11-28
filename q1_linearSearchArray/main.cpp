#include <iostream>
#include "LinkedList.h"

#define ARR_SIZE        7
#define SEARCH_ELEMENT  4

using namespace std;

int linearSearch_disp(int*, int, int);
int linearSearch(int*, int, int, int*);
int linearSearch_returnLinkedList(int*, int, int, LinkedList&);

int main()
{
    int myArr[ARR_SIZE] = {2,3,4,2,4,5,6};
    int indexArr[ARR_SIZE] = {0};
    LinkedList indexList;

    ///Using a Display-Only Function
    cout<<"\n>> Using a Display-Only Function..";
    cout<<"\nElement "<<SEARCH_ELEMENT<<" Number of Occurrences is: "<<linearSearch_disp(myArr, ARR_SIZE, SEARCH_ELEMENT)<<"\n\n";

    ///Using a Function that Returns the Indices in an Array
    cout<<"\n\n>> Using a Function that Returns the Indices in an Array (inefficient method)..";
    int numOcc = linearSearch(myArr, ARR_SIZE, SEARCH_ELEMENT, indexArr);
    if(numOcc)
        for(int n=0;n<numOcc;n++){
            cout<<"\n"<<SEARCH_ELEMENT<<" found at index "<<indexArr[n];
        }
    else
        cout<<"\nElement "<<SEARCH_ELEMENT<<" Not Found";


    ///Using a Function that Returns the Indices in a Linked List
    cout<<"\n\n>> Using a Function that Returns the Indices in a Linked List..";
    int numOcc2 = linearSearch_returnLinkedList(myArr, ARR_SIZE, SEARCH_ELEMENT, indexList);
    if(numOcc2)
        for(int n=0;n<numOcc;n++){
            cout<<"\n"<<SEARCH_ELEMENT<<" found at index "<<indexList.getDataByIndex(n);
        }
    else
        cout<<"\nElement "<<SEARCH_ELEMENT<<" Not Found";
    cout<<"\n\n";

    return 0;
}

///display only
int linearSearch_disp(int* arr, int Size, int reqElement){
    int numOccurences = 0;
    for(int i=0;i<Size;i++){
        if(arr[i] == reqElement){
            cout<<"\nElement "<<reqElement<<" found at index "<<i;
            numOccurences++;
        }
    }
    if(!numOccurences)
        cout<<"\nElement "<<reqElement<<" Not Found";
    return numOccurences;
}

///returning indices
int linearSearch(int* arr, int Size, int reqElement, int* indices){
    int numOccurences = 0;
    for(int i=0;i<Size;i++){
        if(arr[i] == reqElement){
            indices[numOccurences] = i;
            numOccurences++;
        }
    }
    return numOccurences;
}


///returning indices using a Linked List
int linearSearch_returnLinkedList(int* arr, int Size, int reqElement, LinkedList& indicesList){
    int numOccurences = 0;
    for(int i=0;i<Size;i++){
        if(arr[i] == reqElement){
            indicesList.add(i);
            numOccurences++;
        }
    }
    return numOccurences;
}
