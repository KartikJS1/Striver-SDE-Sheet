int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);

    int platform = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        { // if arrival train come before depature train means we need one more platform
            platform++;
            i++;
        }

        else if (at[i] > dt[j])
        { // means depature train goes before arrival of a train that is one platform is empty
            platform--;
            j++;
        }

        if (platform > result)
        {
            result = platform;
        }
    }
    return result;
}