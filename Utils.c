/****************
 * Erez Gilat
 ***************/


#include <stdio.h>
#include "ex6.h"
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "queue.h"

#define COUNT 8
#define LEFT 1
#define MIDDLE 2
#define RIGHT 3

//i added the bool because it didn't work with out it.
// Function to print Trinary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Trin_Ari *root, int space,int bool)
{
    // Base case
    if (root == NULL||bool==0)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space,bool);
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s %d\n", root->name, root->id);
    // Process middle child
    print2DUtil(root->middle, space,bool);
    printf("\n");
    // Process left child
    print2DUtil(root->left, space,bool);
}


/*
 *Function Name:printPreOrder
* Input:Trin_Ari * root,int bool
* Output:none
* Function Operation:the function gets a tree and a bool (0/1) if the bool equals to 0 it means that a family had not been
 * created yet,else it will print the tree in a pre order .
 */
void printPreOrder(Trin_Ari * root,int bool)
{
    if (root==NULL||bool==0)
        return;
    printf("%s ID: %d\n",root->name,root->id);
    printPreOrder(root->left,bool);
    printPreOrder(root->middle,bool);
    printPreOrder(root->right,bool);
}


/*
 *Function Name:isPersonExist
* Input:Trin_Ari * root,int id
* Output:int
* Function Operation:the function gets a root of a tri tree and an id and returns 1 if a certain person in the tree exist
 * with the same id , else it will return 0.
 */
int isPersonExist(Trin_Ari * root,int id)
{
        if(root == NULL){
            return 0;
        }
        else{
            if(root->id==id)
                return 1;
            return isPersonExist(root->left,id)||isPersonExist(root->middle,id)||isPersonExist(root->right,id);
        }
}


/*
 *Function Name:getTheAvailableSlot
* Input:Trin_Ari * pointer
* Output:int
* Function Operation:the function gets a tri tree and returns what available slot (son spaces) it has , if the left is
 * available it will return Left (1) if the middle is available it will return MIDDLE (2), if the right is available it
 * will return RIGHT(3) otherwise it will return 0 , which meeans that there is no place for a new son to be added to.
 */
int getTheAvailableSlot(Trin_Ari * root)
{
    if(root->left==NULL)
        return LEFT;
    if(root->middle==NULL)
        return MIDDLE;
    if(root->right==NULL)
        return RIGHT;
    return 0;
}


/*
 *Function Name:addToTree
* Input:Trin_Ari * pointer, int availableSlot,char * nameOfNewMember,int idOfNewMember
* Output:int
* Function Operation:the function gets a tri tree an available slot , a name of a new member and an id of a new memeber
 * and adds it has a son to the pointer in the available place.
 */
int addToTree(Trin_Ari * pointer, int availableSlot,char * nameOfNewMember,int idOfNewMember)
{
    Trin_Ari * newMember =(Trin_Ari * )malloc(sizeof(Trin_Ari));
    if(newMember==NULL)
    {
        printf("Malloc Failed!\n");
        free(newMember);newMember=NULL;
        return 0;
    }
    newMember->id=idOfNewMember;
    newMember->name=(char *)malloc(sizeof(nameOfNewMember));
    strcpy(newMember->name,nameOfNewMember);
    newMember->left=NULL;
    newMember->middle=NULL;
    newMember->right=NULL;
    if (availableSlot==LEFT)
    {
        pointer->left=newMember;
        printf("Hello %s, ID: %d\n",nameOfNewMember,idOfNewMember);
        return LEFT ;
    }
    if (availableSlot==MIDDLE)
    {
        pointer->middle=newMember;
        printf("Hello %s, ID: %d\n",nameOfNewMember,idOfNewMember);
        return MIDDLE;
    }
    //available slot == RIGHT (3)
    pointer->right=newMember;
    printf("Hello %s, ID: %d\n",nameOfNewMember,idOfNewMember);
    return RIGHT;
}


/*
 *Function Name:getThePointerById
* Input:Trin_Ari * root,int id
* Output:Trin_Ari
* Function Operation:the function gets a tri tree and an ID and returns a pointer to the person with the same id.
 */
Trin_Ari * getThePointerById(Trin_Ari * root,int id)
{
    if(root->id==id)
        return root;
    if (root==NULL)
        return NULL;
    //checking where it's exist ,and go in that way
    if(isPersonExist(root->left,id)==1)
        return getThePointerById(root->left,id);
    if(isPersonExist(root->middle,id)==1)
        return getThePointerById(root->middle,id);
    if (isPersonExist(root->right,id)==1)
        return getThePointerById(root->right,id);
    return NULL;
}


/*
 *Function Name:getPrevPointer
* Input:Trin_Ari * root,Trin_Ari * pointer
* Output:Trin_Ari
* Function Operation:the function gets a tri tree and a pointer and returns the previous to the pointer (the father)
 */
