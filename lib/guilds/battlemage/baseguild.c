inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  set_short("The battlemage guild");
  set_long("The sanctum of the battlemagi.\n");
  set_not_out();
  set_light(3);

  add_exit("north","/guilds/mage/apprmage");
  property = ({"no_summon"});
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 5;
}

guild_name() {
    return "Battlemage";
}

check_joining_rec() {
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}

get_bonuses(level) {
  return "str 1 , con 2 , int 1 ,";
}

skill_list(int guild_level) {
  int i;
  mapping skills;
  skills = ([ ]);

  if (guild_level >=1) {
    skills += (["battlecast": (int) guild_level*20]);
  }
  return skills;
}

