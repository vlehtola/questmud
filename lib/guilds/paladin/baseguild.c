inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  set_short("The paladin guild");
  set_long("The paladin guild is a place of peace and light.\n");
  set_not_out();
  set_light(3);

  add_exit("southwest","/guilds/channel/r04");
  add_exit("southeast","/guilds/fighter/blades");
  property = ({"no_summon"});
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 1;
}

guild_name() {
    return "Paladin";
}

check_joining_rec() {
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([5:"call angel:20;"]);
  return sk;
}

get_bonuses(level) {
  return "str 2 , con 2 , wis 2 ,";
}

skill_list(int guild_level) {
  int i;
  mapping skills;
  skills = ([ ]);

  if (guild_level >=1) {
    skills += (["call angel": (int) 100]);
  }

  return skills;
}

