#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int topp;
    int size;

public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        size = capacity;
        topp = -1;
    }

    void push(int num) {
        if(isFull()) return;

        topp++;
        arr[topp] = num;
    }

    int pop() {

        if(isEmpty()) return -1;
        int ans = arr[topp];
        topp--;
        return ans;

    }
    
    int top() {
        if(isEmpty()) return -1;

        return arr[topp];

    }
    
    int isEmpty() {
        return topp==-1;
    }
    
    int isFull() {

        return (topp-1) == size;
    }
    
};