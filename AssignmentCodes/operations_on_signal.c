#include<stdio.h>

int sample[1000], n, output_arr[1000], k = 0, lower_range = 0, higher_range = 0, arrow_position = 0;

void delay()
{
    int i;
    printf("\nSamples in signal before applying delay are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    higher_range = lower_range + (n - 1);
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
    printf("\nEnter delay to be applied: ");
    scanf("%d", &k);
    for ( i = 0; i<k ; i++)
    {
        output_arr[i] = 0;
    }
    for ( ; i < n+k; i++)
    {
        output_arr[i] = sample[i-k];
    }
    printf("\nSamples in signal after applying delay operation are: \n");
    for (i = 0; i < n+k; i++)
    {
        printf("\t%d", output_arr[i]);
    }
    printf("\n");
    higher_range = lower_range + (n - 1) + k;
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
}

void advance()
{
    int i;
    printf("\nSamples in signal before applying Advance operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    higher_range = lower_range + (n - 1);
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");

    printf("\nEnter advance to be applied: ");
    scanf("%d", &k);
    printf("\nSamples in signal after applying Advance operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    higher_range = lower_range + (n - 1);
    arrow_position = arrow_position + k;
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
}

void fold()
{
    int i, temp;
    printf("\nSamples in signal before applying fold operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    for (i = 0; i<=n/2; i++)
    {
        temp = sample[i];
        sample[i] = sample[n-i-1];
        sample[n-i-1] = temp;
    }
    printf("\nSamples in signal after applying fold operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");

}

void amplification()
{
    int i;
    printf("\nSamples in signal before applying Amplifaction operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
    printf("\nEnter amplification factor: ");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        sample[i] = sample[i] * k;
    }
    printf("\nSamples in signal after applying Amplification operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
}

void deamplification()
{
    int i;
    printf("\nSamples in signal before applying De-amplification operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
    printf("\nEnter De-amplification factor: ");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        sample[i] = (sample[i]/2) * k;
    }
    printf("\nSamples in signal after applying De-amplification operation are: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", sample[i]);
    }
    printf("\n");
    printf("\n\tLower range = %d", lower_range);
    printf("\n\tHigher range = %d", higher_range);
    printf("\n\tArrow position = %d", arrow_position);
    printf("\n");
}

void main()
{
    int choice, i;
    do
    {
        printf("\nEnter total number of sample in the signal: ");
        scanf("%d",&n);
        printf("\nEnter lower range: ");
        scanf("%d", &lower_range);
        printf("\nEnter arrow position: ");
        scanf("%d", &arrow_position);
        for ( i = 0; i<n; i++)
        {
            printf("\nEnter sample[%d]: ",i+1);
            scanf("%d",&sample[i]);
        }

        printf("\n\t\t************Operations on Signal*****************\n\n");
        printf("\t1.Delay\n\t2.Advance\n\t3.Fold\n\t4.Amplification\n\t5.De-Amplification\n\t6.Quit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    delay();
                    break;

            case 2:
                    advance();
                    break;

            case 3:
                    fold();
                    break;

            case 4:
                    amplification();
                    break;

            case 5:
                    deamplification();
                    break;

            case 6:
                    printf("\nProgram Terminated.. Thank you.\n");
                    break;

            default:
                    printf("\nWrong choice..");
                    break;

        }
    }while(choice >= 1 && choice <= 5);
}
