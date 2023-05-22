#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe;
    Teams *first,*top_8;//retine adresa primei echipe
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    first=read(in,&nr_echipe);
    display_teams(first,out);//afisare echipe ramase

    task_2(&first,&nr_echipe,out);

    task_3(first,out,&top_8,nr_echipe);

    task_4(&top_8,out);







//-------------------------------------
    return 0;
}


