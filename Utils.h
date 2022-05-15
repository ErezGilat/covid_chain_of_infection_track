//
// Created by Erez Gilat on 07/01/2021.
//

#ifndef EX6_UTILS_H
#define EX6_UTILS_H

int isPersonExist(Trin_Ari * root,int id);
void print2DUtil(Trin_Ari *root, int space,int bool);
int getTheAvailableSlot(Trin_Ari * root);
Trin_Ari * getThePointerById(Trin_Ari * root,int id);
int addToTree(Trin_Ari * pointer, int availableSlot,char * nameOfNewMember,int idOfNewMember);
void printPreOrder(Trin_Ari * root,int bool);
void printLeftOrder(Trin_Ari * root,int bool);
void printBfs(Trin_Ari * root,int bool);
Trin_Ari * getPrevPointer(Trin_Ari * root,Trin_Ari * pointer);
void printBfsStayAtHome(Trin_Ari * root);
void freeTriTree(Trin_Ari *root);

#endif //EX6_UTILS_H
