/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include "split.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void add(Node*& head, int a);
void print(Node* head);
void deleteList(Node*& head);

int main(int argc, char* argv[])
{
    srand(time(0));

    int cur, last = 0;
    Node* list = nullptr;
    for (int i = 0; i < 10; i++){
        cur = (rand()%7)+last;
        add(list, cur);
        last = cur;
    }
    print(list);

    Node* even = nullptr;
    Node* odd = nullptr;

    split(list, even, odd);

    print(even);
    print(odd);

    deleteList(even);
    deleteList(odd);
}


void add(Node*& head, int a){
    if (head == nullptr){
        head = new Node(a, nullptr);
    }
    else{
        Node* current = head;
        while (current->next != nullptr){
            current = current-> next;
        }
        Node* add = new Node(a, nullptr);
        current->next = add;
    }
}

void print(Node* head){
    Node* current = head;
    while (current != NULL){
        cout << current->value << ' ';
        current = current-> next;
    }
    cout << endl;
}

void deleteList(Node*& head){
    Node* current = head;
    while (current != NULL){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}