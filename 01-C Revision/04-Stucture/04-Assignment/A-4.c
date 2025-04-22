/*
    A-4 ->  Create a structure "Item" which includes below member variables:
            - itemName, quantity, price, amount.
            calculate the amount by accessing the member variable with the help of structure pointer.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item
{
    char name[20];
    int quant;
    int price;
    int amount;
} I;

int main() {
    int i = 0,ch = 1,sum = 0;
    printf("\n\t ***** Total amount of all Items Perchased ****** ");

    while (ch) {
        printf("\n\t Item %d ",++i);
        
        I *nw = malloc(sizeof(I));
        if(nw == NULL) {
            printf("\n\t Memory Allocation Failed!");
            exit(1);
        }
        
        printf("\n\t Enter Item Name : ");
        if (i > 1)  getchar();   
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';
        
        printf("\t Enter Item Quantity : ");
        scanf("%d",&(nw -> quant));

        printf("\t Enter Item Price : ");
        scanf("%d",&(nw -> price));

        nw -> amount = (nw -> price)*(nw -> quant);

        printf("\n\t Amount of the particular item as per price and quantity : %d\n",nw -> amount);

        //Calculating total amount of all items perchased
        sum = sum + nw -> amount;

        printf("\n\t Do you want to enter more Items ( Yes(1) / No(0) ) : ");
        scanf("%d",&ch);

        free(nw);
        nw = NULL;
    }
    printf("\n\t The total amount of all items perchased : %d \n\n",sum);

    return 0;   
}

/*
    Output ->        
                ***** Total amount of all Items Perchased ****** 
                Item 1 
                Enter Item Name : Onions
                Enter Item Quantity : 2
                Enter Item Price : 20

                Amount of the particular item as per price and quantity : 40

                Do you want to enter more Items ( Yes(1) / No(0) ) : 1

                Item 2 
                Enter Item Name : Potato Chips
                Enter Item Quantity : 2
                Enter Item Price : 40

                Amount of the particular item as per price and quantity : 80

                Do you want to enter more Items ( Yes(1) / No(0) ) : 1

                Item 3 
                Enter Item Name : Pizza
                Enter Item Quantity : 1  
                Enter Item Price : 250

                Amount of the particular item as per price and quantity : 250

                Do you want to enter more Items ( Yes(1) / No(0) ) : 0

                The total amount of all items perchased : 370                     
*/