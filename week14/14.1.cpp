#include <stdio.h>

int maxValue = 0;

void copySolution(int *x, int *best, int n)
{
    for (int i = 0; i < n; i++)
        best[i] = x[i];
}

void backtrack(int *w, int *v, int n, int wx, int i,
               int currentWeight, int currentValue,
               int *x, int *best)
{
    if (i == n)
    {
        if (currentValue > maxValue)
        {
            maxValue = currentValue;
            copySolution(x, best, n);
        }
        return;
    }

    x[i] = 0;
    backtrack(w, v, n, wx, i + 1,
              currentWeight, currentValue, x, best);

    if (currentWeight + w[i] <= wx)
    {
        x[i] = 1;
        backtrack(w, v, n, wx, i + 1,
                  currentWeight + w[i],
                  currentValue + v[i], x, best);
    }
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{
    int *best = new int[n];

    for (int k = 0; k < n; k++)
    {
        x[k] = 0;
        best[k] = 0;
    }

    maxValue = 0;

    backtrack(w, v, n, wx, 0, 0, 0, x, best);

    for (int k = 0; k < n; k++)
        x[k] = best[k];

    return maxValue;
}

int main()
{
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x, vx;
    x = new int[n];

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);

    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}