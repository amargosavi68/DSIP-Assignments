#include<stdio.h>

int main()
{
    int x[100], h[100], output[100], N, M, i, j, n, sum;
    int Circular_arr[100][100];

    printf("\n\t********************** LC from CC **********************\n");

    printf("\nEnter number of samples in x:");
    scanf("%d",&N);
    printf("\nEnter samples of x(n):\n");
    for (i = 0; i < N; i++)
    {
        printf("\nEnter x(%d):",i);
        scanf("%d", &x[i]);
    }
    printf("\nEnter number of samples in h:");
    scanf("%d",&M);
    printf("\nEnter samples of h(n):\n");
    for (i = 0; i < M; i++)
    {
        printf("\nEnter h(%d):",i);
        scanf("%d", &h[i]);
    }

    n = N + M - 1;

    for (i = N; i < n; i++)
    {
        x[i] = 0;
    }
    printf("\nx(n) after appending zeros is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", x[i]);
    }

    for (i = M; i < n; i++)
    {
        h[i] = 0;
    }
    printf("\nh(n) after appending zeros is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", h[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Circular_arr[i][(j+i) % n] = x[(n - j)%n];
        }
    }

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum  += Circular_arr[i][j] * h[j];
        }
        output[i] = sum;
    }

    printf("\n\nCircular array is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", Circular_arr[i][j]);
        }
        printf("\n");
    }

    printf("\nThe Linear Convolution using CC is:\n\t{");

    for (i = 0; i < n; i++)
    {
        printf("\t%d", output[i]);
    }

    printf("\t}\n");

    return 0;
}
