#include "header.h"
void sort_8(Tree *BST,Teams **node)
{
    if(BST!=NULL)
   {
       sort_8(BST->right,node);
       add_at_b_t(node,&(BST->team));
       sort_8(BST->left,node);

   }
}
void task_5(Tree *BST,FILE *out)
{
    Tree *AVL;
    Teams *sorted_top8=NULL;
    sort_8(BST,&sorted_top8);
    //display_teams(sorted_top8,out);
    fprintf(out,"\nTHE LEVEL 2 TEAMS ARE:\n");
    fprintf(out,"%s\n",sorted_top8->next->next->next->next->next->next->next->team_name);
    fprintf(out,"%s\n",sorted_top8->next->next->next->next->next->team_name);
    fprintf(out,"%s\n",sorted_top8->next->next->next->team_name);
    fprintf(out,"%s\n",sorted_top8->next->team_name);
}   
