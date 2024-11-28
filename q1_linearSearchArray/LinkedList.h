#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include "Node.h"


class LinkedList
{
    private:
        Node *head, *tail;

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


        int getDataByIndex(int indx){
            int indxData = 0;
            int currIndx = 0;
            Node *current = head;
            if(current == NULL){
                cout<<"\nEmpty List\n";
                return 0;
            }
            else{
                while(current != NULL){
                    if(indx == currIndx){
                        return current->Data;
                    }
                    currIndx++;
                    current = current->next;
                }
            }
            if(indx > currIndx){
                cout<<"\nIndex out of range\n";
            }
        }

        ///Return Count of Nodes
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

};

#endif // LINKEDLIST_H
