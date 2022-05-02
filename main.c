#include <stdio.h>
#include <stdlib.h>
struct operation_type
{
    char optname [100];
    float commission;
    int optnum;
    struct operation_type *nextopt;

};
struct transaction
{
    int optype;
    float amount;
    int tno;
    struct transaction *nexttr;

};
struct customer
{
    char fname [100];
    char lname [100];
    float paid_commission;
    int cno;
    struct transaction *trans;
    struct customer *nextc;

};
struct branch
{
    char bname [100];
    int bno;
    struct customer *custs;
    struct branch *nextb;

};


int main(){
    printf("1) Read operation types from the file \n");
    printf("2) Read branches types from the file \n");
    printf("3) Read customers types from the file \n");
    printf("4) Read customer transactions from the file \n");
    printf("5) calculate paid commission amount of each customers in each branches \n");
    int menu_selector;
    switch (menu_selector)
    {
    case 1:
        /* code */
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }
    
}