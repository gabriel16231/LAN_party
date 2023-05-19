#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe;
    Teams *first;//retine adresa primei echipe
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    first=read(in,&nr_echipe);

    task_2(&first,&nr_echipe,out);

    task_3(first,out);







//-------------------------------------
    return 0;
}


