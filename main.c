/****************
 * Erez Gilat
 * 212434377
 * 01
 * ex6
 ***************/


#include <stdio.h>
#include "ex6.h"
#include <stdlib.h>

int main() {
    char op;
    Trin_Ari * root;
    int bool=0;
    //starting a root , making allocation of memory for the tree
    root=(Trin_Ari *) malloc(sizeof(Trin_Ari));if(root==NULL){printf("Malloc Failed!\n");free(root);exit(1);}
    root->left=NULL;
    root->middle=NULL;
    root->right=NULL;
    printMenu();
    do
    {
        scanf(" %c", &op);
        switch (op) {
            case '1':
                buildFamily(root,&bool);
                printf("Select the next operation (insert 7 for the entire menu):\n");
                break;
            case '2':
                addMeeting(root,bool);
                printf("Select the next operation (insert 7 for the entire menu):\n");
                break;
            case '3':
                printTriTree(root,bool);
                printMenu();
                break;

            case '4':
                bidud(root,bool);
                printf("Select the next operation (insert 7 for the entire menu):\n");
                break;

            case '5':
                superSpreader(root,bool);
                printf("Select the next operation (insert 7 for the entire menu):\n");
                break;

            case '6':
                vaccine(root,&bool);
                printf("Select the next operation (insert 7 for the entire menu):\n");
                break;

            case '7':
                printMenu();
                break;

            case '0':
                break;

            default:
                printf("Error: unrecognized operation.\n");
                printf("Select the next operation (insert 7 for the entire menu):\n");
                break;
        }
    } while (op != '0');
    freeSurvivors(root, bool);
    root=NULL;
    return 0;
}
