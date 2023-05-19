#include "header.h"
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
    float sum=0;//media punctelor
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

float det_min_team(Teams *team)
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

    return mini;

}

void del_min_points_teams(int *nr_echipe,int nr_echipe_fin,Teams **first)
{
    float min_points;
    while((*nr_echipe)!=nr_echipe_fin)
    {
        min_points=det_min_team(*first);//gasim minimul de puncte dintre echipe
        while((*first)->team_points==min_points&&(*nr_echipe)!=nr_echipe_fin)//strege primele elemente consecutive egale cu min_points daca exista
        {
            del_first_node_t(first);
            (*nr_echipe)--;
        }

        Teams *aux=*first;
        while(aux->next!=NULL&&(*nr_echipe)!=nr_echipe_fin)//parcurge lista pentru a sterge echipele cu puncte minime daca exista
        {
            if(min_points==aux->next->team_points)
            {
                del_next_node_t(&aux);
                (*nr_echipe)--;
            }
            else//in czul in care am sters o echipa nu trecem la urmatoarea pentru ca vom sari o echipa la verificare
                aux=aux->next;//vom trece la urmatoarea echipa doar daca urmatoarea NU are val min de puncte
        }
    }
}

void task_2(Teams **first,int **nr_echipe,FILE *out)
{
    init_points(first);//calculeaza si adauga punctele  la fiecare echipa
    int nr_echipe_fin=det_nr_echipe(*nr_echipe);//det. nr maxim de echipe
    del_min_points_teams(nr_echipe,nr_echipe_fin,first);
    display_teams(*first,out);//afisare echipe ramase
}

