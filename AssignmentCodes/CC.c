#include<stdio.h>
#include<math.h>

/*
input variables:-
W_real :- 2D matrix used for real part of twiddle factor
W_imag :- 2D matrix used for imaginary part of twiddle factor
W_imag_conj :- 2D matrix used for conjugate of twiddle factor

x :- input sample
h :- input sample

X_real :- 1D matrix which stores real part of DFT calculation of x(n)
X_imag :- 1D matrix which stores imaginary part of DFT calculation of x(n)

H_real :- 1D matrix which stores real part of DFT calculation of h(n)
H_imag :- 1D matrix which stores imaginary part of DFT calculation h(n)


output variables:-

output_real :- 1D matrix which stores real part of DFT calculation
output_imag :- 1D matrix which stores imaginary part of DFT calculation

Y :- 1D matrix which stores Circular Convolution output

*/

int W_real[4][4] = { {1,1,1,1}, {1,0,-1,0}, {1,-1,1,-1}, {1,0,-1,0} };
int W_imag[4][4] = { {0,0,0,0}, {0,-1,0,1}, {0,0,0,0}, {0,1,0,-1} };

int W_imag_conj[4][4] = { {0,0,0,0}, {0,1,0,-1}, {0,0,0,0}, {0,-1,0,1} };


int x[100], h[100], X_real[100], X_imag[100], H_real[100], H_imag[100], output_real[100], output_imag[100];
int Y[100];

void main()
{
    int i,j, N, real_sum = 0, imag_sum = 0;

    printf("\n***************Circular Convolution using DFT - IDFT***************\n");
    printf("\nEnter value of N (in range of 2^N): ");
    scanf("%d", &N);
    printf("\nEnter x(n) sample: ");
    for (i = 0; i < N; i++)
    {
        printf("\nEnter x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    printf("\nEnter h(n) sample: ");
    for (i = 0; i < N; i++)
    {
        printf("\nEnter h[%d]: ", i);
        scanf("%d", &h[i]);
    }

    for (i = 0; i < N; i++)
    {
        real_sum = 0;
        imag_sum = 0;
        for (j = 0; j < N; j++)
        {
            real_sum += W_real[i][j] * x[j];
            imag_sum += W_imag[i][j] * x[j];
        }
        X_real[i] = real_sum;
        X_imag[i] = imag_sum;
    }

    printf("\nX(K) is: \n\n");

    for (i = 0; i < N; i++)
    {
        printf("\t\t%d +j %d", X_real[i], X_imag[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        real_sum = 0;
        imag_sum = 0;
        for (j = 0; j < N; j++)
        {
            real_sum += W_real[i][j] * h[j];
            imag_sum += W_imag[i][j] * h[j];
        }
        H_real[i] = real_sum;
        H_imag[i] = imag_sum;
    }
    printf("\nH(K) is: \n\n");

    for (i = 0; i < N; i++)
    {
        printf("\t\t%d +j %d", H_real[i], H_imag[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        output_real[i] = ((X_real[i] * H_real[i]) - (X_imag[i] * H_imag[i]));
        output_imag[i] = ((X_real[i] * H_imag[i]) + (X_imag[i] * H_real[i]));
    }

    for (i = 0; i < N; i++)
    {
        real_sum = 0;
        imag_sum = 0;
        for (j = 0; j < N; j++)
        {
            real_sum += W_real[i][j] * output_real[j];
            imag_sum += W_imag_conj[i][j] * output_imag[j];
        }
        Y[i] = real_sum / N ;
    }

    printf("\nOutput of the CC using IDFT is: \n\n");
    printf("\t{ ");
    for (i = 0; i < N; i++)
    {
        printf("%d,\t", Y[i]);
    }
    printf("}");
    printf("\n");

}
