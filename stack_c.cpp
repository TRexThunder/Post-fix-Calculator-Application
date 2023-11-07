#include <iostream>
#include "stack_c.h"
#include <stdexcept>

using namespace std;

Stack_C::Stack_C(){
    try{
        stk=new List;
    }
    catch(bad_alloc){
        throw runtime_error("Out of Memory");
    }
}

Stack_C::~Stack_C(){
    delete stk;
}

void Stack_C::push(int data){
    stk->insert(data);
}

int Stack_C::pop(){
    if (stk->get_size()==0) throw runtime_error("Empty Stack");
    else return stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx){
    int sz=stk->get_size();
    if ((sz<=0) || (idx+1>sz)) throw runtime_error("Index out of range");
    else{
        Node* n=stk->get_head()->prev->prev;
        for (int i=0; i<idx; i++){
            n=n->prev;
        }
        return n->get_value();
    }
}

int Stack_C::get_element_from_bottom(int idx){
    int sz=stk->get_size();
    if ((sz<=0) || (idx+1>sz)) throw runtime_error("Index out of range");
    else{
        Node* n=stk->get_head()->next;
        for (int i=0; i<idx; i++){
            n=n->next;
        }
        return n->get_value();
    }
}

void Stack_C::print_stack(bool top_or_bottom){
    if (top_or_bottom){
        Node* n=stk->get_head()->prev->prev;
        while (n!=stk->get_head()){
            cout<<n->get_value()<<'\n';
            n=n->prev;
        }
    }
    else{
        Node* n=stk->get_head()->next;
        while (n!=stk->get_head()->prev){
            cout<<n->get_value()<<'\n';
            n=n->next;
        }
    }
}

int Stack_C::add(){
    if (stk->get_size()<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)+get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_C::subtract(){
    if (stk->get_size()<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)-get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_C::multiply(){
    if (stk->get_size()<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)*get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_C::divide(){
    if (stk->get_size()<2) throw runtime_error("Not Enough Arguments");
    else{
        int a=get_element_from_top(0), b=get_element_from_top(1);
        if (a==0) throw runtime_error("Divide by Zero Error");
        else{
            int ans=b/a;
            pop();
            pop();
            if ((ans<=0) && (a*ans!=b)) ans-=1;
            push(ans);
            return ans;
        }
    }
}

List* Stack_C::get_stack(){
    return stk;
}

int Stack_C::get_size(){
    return stk->get_size();
}