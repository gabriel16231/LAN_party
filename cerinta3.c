#include "header.h"

void comp_teams(Teams *team1,Teams *team2,Stack **top1,Stack **top2)
{
    if(team1->team_points>team2->team_points)
        {
            add_to_stack(top1,team1);
            add_to_stack(top2,team2);
        }
        else
        {
            add_to_stack(top1,team2);
            add_to_stack(top2,team1);
        }
}
void make_winners(Rounds **first_round,Rounds **last_round,Stack **winner_top,Stack **loser_top)
{
    *winner_top=NULL;
    *loser_top=NULL;
    while(*first_round!=*last_round)
    {
        comp_teams((*first_round)->team1,(*first_round)->team1,winner_top,loser_top);
        del_round(first_round);
    }

    comp_teams((*first_round)->team1,(*first_round)->team1,winner_top,loser_top);


}

void addall_teams_to_stack(Teams *team,Stack **top)
{
    *top=NULL;

    add_to_stack(top,team);
    team=team->next;

    while(team!=NULL)
    {
        add_to_stack(top,team);
        team=team->next;
    }

}

void makeround(Rounds **last_round,Stack **top)
{

    Rounds *new_round=(Rounds*)malloc(sizeof(Rounds));

    new_round->team1=get_from_stack(top);
    new_round->team2=get_from_stack(top);
    if(*last_round!=NULL)
    {
    new_round->next=NULL;
    (*last_round)->next=new_round;
    }
    *last_round=new_round;

}
void make_rounds(Rounds **first_round,Rounds **last_round,Stack **top)
{
    (*last_round)=NULL;

    Teams *team;

    makeround(last_round,top);

    *first_round=*last_round;


    while((*top)!=NULL)
    {
        makeround(last_round,top);
    }

}
