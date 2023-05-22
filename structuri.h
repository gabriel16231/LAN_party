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

typedef struct s
{
    Teams *team;
    struct s *prev;
}Stack;

typedef struct tree
{
    Teams *team;
    struct tree *left,*right;
}Tree;


