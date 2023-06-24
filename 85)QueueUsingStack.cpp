#include <bits/stdc++.h>
class Queue
{
    // Define the data members(if any) here.

    stack<int> first;
    stack<int> second;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        first.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (!second.empty())
        {
            int data = second.top();
            second.pop();
            return data;
        }
        else
        {
            if (first.empty())
            {
                return -1;
            }
            else
            {
                while (!first.empty())
                {
                    second.push(first.top());
                    first.pop();
                }
                int data = second.top();
                second.pop();
                return data;
            }
        }
    }

    int peek()
    {
        // Implement the peek() function here.
        if (!second.empty())
        {
            return second.top();
        }
        else
        {
            if (first.empty())
                return -1;

            else
            {
                while (!first.empty())
                {
                    second.push(first.top());
                    first.pop();
                }
                return second.top();
            }
        }
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return (first.empty() && second.empty());
    }
};