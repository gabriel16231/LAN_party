#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structuri.h"
//eliberare memorie
void free_players(Players **player);
void free_team(Teams **team);
void free_stack(Stack **top);
void free_trees(Tree **tree);
void free_teams(Teams **team);

//afisari
void display_teams(Teams *first,FILE *out);
void disp_spaces(int nr_c,FILE *out);
void display_round(Rounds *first_round,int round,FILE *out);
void display_winners(Stack *top,FILE *out,int round);
void display_bst(Tree *BST,FILE *out);

//functii citire lista de echipe
Players *read_player(FILE *in);
Teams* read_team(FILE* in);
Teams *read(FILE* in,int *nr_echipe);
void display_teams(Teams *first,FILE *out);



//adaugari+stergeri lista coada stiva arbore
void add_at_b_t(Teams **first,Teams **node);
void add_at_b_p(Players **first,Players **node);
void add_to_stack(Stack **top,Teams *team);
void add_to_tail(Rounds **last_match,Teams *team);
void add_in_tree(Tree **link,Teams *team);

Teams *get_from_stack(Stack **top);

void del_next_node_t(Teams **node);
void del_first_node_t(Teams **first);
void del_round(Rounds **first_round);

//cerinta 2
void init_points(Teams **first_team);
void team_points(Teams **team);
int det_nr_echipe(int n);
float det_min_team(Teams *team);
void del_min_points_teams(int *nr_echipe,int nr_echipe_fin,Teams **first);
void task_2(Teams **first,int *nr_echipe,FILE *out);

//cerinta 3
void comp_teams(Teams *team1,Teams *team2,Stack **top1,Stack **top2);
void det_winners_losers(Rounds **first_round,Rounds **last_round,Stack **winner_top,Stack **loser_top);
void addall_teams_to_round(Teams *team,Rounds **first_match,Rounds **last_match);
void makeround(Rounds **last_round,Stack **top);
void make_matches(Rounds **first_round,Rounds **last_round,Stack **top);
void Round(Rounds **first_round,Rounds **last_round,Stack **winners_top,Stack **losers_top,int round,FILE *out);
void save_top_8(Teams **top_8,Stack *winners);
void task_3(Teams *first,FILE *out,Teams **top_8,int nr_echipe);

//
void *search_link(Tree **BST,Teams *team);
void put_in_tree(Teams *node_team,Tree **BST);
void task_4(Teams **top_8,FILE *out,Tree **BST);


void task_5(Tree *BST,FILE *out);



