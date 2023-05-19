#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe;
    Teams *first;//retine adresa primei echipe

    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

//cerinta 1---------------------
    first=read(in,&nr_echipe);
    printf("cerinta1 done \n");
    //all_caps(&first);
//------------------------------


//cerinta2----------------------

    //adauga la fiecare echipa punctele acesteia
    init_points(&first,nr_echipe);


    int nr_echipe_fin=det_nr_echipe(nr_echipe);//det. nr maxim de echipe
    float min_points;

    while(nr_echipe!=nr_echipe_fin)
    {

        det_min_team(first,&min_points);


        //strege primele elemente consecutive egale cu min_points daca exista
        while(first->team_points==min_points&&nr_echipe!=nr_echipe_fin)
        {
            del_first_node_t(&first);
            nr_echipe--;
        }

        Teams *aux=first;

        //parcurge lista pentru a sterge echipele cu puncte minime
        while(aux->next!=NULL&&nr_echipe!=nr_echipe_fin)
        {
            if(min_points==aux->next->team_points)
            {
                del_next_node_t(&aux);
                nr_echipe--;
            }
            else
                aux=aux->next;
        }
    }

    display_teams(first,out);//afisare echipe ramase
    printf("cerinta2 done\n");



//-------------------------------------

//cerinta 3----------------------------

    int round=1;
    Stack *winners_top,*losers_top;
    Rounds *first_round,*last_round;

    addall_teams_to_stack(first,&winners_top);
    //display_Stack(winners_top);
    make_rounds(&first_round,&last_round,&winners_top);
    display_rounds(first_round,round,out);
    make_winners(&first_round,&last_round,&winners_top,&losers_top);
    display_winners(winners_top,out,round);


        while(winners_top->prev!=NULL)
        {
            printf("round%d",round);
            round++;
            make_rounds(&first_round,&last_round,&winners_top);
            display_rounds(first_round,round,out);
            make_winners(&first_round,&last_round,&winners_top,&losers_top);
            display_winners(winners_top,out,round);


        }







//-------------------------------------
    return 0;
}


