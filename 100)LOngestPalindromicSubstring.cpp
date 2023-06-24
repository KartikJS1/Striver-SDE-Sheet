string longestPalinSubstring(string s)
{
    if (s.length() <= 1)
        return s;
    int max_length = 1;
    int n = s.length();
    int st = 0, end = 0;

    // Odd length
    for (int i = 0; i < n - 1; i++)
    {
        int l = i;
        int r = i;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        int len = r - l - 1;
        if (len > max_length)
        {
            max_length = len;
            st = l + 1;
            end = r - 1;
        }
    }

    // Even length
    for (int i = 0; i < n - 1; i++)
    {
        int l = i;
        int r = i + 1;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        int len = r - l - 1;
        if (len > max_length)
        {
            max_length = len;
            st = l + 1;
            end = r - 1;
        }
    }

    return s.substr(st, max_length);
}