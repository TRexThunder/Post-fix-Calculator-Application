#include <iostream>
#include "stack_b.h"
#include <stdexcept>

using namespace std;

Stack_B::Stack_B(){
    stk=new int[1024];
    size=0;
    capacity=1024;
}

Stack_B::~Stack_B(){
    delete stk;
}

void Stack_B::push(int data){
    try{
        if (size>=capacity){
            int *temp=new int[capacity*2];
            for (int i=0; i<size; i++){
                temp[i]=stk[i];
            }
            delete[] stk;
            stk=temp;
            capacity*=2;
        }
        stk[++size-1]=data;
    }
    catch (bad_alloc&){
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::pop(){
    if (size<=0) throw runtime_error("Empty Stack");
    else{
        try{
            if ((capacity>1024) && (size<=capacity/4+1)){
                int *temp=new int[capacity/2];
                for (int i=0; i<size; i++){
                    temp[i]=stk[i];
                }
                delete[] stk;
                stk=temp;
                capacity/=2;
            }
            return stk[size---1];
        }
        catch (bad_alloc&){
            throw runtime_error("Out of Memory");
        }
    }
}

int Stack_B::get_element_from_top(int idx){
    if ((size<=0) || (idx+1>size) || (idx<0)) throw runtime_error("Index out of range");
    else return stk[size-idx-1];
}

int Stack_B::get_element_from_bottom(int idx){
    if ((size<=0) || (idx+1>size) || (idx<0)) throw runtime_error("Index out of range");
    else return stk[idx];
}

void Stack_B::print_stack(bool top_or_bottom){
    if (top_or_bottom){
        for (int i=0; i<size; i++) cout<<stk[size-i-1]<<'\n';
    }
    else{
        for (int i=0; i<size; i++) cout<<stk[i]<<'\n';
    }
}

int Stack_B::add(){
    if (size<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)+get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_B::subtract(){
    if (size<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)-get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_B::multiply(){
    if (size<2) throw runtime_error("Not Enough Arguments");
    else{
        int ans=get_element_from_top(1)*get_element_from_top(0);
        pop();
        pop();
        push(ans);
        return ans;
    }
}

int Stack_B::divide(){
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

int* Stack_B::get_stack(){
    return stk;
}

int Stack_B::get_size(){
    return size;
}