#include "header.h"
void del_round(Rounds **first_round)
{
    Rounds *aux=*first_round;
    (*first_round)=(*first_round)->next;
    free(aux);
}

Teams *get_from_stack(Stack **top)
{
    Teams *team=(*top)->team;
    Stack *aux=*top;
    (*top)=(*top)->prev;
    free(aux);
    return team;

}


