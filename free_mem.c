#include "header.h"
void free_players(Players **player)
{
    if(*player!=NULL)
    {
        free_players(&(*player)->next);
        free(*player);
    }
}
void free_team(Teams **team)
{
    if(*team!=NULL)
    {
        free_players(&(*team)->player);
        free(*team);
    }
}

void free_stack(Stack **top)
{
    if(*top!=NULL)
    {
    free_stack(&(*top)->prev);
    free_team(&(*top)->team);
    free(*top);
    }
}

void free_teams(Teams **team)
{
     if(*team!=NULL)
    {
        free_teams(&(*team)->next);
        free_team(team);
    }
}

void free_tree(Tree **tree)
{
    if(*tree!=NULL)
   {
       free_tree(&(*tree)->right);
       Tree *aux=(*tree)->left;
       free(*tree);
       free_tree(&aux);

   }
}

