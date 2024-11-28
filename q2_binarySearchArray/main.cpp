#include <iostream>

#define ARR_SIZE        7
#define SEARCH_ELEMENT  55

using namespace std;

void Swap(int&, int&);
int bubbleSort(int*,int);
int binarySearch(int*, int, int);

/***************************************************************************************/

int main()
{
    int myArr[ARR_SIZE] = {11,22,33,44,55,66,77}; ///Array MUST be sorted for binary search

    if(binarySearch(myArr, ARR_SIZE, SEARCH_ELEMENT) != -1){
        cout<<"\n\n"<<SEARCH_ELEMENT<<" found at index "<<binarySearch(myArr, ARR_SIZE, SEARCH_ELEMENT)<<"\n\n";
    }
    else
        cout<<"\n\nNot Found\n\n";
    return 0;
}

/****************************************************************************************/

void Swap(int& first, int& second){
    first  = first+second;
    second = first-second;
    first  = first-second;
}

int bubbleSort(int* arr,int Size){
    int sorted=0;
    for(int j=0;sorted==0;j++){
        sorted=1;
        for(int i=0; i<Size-1-j; i++){
            if(arr[i]>arr[i+1]){
                Swap(arr[i],arr[i+1]);
                sorted=0;
            }
        }
    }
    return sorted;
}

int binarySearch(int* arr, int Size, int reqElement){
    int Start=0, End=Size-1;
    if(bubbleSort(arr, Size)){      ///in case the array was not sorted
        while(Start <= End){
            int Mid = (End+Start)/2;
            if(arr[Mid] == reqElement){
                return Mid;
            }
            else if(arr[Mid] > reqElement){
                End = Mid-1;
            }
            else if(arr[Mid] < reqElement){
                Start = Mid+1;
            }
        }
    }
    return -1;
}
