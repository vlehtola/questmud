
inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("southwest","/guilds/necro/base_guild");
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
  return 9;
}
guild_name() {
    return "necromancer adepts";
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
  return "int 1 , str 1 , ";
}
/*
  cast major necromancy -> 100
  cast minor necromancy -> 100
  cast supreme necromancy -> 70
*/

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast minor necromancy": 70]);
    }
    if (guild_level >= 2) {
      skill += (["cast major necromancy": 15]);
    }
    if (guild_level >= 3) {
      skill += (["cast minor necromancy": 95]);
      skill += (["cast major necromancy": 35]);
    }
    if (guild_level >= 4) {
      skill += (["cast minor necromancy": 100]);
      skill += (["cast major necromancy": 50]);
    }
    if (guild_level >= 5) {
      skill += (["cast major necromancy": 60]);
      skill += (["cast supreme necromancy": 15]);
    }
    if (guild_level >= 6) {
      skill += (["cast major necromancy": 70]);
      skill += (["cast supreme necromancy": 30]);

    }
    if (guild_level >= 7) {
      skill += (["cast major necromancy": 85]);
      skill += (["cast supreme necromancy": 50]);

    }
    if (guild_level >= 8) {
      skill += (["cast major necromancy": 100]);
}     
    if (guild_level >= 9) {
      skill += (["cast supreme necromancy": 70]);

      }

return skill;
}

