#include "header.h"

void del_next_node_t(teams **node)
{

    teams *aux=(*node)->next;
    (*node)->next=(*node)->next->next;
    free(aux);

}

void del_first_node_t(teams **first)
{
    teams *aux=*first;
    *first=(*first)->next;
    free(aux);
}

void add_at_b_p(players **first,players **node)
{
    players* aux;
    aux=*first;
    (*first)=*node;
    (*first)->next=aux;
}

void add_at_b_t(teams **first,teams **node)
{
    teams* aux;
    aux=*first;
    (*first)=*node;
    (*first)->next=aux;
}

