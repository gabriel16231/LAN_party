#include "header.h"

void comp_teams(Teams *team1,Teams *team2,Stack **top1,Stack **top2)
{
    if(team1->team_points>team2->team_points)
    {
        team1->team_points++;
        add_to_stack(top1,team1);
        add_to_stack(top2,team2);
    }
    else
    {
        team2->team_points++;
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
        comp_teams((*first_round)->team1,(*first_round)->team2,winner_top,loser_top);
        del_round(first_round);
    }

    comp_teams((*first_round)->team1,(*first_round)->team2,winner_top,loser_top);


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

void addall_teams_to_round(Teams *team,Rounds **first_match,Rounds **last_match)
{
    (*last_match)=NULL;
    add_to_tail(last_match,team);
    team=team->next->next;
    (*first_match)=(*last_match);
    while(team!=NULL)
    {
        add_to_tail(last_match,team);
        team=team->next->next;
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

    display_round(*first_round,round,out);//afisam runda
    det_winners_losers(first_round,last_round,winners_top,losers_top);//populam stiva de winners si losers
    display_winners(*winners_top,out,round);//afisam castigatorii rundei
}

void task_3(Teams *first,FILE *out)
{
    Stack *winners_top,*losers_top;
    Rounds *first_round,*last_round;
    int round=1;

    addall_teams_to_round(first,&first_round,&last_round);//adauga toate echipele din lista in ocada de match uri
    Round(&first_round,&last_round,&winners_top,&losers_top,round,out);

    while(winners_top->prev!=NULL)
    {
        round++;
        make_matches(&first_round,&last_round,&winners_top);//extrage din stiva de winners si adauga echipele in coada de meciuri
        Round(&first_round,&last_round,&winners_top,&losers_top,round,out);
    }
}
