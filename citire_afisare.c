
#include "header.h"

Players *read_player(FILE *in)
{

    Players *new_player=(Players*)malloc(sizeof(Players));
    new_player->firstname=(char*)malloc(25*sizeof(char));
    new_player->secondname=(char*)malloc(25*sizeof(char));

    fscanf(in,"%s%s",new_player->firstname,new_player->secondname);
    fscanf(in,"%f",&new_player->points);
    return new_player;
}

Teams* read_team(FILE* in)
{
    Teams *new_team=(Teams*)malloc(sizeof(Teams));
    fscanf(in,"%d ",&new_team->nr_players);
    new_team->team_name=(char*)malloc(25*sizeof(char));
    fgets(new_team->team_name,25*sizeof(char),in);

    new_team->team_name[strlen(new_team->team_name)-1]=NULL;

    new_team->player=read_player(in);
    new_team->player->next=NULL;

    Players *new_p;

    for(int i=1;i<new_team->nr_players;i++)
    {
        getc(in);
        new_p=read_player(in);
        add_at_b_p(&new_team->player,&new_p);
    }

    return new_team;

}

Teams *read(FILE* in,int *nr_echipe)
{
    fscanf(in,"%d",nr_echipe);

    Teams *first_team=(Teams*)malloc(sizeof(Teams));

    first_team=read_team(in);
    first_team->next=NULL;

    Teams* new_t;
    for(int i=1;i<*nr_echipe;i++)
    {
        new_t=read_team(in);
       add_at_b_t(&first_team,&new_t);
    }

    return first_team;
}
void display_teams(Teams *first,FILE *out)
{
    Teams *aux=first;
    while(aux!=NULL)
    {
        fprintf(out,"%s\n",aux->team_name);
        aux=aux->next;
    }
}


