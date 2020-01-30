inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  short_desc = "The Archers shooting area";
  long_desc = "Nods, this is da archer shooting area, and more lappaa coming.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 1;
}

guild_name() {
    return "Archer";
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
  if(level >= guild_max_level()) return;
  return " ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);
    skill += (["craftmanship":(int) 100]);
    skill += (["fletchery":(int) 100]);
    skill += (["shooting":(int) 100]);
    skill += (["faster shots":(int) 100]);
    skill += (["markmanship":(int) 100]);
    skill += (["aim":(int) 100]);
    skill += (["critical shots":(int) 100]);
  return skill;
}


