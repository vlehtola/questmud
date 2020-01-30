
inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("southeast","/guilds/necro/base_guild");
  short_desc = "The necromancers subguild";
  long_desc = "Necromancers train here their unholy skills and so that\n"+
        "they might get better in practicing their vile art.\n"+
        "The room is carved in stone and the walls are solid. There is\n"+
        "a horrible smell of the dead in the air.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 8;
}
guild_name() {
    return "school of dark power";
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
  cast dark power -> 100
  cast focus dark power -> 100
  dark power -> 70
*/


skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["dark power": 35]);
    }
    if (guild_level >= 2) {
      skill += (["cast focus dark power": 70]);
}
    if (guild_level >= 3) {
      skill += (["cast dark power": 70]);
    }    
    if (guild_level >= 4) {
      skill += (["dark power": 40]);
    }
    if (guild_level >= 5) {
      skill += (["dark power": 50]);
    }
    if (guild_level >= 6) {
      skill += (["cast focus dark power": 100]);
}
    if (guild_level >= 7) {         
      skill += (["cast dark power": 100]);
}
    if (guild_level >= 8) {
      skill += (["dark power": 60]);
    }
return skill;
}
