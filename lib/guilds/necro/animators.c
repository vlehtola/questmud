
inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("east","/guilds/necro/control1");
  short_desc = "A huge hall";
  long_desc ="A dark hall without windows. The air is very thick which makes it\n"+
"hard to breathe. You can sense death in every single corner of this\n"+
"room.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 8;
}

guild_name() {
    return "master animators";
}

check_joining_rec() {
  if(this_player()->query_guild_level("necromancers") < 10) {
    write("You must first complete the guild of necromancers.\n");
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
  return "int 2 , ";
}
/*
  cast raise corporeal -> 100
  cast raise ethereal -> 100
  cast unholy arms -> 70
  knowledge of animation -> 70
*/

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast raise corporeal": 65]);
      skill += (["cast raise ethereal": 45]);
    }
    if (guild_level >= 2) {
      skill += (["cast unholy enchantment": 30]);
      skill += (["knowledge of animation": 15]);
    }
    if (guild_level >= 3) {
      skill += (["cast raise corporeal": 70]);
      skill += (["cast raise ethereal": 50]);
    }
    if (guild_level >= 4) {
      skill += (["cast raise corporeal": 75]);
      skill += (["cast raise ethereal": 55]);
    }
    if (guild_level >= 5) {
      skill += (["cast unholy enchantment": 40]);
      skill += (["knowledge of animation": 30]);
    }
    if (guild_level >= 6) {
      skill += (["cast unholy enchantment": 50]);
      skill += (["knowledge of animation": 40]);
      skill += (["cast raise ethereal": 60]);
      skill += (["knowledge of animation": 40]);
    }
    if (guild_level >= 7) {
      skill += (["cast unholy enchantment": 70]);
      skill += (["knowledge of animation": 70]);
}
    if (guild_level >= 8) {
      skill += (["cast raise corporeal": 100]);
      skill += (["cast raise ethereal": 100]);
    }
return skill;
}
