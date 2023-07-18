#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    if (n == 1)
        return "1";

    string say = writeAsYouSpeak(n - 1);

    // Processing

    string result = "";
    for (int i = 0; i < say.length(); i++)
    {
        char ch = say[i];

        int count = 1;

        while (i < say.length() - 1 && say[i] == say[i + 1])
        {
            count++;
            i++;
        }

        result += to_string(count) + string(1, ch);
    }

    return result;
}