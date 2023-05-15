#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct p
{
    char *firstname,*secondname;
   float points;
   struct p *next;
}players;
typedef struct t
{
    float team_points;
    char *team_name;
    int nr_players;
    players *player;
    struct t *next;
}teams;
//cerinta 1
teams* read_team(FILE* in);
players *read_player(FILE *in);
teams *read(FILE* in,int *nr_echipe);
void display_teams(teams *first,FILE *out);

//cerinta 2
void team_points(teams **team);
int det_nr_echipe(int n);
float det_min_team(teams *team,float *min_points);


void del_next_node_t(teams **node);
void del_first_node_t(teams **first);
void add_at_b_p(players **first,players **node);
void add_at_b_t(teams **first,teams **node);






