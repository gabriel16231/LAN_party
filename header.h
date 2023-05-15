#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct p
{
    char *firstname,*secondname;
   float points;
   struct p *next;
}Players;

typedef struct t
{
    float team_points;
    char *team_name;
    int nr_players;
    Players *player;
    struct t *next;
}Teams;

typedef struct r
{
    Teams *team1,*team2;
    struct r *next;
}Rounds;

//cerinta 1
Teams* read_team(FILE* in);
Players *read_player(FILE *in);
Teams *read(FILE* in,int *nr_echipe);
void display_teams(Teams *first,FILE *out);
void all_caps(Teams **first);
void name_in_caps(char **name);


//cerinta 2
void team_points(Teams **team);
int det_nr_echipe(int n);
float det_min_team(Teams *team,float *min_points);


void del_next_node_t(Teams **node);
void del_first_node_t(Teams **first);
void add_at_b_p(Players **first,Players **node);
void add_at_b_t(Teams **first,Teams **node);






