#include "header.h"

void del_next_node_t(Teams **node)
{

    Teams *aux=(*node)->next;
    (*node)->next=(*node)->next->next;
    free(aux);

}

void del_first_node_t(Teams **first)
{
    Teams *aux=*first;
    *first=(*first)->next;
    free(aux);
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

