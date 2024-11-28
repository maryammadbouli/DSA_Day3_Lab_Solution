#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include "Node.h"


class LinkedList
{
    private:
        Node *head, *tail;

        Node* getNodeData(int data){
            Node *current = head;
            while(current != NULL){
                if(current->Data == data)
                    return current;
                current = current->next;
            }
            return NULL;
        }

    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        ///Insert a new node at the end
        void add(int data){
            Node *newNode = new Node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        ///Display all list data
        void display(){
            Node *current = head;
            if(current == NULL){
                cout<<"\nEmpty List\n";
                return;
            }
            while(current != NULL){
                cout<<current->Data<<"\t";
                current = current->next;
            }
            cout<<endl;
        }

        ///Get node count
        int getCount(){
            int nodeCount = 0;
            Node *current = head;
            if(current == NULL){
                return nodeCount;
            }
            else if(current == tail){
                return ++nodeCount;
            }
            else{
                while(current != NULL){
                    nodeCount++;
                    current = current->next;
                }
                return nodeCount;
            }
        }

        ///general function
        void Swap(int& first, int& second){
            first  = first+second;
            second = first-second;
            first  = first-second;
        }

        ///Bubble Sorting Function (swapping data only)
        int bubbleSort_dataSwap(){
            int sorted=0;
            Node* current = this->head;
            for(int i=0;sorted==0;i++){
                current = head;
                sorted = 1;
                while(current->next != NULL){
                    if((current->Data) > (current->next->Data)){
                        Swap(current->Data, current->next->Data);
                        sorted=0;
                    }
                    current = current->next;
                }
            }
            if(sorted)
                return 1;
            else
                return 0;
        }
};

#endif // LINKEDLIST_H
