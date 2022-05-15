/****************
 * Erez Gilat
 * 212434377
 * 01
 * ex6
 ***************/

#include <stdio.h>
#include "ex6.h"
#include "Utils.h"
#include <stdlib.h>
#include <string.h>
#define SPACE_COUNT 3

/*
 *Function Name:printMenu
* Input:none
* Output:none
* Function Operation:the function prints the menu
 */
void printMenu()
{
    printf("Please select an operation:\n"
           "\t0. Exit.\n"
           "\t1. Create family.\n"
           "\t2. Add family member.\n"
           "\t3. Print Family-Tree.\n"
           "\t4. Bidud.\n"
           "\t5. Superspreader.\n"
           "\t6. Vaccine.\n"
           "\t7. Print the menu.\n");
}


/*
 *Function Name:buildFamily
* Input:Trin_Ari *root (a root of a tri tree),int *bool
* Output:none
* Function Operation:the function builds the a root of a tri tree (only if it haven't been created yet *bool=0)
 * if it succed  it add will change the value of *bool to 1;
 */
void buildFamily(Trin_Ari * root,int * bool)
{
    int id;
    if (*bool!=0)
    {
        printf("The family has already been created\n");
        return;
    }
    char name[50];
    printf("enter name\n");
    scanf(" %[^\n]", &name);
    printf("enter ID\n");
    scanf("%d",&id);
    root->name=(char *)malloc(sizeof(name));
    if (root->name==NULL){free(root->name);free(root);printf("Malloc Failed!\n");exit(1);}
    strcpy(root->name,name);
    root->id=id;
    printf("Hello %s, ID: %d\n",name,id);
    *bool=1;
}


/*
 *Function Name:addMeeting
* Input:Trin_Ari *root , int bool
* Output:none
* Function Operation:the function adds a meeting to a desire person (the input id of admin) , the id of the person who
 *the admin meets with is also input(with scanf coomend) of the function , if bool =0 (which means that there is no root)
 *the function will print the message "Please create the family first" and return .
 */
void addMeeting(Trin_Ari *root,int bool)
{
    int availableSlot;
    char nameOfNewMember[50];
    Trin_Ari * pointer,*exist;
    //THE ID OF THE ADMIN IS THE ID OF THE PERSON WHO CREATES THE MEETING
    int idOfAdmin;
    int idOfNewMember;
    if (bool==0)
    {
        printf("Please create the family first\n");
        return;
    }
    printf("Enter the ID of the person who wants to make an appointment?\n");\
    scanf(" %d",&idOfAdmin);
    if (!isPersonExist(root,idOfAdmin))
    {
        printf("There is no ID %d\n",idOfAdmin);
        return;
    }
    pointer = getThePointerById(root,idOfAdmin);
    availableSlot=getTheAvailableSlot(pointer);
    if (availableSlot==0)
    {
        printf("%s ID: %d can't meet more than 3 members!\n",pointer->name,idOfAdmin);
        return;
    }
    printf("enter name\n");
    scanf(" %[^\n]", &nameOfNewMember);
    printf("enter ID\n");
    scanf(" %d", &idOfNewMember);
    //we are running to see if there is alredy such person with the idOfNewMember
    while (isPersonExist(root,idOfNewMember)==1)
    {
        exist=getThePointerById(root,idOfNewMember);
        printf("ID %d belongs to %s\n",idOfNewMember,exist->name);
        printf("enter name\n");
        scanf(" %[^\n]", &nameOfNewMember);
        printf("enter ID\n");
        scanf(" %d", &idOfNewMember);
    }
    //1 -left 2-middle 3-right
    //returns 0 if the function failed(malloc failed)
    //the addToTree also does the adding
    int i=addToTree(pointer,availableSlot,nameOfNewMember,idOfNewMember);
    if (i==0)
    {
        freeTriTree(root);
        exit(1);
    }
}



/*
 *Function Name:printTriTree
* Input:Trin_Ari *root , int bool (0/1)
* Output:none
* Function Operation:the function has a menu and it can print the tree as a 2d form/pre-order print/left-order print/BFS
 * print
 */
void printTriTree(Trin_Ari *root,int bool)
{
    char op;
    printf("Please select an operation:\n"
           "\t0. Return to the main menu.\n"
           "\t1. Print Trin-Ari family.\n"
           "\t2. Print Pre-order.\n"
           "\t3. Print Left-order.\n"
           "\t4. Print BFS.\n");
    do
    {
        scanf(" %c", &op);
        switch (op) {
            case '1':
                print2DUtil(root,SPACE_COUNT,bool);
                return;
            case '2':
                printPreOrder(root,bool);
                return;
            case '3':
                printLeftOrder(root,bool);
                return;
            case '4':
                printBfs(root,bool);
                return;
            case '0':
                return;
            default:
                printf("Error: unrecognized operation.\n");
                printf("Please select an operation:\n"
                       "\t0. Return to the main menu.\n"
                       "\t1. Print Trin-Ari family.\n"
                       "\t2. Print Pre-order.\n"
                       "\t3. Print Left-order.\n"
                       "\t4. Print BFS.\n");
                break;
        }
    } while (op != '0');
    return;
}


