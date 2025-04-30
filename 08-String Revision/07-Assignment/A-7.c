/*
    A-7 ->  In C, take input from the user about their hobbies in a 2D character array, ask the user how many hobbies they have, and accordingly 
            dynamically allocate the 2D character array and ask them to enter one by one hobby names and iterate accordingly.
            Sample 1: 
            INPUT: 
                    3
                    eating
                    playing
                    watching
            OUTPUT: 
                    Eating 
                    Playing
                    Watching
            Sample 2: 
            INPUT: 
                    3
                    eating icecream
                    playing videogames
                    watching cartooon
            OUTPUT: 
                    Eating Icecream
                    Playing Videogames
                    Watching Cartoon
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main() {
    int n;

    printf("\n\t ***** Hobbie Counter ***** \n");
    printf("\n\t Enter the total number of hobbies : ");
    scanf("%d",&n);
    getchar();

    char **string = NULL;
    string = (char**)malloc(n*sizeof(char*)); 
    if (string == NULL) {
        printf("\n\t Memory Allocation Failed! ");
        exit(1);
    }

    for (int i = 0 ; i < n ; i++) {
        string[i] = (char*)malloc(50*sizeof(char));
        if (string[i] == NULL) {
            printf("\n\t Memory Allocation Failed! ");
            exit(1);
        }

        printf("\n\t Enter Hobbie %d : ",i+1);
        fgets(string[i],50,stdin);
        string[i][strcspn(string[i],"\n")] = '\0';
        
        int j = 1;
        if(islower(string[i][0])) {
            string[i][0] = toupper(string[i][0]);
        }
        while (string[i][j] != '\0') {
            while (!isspace(string[i][j]) && string[i][j] != '\0') {
                j++;
            }

            if (isspace(string[i][j]))  j++;
            
            if (string[i][j]) {
                if(islower(string[i][j])) {
                    string[i][j] = toupper(string[i][j]);
                }
                j++;
            }
        } 
    }

    for (int i = 0 ; i < n ; i++) {
        printf("\n\t Hobbie %d : %s",i+1,string[i]);
    }
    printf("\n\n");

    for (int i = 0 ; i < n ; i++) {
        free(string[i]);
        string[i] = NULL;
    }
    free(string);
    string = NULL;

    return 0;   
}
