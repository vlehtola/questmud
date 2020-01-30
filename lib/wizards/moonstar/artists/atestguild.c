inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("leave","/wizards/moonstar/workroom.c");
  short_desc = "Artistien testeri guildi";
  long_desc = "Artists test center. Here you can train some martial artist skills.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 1;
}
guild_name() {
    return "Artists test";
}

check_joining_rec() {
  if(this_player()->query_guild_level("fighters") < 10) {
    write("You must first complete the guild of fighters.\n");
    return 0;

  }
  return 1;

}
check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;

}


get_bonuses(level) {
  return "str 5 , con 5 , dex 5";
}


skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["martial arts": 100]);
      skill += (["advanced martial arts": 100]);
      skill += (["dragon blow": 100]);
      skill += (["beartest": 100]);
    }
    return skill;
}