/*
 *Function Name:bidud
* Input:Trin_Ari *root , int bool (0/1)
* Output:none
* Function Operation:the function asks for a suspect who might have Covid and prints all the people who should stay at
 * home.
 */
void bidud(Trin_Ari *root,int bool)
{
    int idSuspect;
    if (bool==0)
    {
        printf("Please create the family first\n");
        return;
    }
    printf("Enter the ID of the suspected member\n");
    scanf("%d",&idSuspect);
    if (!(isPersonExist(root,idSuspect)))
    {
        printf("ID %d does not exist\n",idSuspect);
        return;
    }
    Trin_Ari * pointer = getThePointerById(root,idSuspect);
    Trin_Ari * prev=getPrevPointer(root,pointer);
    if (prev!=NULL)
        printf("#StayHome! %s %d\n",prev->name,prev->id);
    printf("#StayHome! %s %d\n",pointer->name,pointer->id);
    if (pointer->left!=NULL)
        printf("#StayHome! %s %d\n",pointer->left->name,pointer->left->id);
    if (pointer->middle!=NULL)
        printf("#StayHome! %s %d\n",pointer->middle->name,pointer->middle->id);
    if (pointer->right!=NULL)
        printf("#StayHome! %s %d\n",pointer->right->name,pointer->right->id);

}


/*
 *Function Name:superSpreader
* Input:Trin_Ari *root , int bool (0/1)
* Output:none
* Function Operation:the function asks for a suspected super spreader who might have Covid and tells him , its admin of the
 * meeting and all of its offsprings to stay at home .
 */
void superSpreader(Trin_Ari *root,int bool)
{
    int superId;
    if (bool==0)
    {
        printf("Please create the family first\n");
        return;
    }
    printf("Enter the ID of the suspected Superspreader\n");
    scanf("%d",&superId);
    if (!(isPersonExist(root,superId)))
    {
        printf("ID %d does not exist\n",superId);
        return;
    }
    Trin_Ari * pointer = getThePointerById(root,superId);
    if(root->id==pointer->id)
    {
        printBfsStayAtHome(pointer);
        return;
    }
    Trin_Ari * prev=getPrevPointer(root,pointer);
    printf("#StayHome! %s %d\n",prev->name,prev->id);
    printBfsStayAtHome(pointer);
}


/*
 *Function Name:freeSurvivors
* Input:Trin_Ari *root , int bool (0/1)
* Output:none
* Function Operation:the function gets a tree and free all the people who last in the tree (survivors) , it congrats
 * them and free their memory allocation.
 */
void freeSurvivors(Trin_Ari *root, int bool)
{
    if (bool==0)
        return;
    if (root == NULL)
        return;
    freeSurvivors(root->left, bool);
    freeSurvivors(root->middle, bool);
    freeSurvivors(root->right, bool);
    printf("%s ID: %d Survived!\n",root->name,root->id);
    free(root->name);
    free(root);
}



/*
 *Function Name:vaccine
* Input:Trin_Ari *root , int * bool (*bool=0/1)
* Output:none
* Function Operation:the function gets a tree and a pointer to an int(bool) if *bool=0 ( which means no tree has been
 * created yet)it will give a message to the user,else , it would ask for an ID of a person that got a vaccine and it
 * will free him and all its offspring and congratulate them for surviving COVID.
 */
void vaccine(Trin_Ari * root,int * bool)
{
    int idOfVac;
    if (*bool==0)
    {
        printf("Please create the family first\n");
        return;
    }
    printf("Who got vaccinated (ID)?\n");
    scanf("%d",&idOfVac);
    if (!isPersonExist(root,idOfVac))
    {
        printf("There is no ID %d\n",idOfVac);
        return;
    }
    Trin_Ari * pointer=getThePointerById(root,idOfVac);
    if (root->id==idOfVac)
    {
        freeSurvivors(root,*bool);
        *bool=0;
        root=(Trin_Ari *) malloc(sizeof(Trin_Ari));if(root==NULL){printf("Malloc Failed!\n");free(root);exit(1);}
        root->left=NULL;
        root->middle=NULL;
        root->right=NULL;
        return;
    }
    Trin_Ari * prev=getPrevPointer(root,pointer);
    freeSurvivors(pointer,*bool);
    if (prev->left->id==idOfVac)
        prev->left=NULL;
    else if (prev->middle->id==idOfVac)
        prev->middle=NULL;
    else
        prev->right=NULL;

}