/* tells the ambush room the type and level (amount) of the monsters //Celtron */

#define TUNEFACTOR 50 /* change this if ambushes are too tough or not, bigger value results in bigger monsters */
#define MONSTER	"/room/ambush/random_monster"
#define MAX_AMOUNT 4
#define MAX_LEVEL 30

/* returns an array of monster levels, based on the distance between duranghom and this place */
/* duranghom = (97, 119) */
int *query_monster_levels(string terrain, int x, int y) {
  int distance;
  float dist;
  int *levels;
  int level,i, amount;
  x -= 97; y -= 119;
  x *= x; y *= y;
  dist = x + y + 0.0;
  distance = to_int(sqrt(x + y + 0.0));
  /* we have the distance now */
  /* level = 3*SQRT(d). amount = random(d/20) */
  level = to_int(sqrt(to_float(distance * TUNEFACTOR / 100))) * 3;
  amount = random(distance/(2000/TUNEFACTOR)) +1;
  if(amount > MAX_AMOUNT) amount = MAX_AMOUNT;
  levels = allocate(amount);
  for(i=0; i < amount; i++) {
    levels[i] = level + random(5) - random(5);
    if(levels[i] > MAX_LEVEL) levels[i] = MAX_LEVEL;
  }
  return levels;
}

string monster_race(string terrain, int x, int y) {
  string *races;
  races = ({ "giant", "ogre", "orc", "troll", "human", "dark elf", });
  switch(terrain) {
    case "H": return "giant";
    case "f": return "troll";
  }
  return races[random(sizeof(races))];
}

void get_monsters(string terrain, int coord_x, int coord_y, object room) {
  int i, *levels;
  object monster;
  string race;
  race = monster_race(terrain, coord_x, coord_y);
  levels = query_monster_levels(terrain, coord_x, coord_y);

  for(i=0; i<sizeof(levels); i++) {
    monster = clone_object(MONSTER);
    monster->set_level(levels[i]);
    monster->set_ambush_race(race, levels[i]);
    monster->set_race(race);
    monster->set_exp(monster->query_exp()/3);
    move_object(monster, room);
  }
}


