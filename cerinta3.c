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
void det_winners_losers(Rounds **first_round,Rounds **last_round,Stack **winner_top,Stack **loser_top)
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
    new_round->next=NULL;
    if(*last_round!=NULL)
    {
    (*last_round)->next=new_round;
    }
    *last_round=new_round;

}
void make_matches(Rounds **first_round,Rounds **last_round,Stack **top)
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
void Round(Rounds **first_round,Rounds **last_round,Stack **winners_top,Stack **losers_top,int round,FILE *out)
{
    make_matches(first_round,last_round,winners_top);//extrage din stuva de winners si adauga echipele in coada de meciuri
    display_round(*first_round,round,out);//afisam runda
    det_winners_losers(first_round,last_round,winners_top,losers_top);//populam stiva de winners si losers
    display_winners(*winners_top,out,round);//afisam castigatorii rundei
}

void task_3(Teams *first,FILE *out)
{
    Stack *winners_top,*losers_top;
    Rounds *first_round,*last_round;
    int round=1;

    addall_teams_to_stack(first,&winners_top);


        Round(&first_round,&last_round,&winners_top,&losers_top,round,out);

        while(winners_top->prev!=NULL)
        {
            round++;
             Round(&first_round,&last_round,&winners_top,&losers_top,round,out);
        }
}
