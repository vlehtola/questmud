inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("south","/world/city/mainstr9");
  short_desc = "The study of merchants";
  long_desc =
"The merchants gather here to train their bargain and other abilities.\n"+
"The room is decorated with a good taste. The furniture might even be\n"+
"called too expensive.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 5;
}
guild_name() {
    return "merchants";
}

check_joining_rec() {
  return 1;
}


check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  if (lev >= 3 && this_player()->query_guild_level("apprentice mages") != 20) {
    write("Must have completed the Appretice Mage guild first.\n");
    return 0;
  }
  return sk;
}

get_bonuses(level) {
  return "int 1 , wis 1 , ";
}
/*
bargain
evaluate
cast trade
cast information
mastery of commerce
*/

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
    if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
  if(guild_level >= 1) {
    skill += (["bargain":(int) 60]);
    skill += (["evaluate":(int) 80]);
  }
  if(guild_level >= 2) {
    skill += (["bargain":(int) 100]);
    skill += (["evaluate":(int) 100]);
    skill += (["cast trade":(int) 20]);
  }
  if(guild_level >= 3) {
    skill += (["cast information":(int) 40]);
    skill += (["cast trade":(int) 60]);
    skill += (["mastery of commerce":(int) 20]);
  }
  if(guild_level >= 4) {
    skill += (["cast information":(int) 50]);
    skill += (["cast trade":(int) 70]);
    skill += (["mastery of commerce":(int) 40]);
  }
  if(guild_level >= 5) {
    skill += (["cast information":(int) 100]);
    skill += (["cast trade":(int) 100]);
    skill += (["mastery of commerce":(int) 100]);
  }
return skill;
}

