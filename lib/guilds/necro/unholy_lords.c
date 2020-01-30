inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("west", "/guilds/necro/control2");
  short_desc = "A cold hole";
  long_desc ="The guild room of the Unholy Lords. Peaces of different kinds of bones lie\n"+
"all around the room. The walls are solid cold rock and the huge torches on\n"+
"the walls light the room. The presence of death scares you.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 8;
}
guild_name() {
    return "unholy lords";
}
check_joining_rec() {
  if(this_player()->query_guild_level("adept controllers") < 9) {
    write("You must first complete the guild of Adept controllers.\n");
    return 0;
  }
  if(this_player()->query_guild_level("master animators") < 8) {
    write("You much first complete the guild of Master animators.\n");
    return 0;
  }
  if(this_player()->query_guild_level("necromancer adepts") < 9) {
    write("You much first complete the guild of Necromancer adepts.\n");
    return 0;
  }
  if(this_player()->query_guild_level("school of dark power") < 8) {
    write("You much first complete the guild of School of dark power.\n");
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

  return "int 1 , wis 1 , ";
}
/*
  dark power 70 -> 100
  knowledge of anim 70 -> 100
  cast unh arms 70 -> 100
  cast supremen 70 -> 100
  control magi 70 -> 100
*/

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }

    if (guild_level >= 1) {
      skill += (["dark power": 80]);
      skill += (["knowledge of animation": 80]);
	skill += (["cast unholy enchantment": 80]);
      skill += (["cast supreme necromancy": 75]);
      skill += (["control dark magic": 70]);
    }
    if (guild_level >= 2) {
      skill += (["dark power": 85]);
      skill += (["knowledge of animation": 90]);
    }
    if (guild_level >= 3) {  
      skill += (["cast unholy enchantment": 85]);
      skill += (["cast supreme necromancy": 80]);
      skill += (["control dark magic": 75]);
    }
    if (guild_level >= 4) {
      skill += (["dark power": 95]);
      skill += (["knowledge of animation": 95]);
      skill += (["cast unholy enchantment": 95]);
     }
    if (guild_level >= 5)  {
      skill += (["cast supreme necromancy": 90]);
      skill += (["control dark magic": 85]);
    }
    if (guild_level >= 6) {
      skill += (["dark power": 100]);
      skill += (["knowledge of animation": 100]);
      skill += (["cast unholy enchantment": 100]);
}
    if (guild_level >= 7)  {
      skill += (["cast supreme necromancy": 95]);
      skill += (["control dark magic": 90]);
    }
    if (guild_level >= 8) {
      skill += (["cast supreme necromancy": 100]);
      skill += (["control dark magic": 100]);
    }

return skill;
}
