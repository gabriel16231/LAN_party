#include "header.h"
//cerinta 2
void init_points(Teams **first_team)
{
    Teams *aux=*first_team;
    while(aux!=NULL)
    {
        team_points(&aux);

        aux=aux->next;
    }
}
void team_points(Teams **team)
{
    float sum=0;
    Players *aux;
    aux=(*team)->player;
    for(int i=0; i<(*team)->nr_players; i++)
    {

        sum+=aux->points;
        aux=aux->next;
    }

    (*team)->team_points=sum/(*team)->nr_players;
}

int det_nr_echipe(int n)
{
    int nr_echipe_fin=1;

    while(nr_echipe_fin*2<n)
        nr_echipe_fin*=2;

    return nr_echipe_fin;
}

float det_min_team(Teams *team,float *min_points)
{
    Teams *aux=team;
    float mini;
    mini=team->team_points;

    while(aux!=NULL)
    {
        if(mini > aux->team_points)
        {
            mini=aux->team_points;
        }

        aux=aux->next;
    }

    *min_points=mini;

}

//cerinta 3
