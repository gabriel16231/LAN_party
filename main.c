#include "header.h"

int main()
{
    FILE *in,*out;
    int nr_echipe;
    teams *first;//retine adresa primei echipe

    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    //cerinta 1
    first=read(in,&nr_echipe);
    display_teams(first,out);

    //cerinta2

        ///adauga la fiecare echipa punctele acesteia
        teams *aux=first;
        for(int i=0;i<nr_echipe;i++)
        {
            team_points(&aux);
          aux=aux->next;
        }
        int nr_echipe_fin=det_nr_echipe(nr_echipe);
        float min_points;
        while(nr_echipe!=nr_echipe_fin)
        {

            det_min_team(first,&min_points);
            while(first->team_points==min_points&&nr_echipe!=nr_echipe_fin)
            {
                del_first_node_t(&first);
                nr_echipe--;
            }

            teams *aux=first;
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






    return 0;
}
