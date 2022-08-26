#include<stdio.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Written by: Lilitha Soka"
#define DATE "Date: 2022"
#include<math.h>

//Function that prints an array by looping through it

void Arr(int array[], int no)
{
    int x;

    for (x; x < no; x++)
    {
        printf("%d", array[x]);
    }
}

//Radix-I converter function
void Dec2RadixI(int decValue, int radValue)
{
    int n = round((log2(decValue)/log2(radValue)) + 0.5); //Calculating the length of the number in the desired number system.
    int array[n];
    int result = 1;
    int rem;
    int bi;
    int i = 1;

    while(result != 0) //While loop executes constant division by radix chosen
    {
        result = (decValue/radValue);
        rem = (decValue%radValue);
        array[n-i] = rem; //array stores new number in the right order.
        decValue = result;
        i = i+1;
    }

    Arr(array, n);
}


void main(void)
{
    printf("***************************** \n");
    printf(" %s \n" , TITLE);  //Add definitions.
    printf(" %s \n" , AUTHOR); //"              "
    printf(" %s \n" , DATE);   //"              "
    printf("***************************** \n");

    int dec;
    int rad;

    while(dec >= 0)  //loop to keep main function running until a value < 0 is entered.
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
