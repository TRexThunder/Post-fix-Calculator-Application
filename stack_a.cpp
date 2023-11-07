#include <iostream>
#include "stack_a.h"
#include <stdexcept>

using namespace std;

Stack_A::Stack_A(){
    stk[1024]={0};
    size=0;
}

void Stack_A::push(int data){
    if (size>=1024) throw runtime_error("Stack Full");
    else stk[++size-1]=data;
}

int Stack_A::pop(){
    if (size<=0) throw runtime_error("Empty Stack");
    else return stk[size---1];
}

int Stack_A::get_element_from_top(int idx){
    if ((size<=0) || (idx+1>size) || (idx<0)) throw runtime_error("Index out of range");
    else return stk[size-idx-1];
}

int Stack_A::get_element_from_bottom(int idx){
    if ((size<=0) || (idx+1>size) || (idx<0)) throw runtime_error("Index out of range");
    else return stk[idx];
}

void Stack_A::print_stack(bool top_or_bottom){
    if (top_or_bottom){
        for (int i=0; i<size; i++) cout<<stk[size-i-1]<<'\n';
    }
    else{
        for (int i=0; i<size; i++) cout<<stk[i]<<'\n';
    }
}

int Stack_A::add(){
    if (size<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)+get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_A::subtract(){
    if (size<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)-get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_A::multiply(){
    if (size<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)*get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_A::divide(){
    if (size<2) throw runtime_error("Not Enough Arguments");
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

int* Stack_A::get_stack(){
    return stk;
}

int Stack_A::get_size(){
    return size;
}