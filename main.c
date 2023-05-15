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
    all_caps(&first);
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

//-------------------------------------

//cerinta 3----------------------------





//-------------------------------------




    return 0;
}
