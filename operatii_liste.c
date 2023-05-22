#include "header.h"

void del_next_node_t(Teams **node)
{

    Teams *aux=(*node)->next;
    (*node)->next=(*node)->next->next;
    free_team(&aux);

}

void del_first_node_t(Teams **first)
{
    Teams *aux=*first;
    *first=(*first)->next;
    free_team(&aux);
}

void add_at_b_p(Players **first,Players **node)
{
    Players* aux;
    aux=*first;
    (*first)=*node;
    (*first)->next=aux;
}

void add_at_b_t(Teams **first,Teams **node)
{
    Teams* aux;
    aux=*first;
    (*first)=*node;
    (*first)->next=aux;
}

void add_to_stack(Stack **top,Teams *team)
{
    Stack *new_node=(Stack*)malloc(sizeof(Stack));
    new_node->team=team;
    new_node->prev=*top;
    *top=new_node;

}

void add_to_tail(Rounds **last_match,Teams *team)
{
    Rounds *new_match=(Rounds*)malloc(sizeof(Rounds));
    new_match->team1=team;
    new_match->team2=team->next;
    new_match->next=NULL;
    if(*last_match!=NULL)
        (*last_match)->next=new_match;
    (*last_match)=new_match;
}
void add_in_tree(Tree **link,Teams *team)
{
    Tree *new_node=(Tree*)malloc(sizeof(Tree));
    new_node->team=team;
    new_node->left=NULL;
    new_node->right=NULL;
    *link=new_node;
}
