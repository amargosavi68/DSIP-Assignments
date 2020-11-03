#include<stdio.h>

int x[100], h[100], output_arr[500];
int N, M, L, n, no_of_blocks = 0;
int Blocks[100][100], convolution_arr[100][100], Circular_arr[100][100];

void updateConvolutionArr(int t)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Circular_arr[i][(j+i) % n] = Blocks[t][(n - j) % n];
}


int main()
{
    int i, j, k, t, sum = 0;

    printf("\n\t*****************Overlap Add Method***********************\n");
    printf("\nEnter total number of samples in x(n): ");
    scanf("%d", &N);
    printf("\nEnter samples of x(n):\n");
    for (i = 0; i < N; i++)
    {
        printf("\nEnter x(%d): ",i);
        scanf("%d", &x[i]);
    }
    printf("\n\nEnter total number of samples in h(n): ");
    scanf("%d", &M);
    printf("\nEnter samples of h(n):\n");
    for (i = 0; i < M; i++)
    {
        printf("\nEnter h(%d): ",i);
        scanf("%d", &h[i]);
    }
    printf("\nEnter value of L to be assumed: ");
    scanf("%d", &L);

    n = L + M - 1;

    no_of_blocks = 1;
    while (no_of_blocks * L < N)
    {
        no_of_blocks++;
    }

    k = 0;
    for (i = 0; i < no_of_blocks; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j >= L)
            {
                Blocks[i][j] = 0;
            }
            else if (k <= N-1 )
            {
                Blocks[i][j] = x[k];
                k++;
            }
            else
            {
                Blocks[i][j] = 0;
            }
        }
    }

    for (i = M; i < n; i++)
    {
        h[i] = 0;
    }
    printf("\n\nThe h(n) matrix is: \n");
    for (j = 0; j < n; j++)
    {
        printf("\t%d", h[j]);
    }
    printf("\n");

    printf("\n\nThe blocks after appending zeros are: ");
    for (i = 0; i < no_of_blocks; i++)
    {
        printf("\n\tX(%d): ", i);
        for (j = 0; j < n; j++)
        {
            printf("\t%d", Blocks[i][j]);
        }
        printf("\n");
    }


    for (t = 0; t < no_of_blocks; t++)
    {
        updateConvolutionArr(t);
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
            {
                sum += Circular_arr[i][j] * h[j];

            }
            convolution_arr[t][i] = sum;
        }
    }

    printf("\n\nThe convolution array of each steps are:");
    for (i = 0; i < no_of_blocks; i++)
    {
        printf("\n\tC(%d): ", i);
        for (j = 0; j < n; j++)
        {
            printf("\t%d", convolution_arr[i][j]);
        }
        printf("\n");
    }


    t = 0;
    for (i = 0; i < n; i++)
    {
        if (i > 0)
            j = M - 1;
        else
            j = 0;
        for (; j < n; j++)
        {
            if (j >= L)
            {
                output_arr[t++] = convolution_arr[i][j] + convolution_arr[i+1][(j+M-1) % n];
            }
            else
            {
                output_arr[t++] = convolution_arr[i][j];
            }
        }
    }

    j = M - 1;
    for (; j < n; j++)
        output_arr[t++] = convolution_arr[i][j];

    printf("\n\nThe result of Convolution is: \n\n \tY(K) = {");
    for ( i = 0; i < N + M - 1; i++)
    {
        printf("\t%d", output_arr[i]);
    }
    printf("\t}\n");

    return 0;
}
