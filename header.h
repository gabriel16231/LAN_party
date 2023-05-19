#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structuri.h"

//cerinta 1
Teams* read_team(FILE* in);
Players *read_player(FILE *in);
Teams *read(FILE* in,int *nr_echipe);
void display_teams(Teams *first,FILE *out);


//cerinta 2
void team_points(Teams **team);
int det_nr_echipe(int n);
float det_min_team(Teams *team);


void del_next_node_t(Teams **node);
void del_first_node_t(Teams **first);
void add_at_b_p(Players **first,Players **node);
void add_at_b_t(Teams **first,Teams **node);






