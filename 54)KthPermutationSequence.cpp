string kthPermutation(int n, int k)
{

    // Write your code here.

    vector<int> numbers;

    int fact = 1;

    for (int i = 1; i <= n; i++)
    {

        fact = fact * i;

        numbers.push_back(i);
    }

    fact /= n; // making the boxes of size 24 / 4

    string ans = "";

    k = k - 1;

    while (1)

    {

        ans += to_string(numbers[k / fact]);

        numbers.erase(numbers.begin() + k / fact);

        if (numbers.size() == 0)

        {

            break;
        }

        k = k % fact;

        fact = fact / numbers.size();
    }

    return ans;
}