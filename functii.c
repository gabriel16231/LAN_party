#include "header.h"
//cerinta 1
void name_in_caps(char **name)
{
    for(int i=0;i<strlen(*name);i++)
        *(*name+i)=toupper(*(*name+i));
}
void all_caps(Teams **first)
{
    Teams *aux=*first;
    while(aux!=NULL)
    {
        name_in_caps(&aux->team_name);
        aux=aux->next;
    }
}
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
void make_round(Rounds **last_round,Rounds *new_round,Teams *team)
{
    new_round->team1=team;
    new_round->team2=team->next;
    *last_round=new_round;

}
void init_rounds(Rounds **first_round,Rounds **last_round,Teams *first_team)
{


     Teams *current_team=first_team;
    *first_round=(Rounds*)malloc(sizeof(Rounds));
    (*first_round)->next=NULL;

    make_round(last_round,*first_round,current_team);
    printf("%s  -  %s",(*first_round)->team1->team_name,(*first_round)->team2->team_name);
}

