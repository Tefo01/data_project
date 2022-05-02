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
    struct operation_type *head=(struct Node*) malloc (sizeof(struct operation_type));
    
}