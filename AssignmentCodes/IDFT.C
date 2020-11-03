#include<stdio.h>
#include<math.h>
#include<complex.h>

#define PI 3.142

float real_sample[100], imag_sample[100];
double output[200];
float real, imag;

int main()
{
    double real_sum = 0, imag_sum = 0;
    int i, j, k = 0, n;

    printf("\nEnter number of samples (in range of 2^N): ");
    scanf("%d", &n);

    printf("\nEnter samples of signal: \n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter sample[%d]: ",i);
        scanf("%f %f", &real_sample[i], &imag_sample[i]);
    }
    for (i = 0; i < n; i++)
    {
        real_sum = 0;
        imag_sum = 0;
        for (j = 0; j < n; j++)
        {
            real = cos(2 * PI * j * i / 4);
            imag = sin(2 * PI * j * i / 4);
            /*
                (a + ib) * (cosa - isinb) = (a * cosa - b sinb) + i(b * cosa - a sinb)
            */
            real_sum += ((real_sample[j] * real) - (imag_sample [j] * imag));
            imag_sum += ((imag_sample[j] * real) - (real_sample [j] * imag));
        }
        //printf("\nreal: %f   imag: %f", real_sum, imag_sum);
        output[k++] = real_sum / n;
        output[k++] = imag_sum / n;
    }

    printf("\nOutput sample are:  \n\n");
    for (i = 0; i < n*2; i = i + 2)
    {
        printf("\t\t");
        printf("%.2f", output[i]);
    }
    printf("\n\n");
    return 0;
}

