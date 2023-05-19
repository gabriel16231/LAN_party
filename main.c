#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe;
    Teams *first;//retine adresa primei echipe

    in=fopen("d.in","rt");
    out=fopen("r.out","wt");


    first=read(in,&nr_echipe);

    init_points(&first,nr_echipe);//calculeaza si adauga punctele  la fiecare echipa

    int nr_echipe_fin=det_nr_echipe(nr_echipe);//det. nr maxim de echipe

    task_2(&nr_echipe,nr_echipe_fin,&first);
    printf("ok");
    display_teams(first,out);//afisare echipe ramase




//-------------------------------------

//cerinta 3----------------------------

    int round=1;
    Stack *winners_top,*losers_top;
    Rounds *first_round,*last_round;

    addall_teams_to_stack(first,&winners_top);

    make_rounds(&first_round,&last_round,&winners_top);
    display_rounds(first_round,round,out);
    make_winners(&first_round,&last_round,&winners_top,&losers_top);
    display_winners(winners_top,out,round);


        while(winners_top->prev->prev!=NULL)
        {
            round++;
            make_rounds(&first_round,&last_round,&winners_top);
            display_rounds(first_round,round,out);
            make_winners(&first_round,&last_round,&winners_top,&losers_top);
            display_winners(winners_top,out,round);


        }







//-------------------------------------
    return 0;
}


