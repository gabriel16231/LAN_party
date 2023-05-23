#include "header.h"

int main(int argc,char *argv[])
{
    FILE *in,*out,*in_c;
    Tree *BST;
    int nr_echipe;
    Teams *first,*top_8;//retine adresa primei echipe
    int *cerinta=(int*)malloc(5*sizeof(int ));
    in_c=fopen(argv[1],"r");
    in=fopen(argv[2],"r");
    out=fopen(argv[3],"w");

    int nr_cerinte=5;
    for (int i=0;i<nr_cerinte;i++)
    fscanf(in_c,"%d",&cerinta[i]);
    printf("ok");
    first=read(in,&nr_echipe);
    if(cerinta[0]==1&&cerinta[1]==0)
    display_teams(first,out);//afisare echipe ramase

    task_2(&first,&nr_echipe,out);

    if(cerinta[0]==1&&cerinta[1]==1)
    display_teams(first,out);//afisare echipe ramase
    if(cerinta[2]==1)
    task_3(first,out,&top_8,nr_echipe);
    if(cerinta[3]==1)
    task_4(&top_8,out,&BST);
    if(cerinta[4]==1)
    task_5(BST,out);
    free(cerinta);






//-------------------------------------
    return 0;
}


