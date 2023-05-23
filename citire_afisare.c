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
    new_team->team_name=(char*)malloc(50*sizeof(char));
    fgets(new_team->team_name,50*sizeof(char),in);

    new_team->team_name[strlen(new_team->team_name)-2]='\0';
    if(new_team->team_name[strlen(new_team->team_name)-1]==' ')
    new_team->team_name[strlen(new_team->team_name)-1]='\0';

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
void disp_spaces(int nr_c,FILE *out)
{
    for(int i=0.;i<nr_c;i++)
            fprintf(out," ");
}
void display_round(Rounds *first_match,int round,FILE *out)
{
     fprintf(out,"\n--- ROUND NO:%d\n",round);
    while(first_match!=NULL)
    {
        fprintf(out,"%s",first_match->team1->team_name);
        disp_spaces(33-strlen(first_match->team1->team_name),out);
        fprintf(out,"-");
        disp_spaces(33-strlen(first_match->team2->team_name),out);
        fprintf(out,"%s",first_match->team2->team_name);

        fprintf(out,"\n");
        first_match=first_match->next;
    }
}

void display_winners(Stack *top,FILE *out,int round)
{
    fprintf(out,"\nWINNERS OF ROUND NO:%d\n",round);
    while(top!=NULL)
    {
       fprintf(out,"%s",top->team->team_name);
       disp_spaces(34-strlen(top->team->team_name),out);
       fprintf(out,"-  %.2f\n",top->team->team_points);

       top=top->prev;
    }


}

void display_bst(Tree *BST,FILE *out)
{
    if(BST!=NULL)
   {
       display_bst(BST->right,out);

       fprintf(out,"%s",BST->team->team_name);
       disp_spaces(34-strlen(BST->team->team_name),out);
       fprintf(out,"-  %.2f\n",BST->team->team_points);

       display_bst(BST->left,out);

   }
}







