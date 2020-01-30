inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(1);
  if(arg) return;
  add_exit("east", "/guilds/necro/unholy_lords");
  short_desc = "A small cold tomb";
  long_desc =
"The walls are cold and some water drips here and there. The tomb has\n"+
"been empty quite a long time. Smell of rotten flesh fills the air.\n"+
"The walls are soft, but offer enough support for climbing.\n";
}

init() {
  ::init();
  guild_init();
  add_action("climb", "climb");
}

climb() {
  write("You climb up and return to the necromancers guild.\n");
  move_object(this_player(), "/guilds/necro/base_guild");
  return 1;
}

guild_max_level() {
  return 9;
}

guild_name() {
    return "adept controllers";
}
check_joining_rec() {
  if(this_player()->query_guild_level("apprentice controllers") < 8) {
    write("You must first complete the guild of Apprentice controllers.\n");
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
  /* yhteensa 5 stattia / levelli */
  return "int 1 , wis 1 , ";
}
/*
  control corp -> 100
  control ethe -> 100
  control grea -> 100
  control magi -> 60
*/

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["control corporeal": 90]);
      skill += (["control ethereal": 70]);
      skill += (["control greater undead": 50]);
    }
    if (guild_level >= 2) {
      skill += (["control corporeal": 95]);
      skill += (["control ethereal": 80]);
      skill += (["control greater undead": 55]);
    }
    if (guild_level >= 3) {
      skill += (["control corporeal": 100]);
    }
    if (guild_level >= 4) {     
      skill += (["control ethereal": 85]);
      skill += (["control greater undead": 65]);
    }
    if (guild_level >= 5) {
      skill += (["control ethereal": 95]);
      skill += (["control greater undead": 75]);
    }
    if (guild_level >= 6) {
      skill += (["control ethereal": 100]);
      skill += (["control greater undead": 80]);
      skill += (["control dark magic": 15]);
    }
    if (guild_level >= 7) {
      skill += (["control greater undead": 90]);
      skill += (["control dark magic": 30]);
    }
    if (guild_level >= 8) {
      skill += (["control greater undead": 100]);
      skill += (["control dark magic": 45]);
    }
    if (guild_level >= 9) {
      skill += (["control dark magic": 60]);
    }
return skill;
}


