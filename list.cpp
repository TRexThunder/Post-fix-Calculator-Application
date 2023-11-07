#include <iostream>
#include "list.h"
#include <stdexcept>

using namespace std;

List::List(){
    try{
        size=0;
        sentinel_head=new Node;
        sentinel_tail=new Node;
        sentinel_head->next=sentinel_tail;
        sentinel_head->prev=sentinel_tail;
        sentinel_tail->prev=sentinel_head;
        sentinel_tail->next=sentinel_head;
    }
    catch(bad_alloc&){
        throw runtime_error("Out of Memory");
    }
}

List::~List(){
    Node* n=sentinel_head;
    while (true){
        if (n==sentinel_tail){
            delete n;
            break;
        }
        else{
            Node* m=n->next;
            delete n;
            n=m;
        }
    }
}

void List::insert(int v){
    try{
        Node* n=new Node(v, sentinel_tail, sentinel_tail->prev);
        sentinel_tail->prev=n;
        n->prev->next=n;
        size+=1;
    }
    catch(bad_alloc&){
        throw runtime_error("Out of Memory");
    }
}

int List::delete_tail(){
    if (sentinel_tail->prev!=sentinel_head){
        Node* n=sentinel_tail->prev;
        int ans=n->get_value();
        sentinel_tail->prev=n->prev;
        n->prev->next=sentinel_tail;
        delete n;
        size-=1;
        return ans;
    }
    else return -1;
}

int List::get_size(){
    return size;
}

Node* List::get_head(){
    return sentinel_head;
}