Trin_Ari * getPrevPointer(Trin_Ari * root,Trin_Ari * pointer)
{
    if(root->id==pointer->id||root==NULL)
        return NULL;
    else{
        if((root->left->id==pointer->id)||(root->middle->id==pointer->id)|(root->right->id==pointer->id))
            return root;
        if(isPersonExist(root->left,pointer->id)==1)
            return getPrevPointer(root->left,pointer);
        if(isPersonExist(root->middle,pointer->id)==1)
            return getPrevPointer(root->middle,pointer);
        if(isPersonExist(root->right,pointer->id)==1)
            return getPrevPointer(root->right,pointer);
    }
}


/*
 *Function Name:printLeftOrder
* Input:Trin_Ari * root,int bool
* Output:none
* Function Operation:the function gets a tri tree and prints it in left order print.
 */
void printLeftOrder(Trin_Ari * root,int bool)
{
    if (root==NULL||bool==0)
        return;
    printLeftOrder(root->left,bool);
    printf("%s ID: %d\n",root->name,root->id);
    printLeftOrder(root->middle,bool);
    printLeftOrder(root->right,bool);
}



/*
 *Function Name:printBfs
* Input:Trin_Ari * root,int bool
* Output:none
* Function Operation:the function gets a tri tree and prints it in bfs,if bool== 0 , which means that no family
 * had been created it will return .
 */
void printBfs(Trin_Ari * root,int bool)
{
    int check;
    if (root==NULL||bool==0)
        return;
    Trin_Ari * current=root;
    Queue * q=createQueue();
    if (current->left!=NULL) {
        check=enQueue(q,current->left);
        if(check==0)
        {
            freeTriTree(root);
            destroyQueue(q);
            exit(1);
        }
    }
    if (current->middle!=NULL) {
        check=enQueue(q,current->middle);
        if(check==0)
        {
            freeTriTree(root);
            destroyQueue(q);
            exit(1);
        }
    }
    if (current->right!=NULL) {
        check=enQueue(q,current->right);
        if(check==0)
        {
            freeTriTree(root);
            destroyQueue(q);
            exit(1);
        }
    }
    while (!isEmpty(q))
    {
        printf("%s %d\n",current->name,current->id);
        current=deQueue(q);
        if (current->left!=NULL) {
            check=enQueue(q,current->left);
            if(check==0)
            {
                freeTriTree(root);
                destroyQueue(q);
                exit(1);
            }
        }
        if (current->middle!=NULL) {
            check=enQueue(q,current->middle);
            if(check==0)
            {
                freeTriTree(root);
                destroyQueue(q);
                exit(1);
            }
        }
        if (current->right!=NULL) {
            check=enQueue(q,current->right);
            if(check==0)
            {
                freeTriTree(root);
                destroyQueue(q);
                exit(1);
            }
        }
    }
    printf("%s %d\n",current->name,current->id);
    destroyQueue(q);
}

/*
 *Function Name:printBfsStayAtHome
* Input:Trin_Ari * root
* Output:none
* Function Operation:the function gets a tri tree and tells all the people from the root down to stay at home (in bfs)
 */
void printBfsStayAtHome(Trin_Ari * root)
{
    int check;
    if (root==NULL)
        return;
    Trin_Ari * current=root;
    Queue * q=createQueue();
    if (current->left!=NULL) {
        check=enQueue(q,current->left);
        if(check==0)
        {
            freeTriTree(root);
            destroyQueue(q);
            exit(1);
        }
    }
    if (current->middle!=NULL) {
        check=enQueue(q,current->middle);
        if(check==0)
        {
            freeTriTree(root);
            destroyQueue(q);
            exit(1);
        }
    }
    if (current->right!=NULL) {
        check=enQueue(q,current->right);
        if(check==0)
        {
            freeTriTree(root);
            destroyQueue(q);
            exit(1);
        }
    }
    while (!isEmpty(q))
    {
        printf("#StayHome! %s %d\n",current->name,current->id);
        current=deQueue(q);
        if (current->left!=NULL) {
            check=enQueue(q,current->left);
            if(check==0)
            {
                freeTriTree(root);
                destroyQueue(q);
                exit(1);
            }
        }
        if (current->middle!=NULL) {
            check=enQueue(q,current->middle);
            if(check==0)
            {
                freeTriTree(root);
                destroyQueue(q);
                exit(1);
            }
        }
        if (current->right!=NULL) {
            check=enQueue(q,current->right);
            if(check==0)
            {
                freeTriTree(root);
                destroyQueue(q);
                exit(1);
            }
        }
    }
    printf("#StayHome! %s %d\n",current->name,current->id);
    destroyQueue(q);
}


/*
 *Function Name:freeTriTree
* Input:Trin_Ari * root
* Output:none
* Function Operation:the function gets a tri tree and free all it values and parts
 */
void freeTriTree(Trin_Ari *root)
{
    if (root == NULL)
        return;
    freeTriTree(root->left);
    freeTriTree(root->middle);
    freeTriTree(root->right);
    free(root->name);
    free(root);
    root=NULL;
}
