#include <stdio.h>

int findBestItem(int *weight, int *value, int *selected, int itemCount, int capacity)
{
    int index;
    int bestIndex = -1;
    double bestRatio = 0.0;

    for ( index = 0; index < itemCount; index++ )
    {
        if ( selected[index] == 0 )
        {
            if ( weight[index] <= capacity )
            {
                double ratio = (double)value[index] / weight[index];

                if ( ratio > bestRatio )
                {
                    bestRatio = ratio;
                    bestIndex = index;
                }
            }
        }
    }

    return bestIndex;
}

int *KnapsackGreedy( int *w, int *v, int n, int wx )
{
    int *selected = new int[n];
    int item;

    for ( item = 0; item < n; item++ )
    {
        selected[item] = 0;
    }

    int remainingCapacity = wx;

    while ( 1 )
    {
        int bestItem = findBestItem(w, v, selected, n, remainingCapacity);

        if ( bestItem == -1 )
        {
            break;
        }

        selected[bestItem] = 1;
        remainingCapacity = remainingCapacity - w[bestItem];
    }

    return selected;
}

int main()
{
    int n = 5;
    int wx = 11;

    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy( w, v, n, wx );

    int index;

    for ( index = 0; index < n; index++ )
    {
        printf("%d ", x[index]);
    }

    return 0;
}