#include "header.h"

void *search_link(Tree **BST,Teams *team)
{
    if(*BST==NULL)
    {
        add_in_tree(BST,team);
    }
    else
    {
        if((*BST)->team->team_points==team->team_points)
        {
            if(strcmp((*BST)->team->team_name,team->team_name)<0)
                search_link(&(*BST)->right,team);
            else
                search_link(&(*BST)->left,team);
        }
        else
        if((*BST)->team->team_points<team->team_points)
        search_link(&(*BST)->right,team);
    else
        
        search_link(&(*BST)->left,team);
    }
}
void put_in_tree(Teams *node_team,Tree **BST)
{
    while(node_team!=NULL)
    {
            search_link(BST,node_team);
            node_team=node_team->next;

    }


}
void task_4(Teams **top_8,FILE *out,Tree **BST)
{
    //display_teams(*top_8,out);
    
    *BST=NULL;
    put_in_tree(*top_8,BST);
    fprintf(out,"\nTOP 8 TEAMS:\n");
    display_bst(*BST,out);

}
