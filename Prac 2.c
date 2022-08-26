#include<stdio.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Written by: Lilitha Soka"
#define DATE "Date: 2022"
#include<math.h>

void revArr(int array[], int no)
{
    int x;

    for (x; x < no; x++)
    {
        printf("%d", array[x]);
    }
}

void Dec2RadixI(int decValue, int radValue)
{
    int n = round((log2(decValue)/log2(radValue)) + 0.5);
    int array[n];
    int result = 1;
    int rem;
    int bi;
    int i = 1;

    while(result != 0)
    {
        result = (decValue/radValue);
        rem = (decValue%radValue);
        array[n-i] = rem;
        decValue = result;
        i = i+1;
    }

    revArr(array, n);
}


void main(void)
{
    printf("***************************** \n");
    printf(" %s \n" , TITLE);
    printf(" %s \n" , AUTHOR);
    printf(" %s \n" , DATE);
    printf("***************************** \n");

    int dec;
    int rad;

    while(dec >= 0)
    {
        printf("Enter a decimal number: ");
        scanf("%d", &dec, "\n");

        if(dec < 0)
        {
           printf("EXIT");
           break;
        }

        else
        {
           float logs = log2(dec);

           printf("%s %d \n","The number you have entered is", dec);

           printf("Enter a radix for the converter between 2 and 16: ");
           scanf("%d", &rad, "\n");
           printf("%s %d \n","The radix you have entered is", rad);

           printf("%s %0.2f \n", "The log2 of the number is", logs);
           printf("%s %d %s %d \n", "The integer result of the number divided by", rad, "is", dec/rad);
           printf("%s %d \n", "The remainder is", dec%rad);
           printf("%s", "The radix-2 value is ");
           Dec2RadixI(dec, rad);
           printf("\n");

        }

    }

}
