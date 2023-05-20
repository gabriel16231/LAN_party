#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe;
    Teams *top_8;
    Teams *first;//retine adresa primei echipe
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    first=read(in,&nr_echipe);

    task_2(&first,&nr_echipe,out);

    task_3(first,out,nr_echipe,&top_8);

    display_Stack(top_8);






//-------------------------------------
    return 0;
}


