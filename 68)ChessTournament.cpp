#include <bits/stdc++.h>

bool ispossible(int mid, vector<int> &positions, int c)
{

    int cnt = 1, res = positions[0];

    for (int i = 0; i < positions.size(); i++)
    {

        // our target is to reach cnt ==c so if diff is greater than mid we try to
        // split it

        if (positions[i] - res >= mid)
        {

            cnt++;

            // if our cnt reaches to c then we can adjust this last student to last
            // index that'whywe return true

            if (cnt == c)
                return true;

            res = positions[i];
        }
    }

    return false;
}

int chessTournament(vector<int> positions, int n, int c)
{

    int low = 1;

    sort(positions.begin(), positions.end());

    int maxi = INT_MIN;

    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        maxi = max(maxi, positions[i]);

        mini = min(mini, positions[i]);
    }

    int high = maxi - mini;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        // if mid is possible minimum difference for students

        if (ispossible(mid, positions, c))
        {

            // if it is possible minimum then we want to maximize  it

            low = mid + 1;
        }

        // we cant divide diff(mid) among students so reduce this mid

        else
            high = mid - 1;
    }

    return high;

    // Write your code here
}