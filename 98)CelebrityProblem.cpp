#include <bits/stdc++.h>

/*

    This is signature of helper function 'knows'.

    You should not implement it, or speculate about its implementation.



    bool knows(int A, int B);

    Function 'knows(A, B)' will returns "true" if the person having

    id 'A' know the person having id 'B' in the party, "false" otherwise.

*/

int findCelebrity(int n)
{

    stack<int> s;

    for (int i = 0; i < n; i++)

    {

        s.push(i);
    }

    while (s.size() > 1)

    {

        int a = s.top();

        s.pop();

        int b = s.top();

        s.pop();

        if (knows(a, b))

        {

            s.push(b);
        }

        else

        {

            s.push(a);
        }
    }

    bool rowCheck = false;

    int zcnt = 0;

    for (int i = 0; i < n; i++)

    {

        if (M[s.top()][i] == 0)
        {
            zcnt++;
        }
    }

    if (zcnt == n)
    {
        rowCheck = true;
    }

    bool colCheck = false;

    int ccnt = 0;

    for (int i = 0; i < n; i++)

    {

        if (M[i][s.top()] == 1)
        {
            ccnt++;
        }
    }

    if (ccnt == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)

    {

        return s.top();
    }

    else
    {
        return -1;
    }
}