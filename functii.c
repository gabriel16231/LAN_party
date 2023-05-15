#include "header.h"
//cerinta 1
void name_in_caps(char **name)
{
    for(int i=0;i<strlen(*name);i++)
        *(*name+i)=toupper(*(*name+i));
}
void all_caps(teams **first)
{
    teams *aux=*first;
    while(aux!=NULL)
    {
        name_in_caps(&aux->team_name);
        aux=aux->next;
    }
}
//cerinta 2
void init_points(teams **first_team)
{
        teams *aux=*first_team;
        while(aux!=NULL)
        {
            team_points(&aux);

          aux=aux->next;
        }
}
void team_points(teams **team)
{
    float sum=0;
    players *aux;
    aux=(*team)->player;
    for(int i=0;i<(*team)->nr_players;i++)
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

float det_min_team(teams *team,float *min_points)
{
    teams *aux=team;
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

