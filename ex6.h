/****************
 * Erez Gilat
 * 212434377
 * 01
 * ex6
 ***************/

#ifndef EX6_EX6_H
#define EX6_EX6_H


struct Trin_Ari {
    int id;
    char * name;
    struct Trin_Ari *left;
    struct Trin_Ari *middle;
    struct Trin_Ari *right;
};

typedef struct Trin_Ari Trin_Ari;
void buildFamily(Trin_Ari * root,int *bool);
void addMeeting(Trin_Ari *root,int bool);
void printMenu();
void printTriTree(Trin_Ari *root,int bool);
void bidud(Trin_Ari *root,int bool);
void superSpreader(Trin_Ari *root,int bool);
void vaccine(Trin_Ari * root,int * bool);
void freeSurvivors(Trin_Ari *root, int bool);


#endif //EX6_EX6_H
