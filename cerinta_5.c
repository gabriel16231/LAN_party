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
void make_avl(Tree **AVL_root,Teams *team)
{
    *AVL_root=NULL;
    add_in_tree(AVL_root,team->next->next->next->next);
    add_in_tree(&(*AVL_root)->left,team->next->next);
    add_in_tree(&(*AVL_root)->left->left,team->next);
    add_in_tree(&(*AVL_root)->left->right,team->next->next->next);
    add_in_tree(&(*AVL_root)->left->left->left,team);

    add_in_tree(&(*AVL_root)->right,team->next->next->next->next->next->next);
    add_in_tree(&(*AVL_root)->right->left,team->next->next->next->next->next);
    add_in_tree(&(*AVL_root)->right->right,team->next->next->next->next->next->next->next);
}
void task_5(Tree *BST,FILE *out)
{
    Tree *AVL;
    Teams *sorted_top8=NULL;
    sort_8(BST,&sorted_top8);
    make_avl(&AVL,sorted_top8);
    fprintf(out,"\nTHE LEVEL 2 TEAMS ARE:\n");
    fprintf(out,"%s\n",AVL->right->right->team->team_name);
    fprintf(out,"%s\n",AVL->right->left->team->team_name);
    fprintf(out,"%s\n",AVL->left->right->team->team_name);
    fprintf(out,"%s\n",AVL->left->left->team->team_name);
}   
