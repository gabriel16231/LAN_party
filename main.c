#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe,round=1;
    Teams *first;//retine adresa primei echipe
    Stack *winners_top,*losers_top;
    Rounds *first_round,*last_round;
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    first=read(in,&nr_echipe);

    task_2(&first,&nr_echipe,out);

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


