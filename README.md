# Post-fix-Calculator-Application
Course Project (COL106) under Prof. Subodh Sharma [August 2023]: Designed a robust post-fix notation calculator using the Stack data structure implemented using fixed arrays, dynamic
arrays and doubly-linked lists. The project involved encapsulation in classes, tokenisation and error handling.
## Methods of Stack Implementation
- stack_a: using fixed-sized arrays
- stack_b: using dynamically-sized arrays
- stack_c: using doubly linked lists
## Description of Commands
1. void push(int data): Push the argument on the stack
1. int pop(): Pop and return the top element of the stack
1. int get_element_from_top(int idx): Return the element at index idx from the top
1. int get_element_from_bottom(int idx): Return the element at index idx from the bottom
1. void print_stack(bool top): Print the elements of the stack, one number per line.
1. int add(): Pop and add the top two elements of the stack and push the result back onto the stack
1. int subtract(): Pop the top two elements from the stack. Subtract the top element from the second element and push the results back onto the stack
1. int multiply(): Pop two elements from the stack and multiply them
and push the result back onto the stack
1. int divide() Pop two elements from the stack. Divide the second from the top element by the top element of the stack. Push the floor of the result, i.e. ⌊res⌋ back onto the stack.
1. int* get_stack() Return a pointer to the array used for the stack (for Part 1 and 2)
1. List* get_stack() Return a pointer to the Linked List used for the stack (for Part 3)
1. int get_size() Return the size of the stack
