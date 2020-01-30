inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("north","out: 163 108");
  add_exit("south","out: 163 108");
  add_exit("east","out: 163 108");
  add_exit("west","out: 163 108");
  short_desc = "The Navigators guild";
  long_desc =
"This place is where the Navigators study and train their skills\n"+
"of teleportation. They use essence to evoke the various\n"+
"spells of magical transportation.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 5;
}
guild_name() {
    return "Navigators";
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
  /* yhteensa 5 stattia / levelli */
  return "int 2 , ";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast teleport":(int) 15]);
      skill += (["cast locate":(int) 15]);
    }
    if (guild_level >= 2) {
      skill += (["cast locate":(int) 30]);
      skill += (["cast teleport":(int) 30]);
    }
    if (guild_level >= 3) {
      skill += (["cast locate":(int) 30]);
      skill += (["cast teleport":(int) 50]);
    }
    if (guild_level >= 4) {
      skill += (["cast locate":(int) 70]);
      skill += (["cast teleport":(int) 70]);
      skill += (["navigation mastery":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["cast locate":(int) 100]);
      skill += (["cast teleport":(int) 100]);
      skill += (["navigation mastery":(int) 100]);
    }
return skill;
}
