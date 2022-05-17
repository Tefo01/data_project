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
struct branch *create_branch(){
    struct branch *temp=(struct branch*)malloc(sizeof(struct branch));
}
struct bank
{
    struct branch *branches;
    struct operation_type *optypes;
};
void printBranches(struct branch *branch){
    struct branch *branch_head=branch;
    while (branch_head->nextb!=NULL)
        {
            printf("%d %s\n",branch_head->bno,branch_head->bname);
            branch_head=branch_head->nextb;
        }
}

void printOperationTypes(struct operation_type *opt){
    struct operation_type *opt_head=opt;
    while (opt_head->nextopt!=NULL)
        {
            printf("%d %s %f\n",opt_head->optnum,opt_head->optname,opt_head->commission);
            opt_head=opt_head->nextopt;
        }
}

void readoperationtypes(struct operation_type *opt_head,struct bank bank){
        FILE* file;
        file=fopen("./operation_types.txt","r");
        struct operation_type *opt=(struct operation_type*)malloc(sizeof(struct operation_type));
        opt_head=opt;
        char k;
        int optnum=1;
        //////////////////read operation types from file/////////////////
        while (!feof(file))
        {
        struct operation_type *temp=(struct operation_type*)malloc(sizeof(struct operation_type));

        fscanf(file, "%s %f", &opt->optname, &opt->commission);
        //printf("%s %f\n",opt->optname,opt->commission);
        opt->optnum=optnum;
        optnum++;

        opt->nextopt=temp;
        opt=opt->nextopt;
        }
        
        bank.optypes=opt_head;
        printOperationTypes(bank.optypes);
        fclose(file);

}

void readbranches(struct branch *branch_head,struct bank bank){
        FILE* file;
        file=fopen("./branches.txt","r");
        struct branch *branch=(struct branch*)malloc(sizeof(struct branch));
        branch_head=branch;
        char k=' ';
        int bno=1;

        while (!feof(file))
        {
        struct branch *temp =create_branch();
        int count=0;
        do
        {
            k=fgetc(file);
            branch->bname[count]=k;
            count++;
            if(k==' '||k==EOF)
                break;
        }while (1);
        branch->bno=bno;
        bno++;
        branch->nextb=temp;
        branch=branch->nextb;
        }
        bank.branches=branch_head;
        printBranches(bank.branches);
        fclose(file);
        
}



int main(){
    while(1){
    printf("1) Read operation types from the file \n");
    printf("2) Read branches types from the file \n");
    printf("3) Read customers types from the file \n");
    printf("4) Read customer transactions from the file \n");
    printf("5) calculate paid commission amount of each customers in each branches \n");

    printf("\n option  :  ");
    int menu_selector;
    
    scanf("%d",&menu_selector);
    printf("\n");

    if (menu_selector==1)
    {
        struct operation_type *opt_head;
        struct bank bank;
        readoperationtypes(opt_head,bank);
    }
    
    else if (menu_selector==2)
    {
        struct branch *branch_head;
        struct bank bank;
        readbranches(branch_head,bank);
    }

    break;
    
    }
}