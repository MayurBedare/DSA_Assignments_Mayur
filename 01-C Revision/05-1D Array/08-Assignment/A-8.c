/*
    A-8 ->  accept n elements in an array and perform right rotaion and left rotation (rotate N elements (N is an user input)) .  
            (Allocate the array dynamically)
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i = 0,key,size = 1;
    int *arr = NULL;
    arr = (int*)malloc(sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t ***** Array Rotation - Right and Left ***** \n");

    printf("\n\t Note -> Enter arr[last] : -1 to exit \n");
    printf("\n\t Enter the elements of arr[n] one by one : \n");

    while (1) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);

        if (arr[i] == -1) {
            size--;
            break;
        }

        size++;
        arr = (int*)realloc(arr,(size)*sizeof(int));
        if (arr == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        i++;
    }   

    printf("\n\t The given arr[%d] : \n",size);
    for (int i = 0 ; i < size ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
    printf("\n\n");

    int *rotation = (int*)malloc(size*sizeof(int));
    if (rotation == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }

    while (1) {
        char rotate;
        int n,ch,element,same_array = 1;
        printf("\n\t Rotate array in right and left : \n");
        printf("\n\t Enter (r) for Right rotation or (l) for left rotation : ");
        scanf(" %c",&rotate); // Note : before these scanf input buffer contains \n then to remove that we can use scanf(" %c"); which works same as getchar();

        if (rotate == 'r' || rotate == 'l') {
            printf("\n\t Enter the no. of times to Rotate the given arr[%d] : ",i);
            scanf("%d",&n);
            if (rotate == 'r') {
                for (int i = 0 ; i < size ; i++) {
                    element = (i + n) % size;
                    rotation[element] = arr[i];
                }
            }
            if (rotate == 'l') {
                for (int i = 0 ; i < size ; i++) {
                    element = (i + 2*n) % size;
                    rotation[element] = arr[i];
                }
            }

            printf("\n\t Rotation of the given arr[%d] : \n",size);
            for (int i = 0 ; i < size ; i++) {
                if (i == 0) printf("\n\t |_%d_|",rotation[i]);
                else    printf("_%d_|",rotation[i]);
            }
            printf("\n\n");

            printf("\n\t Do you want to perform more operations : ");
            scanf("%d",&ch);

            if (ch) {
                continue;
            } else {
                printf("\n\t Program Exited Successfully.\n\n");
                exit(0);
            }
        } else {
            printf("\n\t Invalid Rotation Entered!\n\n");
            continue;
        }   
    } 

    free(arr);
    arr = NULL;

    free(rotation);
    rotation = NULL;

    return 0;   
}
