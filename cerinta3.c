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
    free_stack(losers_top);
    display_winners(*winners_top,out,round);//afisam castigatorii rundei
}

void save_top_8(Teams **top_8,Stack *winners)
{
    Teams *last;
    Teams *new_node=(Teams*)malloc(sizeof(Teams));
    new_node->team_name=winners->team->team_name;
        new_node->team_points=winners->team->team_points;
        new_node->next=NULL;
        last=new_node;
    (*top_8)=last;
    winners=winners->prev;
    while(winners!=NULL)
    {

        Teams *new_node=(Teams*)malloc(sizeof(Teams));
        new_node->team_name=winners->team->team_name;
        new_node->team_points=winners->team->team_points;
        new_node->next=NULL;
        last->next=new_node;
        last=new_node;
        winners=winners->prev;
    }
}

void task_3(Teams *first,FILE *out,Teams **top_8,int nr_echipe)
{
    Stack *winners_top,*losers_top;
    Rounds *first_round,*last_round;
    int round=1;

    addall_teams_to_round(first,&first_round,&last_round);//adauga toate echipele din lista in ocada de match uri
    Round(&first_round,&last_round,&winners_top,&losers_top,round,out);
    nr_echipe=nr_echipe/2;
    while(nr_echipe>1)
    {
        if(nr_echipe==8)
           {
               save_top_8(top_8,winners_top);
           }
        round++;
        make_matches(&first_round,&last_round,&winners_top);//extrage din stiva de winners si adauga echipele in coada de meciuri
        Round(&first_round,&last_round,&winners_top,&losers_top,round,out);
        nr_echipe=nr_echipe/2;
    }
}
