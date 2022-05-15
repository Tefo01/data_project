#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
struct bank
{
    struct branch *branches;
    struct operation_type *optypes;
};

void printOperationTypes(struct operation_type *opt_head){
    while (opt_head->nextopt!=NULL)
        {
            printf("%s %f\n",opt_head->optname,opt_head->commission);
            opt_head=opt_head->nextopt;
        }
}



int main(){
    printf("1) Read operation types from the file \n");
    printf("2) Read branches types from the file \n");
    printf("3) Read customers types from the file \n");
    printf("4) Read customer transactions from the file \n");
    printf("5) calculate paid commission amount of each customers in each branches \n");
    int menu_selector=1;
    struct bank bank;
    //scanf(" %d",&menu_selector);

    if (menu_selector==1)
    {
        FILE* file;
        file=fopen("./operations.txt","r");
        struct operation_type *opt=(struct operation_type*)malloc(sizeof(struct operation_type));
        struct operation_type *opt_head=opt;
        char k;
        //////////////////read operation types from file/////////////////
        while (!feof(file))
        {
        int count=1;
        struct operation_type *temp=(struct operation_type*)malloc(sizeof(struct operation_type));

        fscanf(file, "%s %f", &opt->optname, &opt->commission);
        //printf("%s %f\n",opt->optname,opt->commission);
        opt->optnum=count;
        count++;

        opt->nextopt=temp;
        opt=opt->nextopt;
        }
        
        bank.optypes=opt_head;
        printOperationTypes(bank.optypes);
    }
    
        

    
}