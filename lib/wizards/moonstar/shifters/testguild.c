inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("leave","/wizards/moonstar/workroom.c");
  short_desc = "shifti testeri guildi";
  long_desc = "Shifters test center. Here you can train some shapeshifters skills.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 1;
}
guild_name() {
    return "Shapeshifters";
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
      skill += (["chant of bears": 100]);
      skill += (["animal instinct": 100]);
      skill += (["animals strength": 100]);
      skill += (["shapeshift control": 100]);
      skill += (["double claws": 100]);
      skill += (["combined claw strike": 100]);
      skill += (["mastery of shapeshifting": 100]);
      skill += (["bear hug": 100]);
      skill += (["bear strike": 100]);
      skill += (["bear blow": 100]);
      skill += (["animals will": 100]);
      skill += (["double blow": 100]);
      skill += (["power hug": 100]);
    }
    return skill;
}

