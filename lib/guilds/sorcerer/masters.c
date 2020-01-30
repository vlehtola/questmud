inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("northwest","/guilds/sorcerer/tower/floor3/room5.c");	
  short_desc = "Guild room";
  long_desc = "A spacious chamber. In the middle of the room is statue.\n";
}


init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 15;
}
guild_name() {
    return "Master sorcerers of the Will";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Sorcerers of the Will") < 15) {
    write("You must first complete the guild 'Sorcerers of the Will'\n");
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
  return "wis 1 , int 2";
}

skill_list(int guild_level) {
    mapping skill;

    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["eyes of phoenix": 80]);
      skill += (["aurabeam": 85]);
      skill += (["focused will": 40]);
      skill += (["powered will": 40]);
      skill += (["mind link": 40]);
    }
    if (guild_level >= 2) {
      skill += (["cast major ztrand": 10]);
      skill += (["move items": 80]);
      skill += (["trance": 10]);
    }
    if (guild_level >= 3) {
      skill += (["knowledge of power": 80]);
      skill += (["sorcerers touch": 85]);
    }
   if (guild_level >= 4) {
      skill += (["cast major ztrand": 30]);
      skill += (["move items": 90]);
    }
    if (guild_level >= 5) {
      skill += (["cast major ztrand": 35]);
      skill += (["eyes of phoenix": 90]);
      skill += (["sorcerers touch": 100]);
      skill += (["focused will": 45]);
      skill += (["mind link": 45]);
      skill += (["faith of izyldran": 5]);
      skill += (["trance": 25]);
    }
    if (guild_level >= 6) {
      skill += (["cast major ztrand": 40]);
      skill += (["move items": 100]);
    }
    if (guild_level >= 7) {
      skill += (["cast major ztrand": 50]);
    }
    if (guild_level >= 8) {
      skill += (["aurabeam": 100]);
      skill += (["trance": 30]);
      skill += (["meteor storm": 10]);
}
     if (guild_level >= 9) {
      skill += (["cast major ztrand": 60]);
      skill += (["powered will": 45]);
      skill += (["faith of izyldran": 10]);
      skill += (["meteor storm": 20]);
       }
    if (guild_level >= 10) {
      skill += (["trance": 35]);
    }
    if (guild_level >= 11) {
      skill += (["faith of izyldran": 15]);
    }
    if (guild_level >= 12) {
      skill += (["cast major ztrand": 65]);
      skill += (["faith of izyldran": 20]);
      skill += (["trance": 40]);
    }
      if (guild_level >= 13) {
      skill += (["cast major ztrand": 85]);
      skill += (["eyes of phoenix": 100]);
      skill += (["focused will": 50]);
      skill += (["mind link": 50]);
      skill += (["meteor storm": 30]);
    }
    if (guild_level >= 14) {
      skill += (["knowledge of power": 100]);
      skill += (["powered will": 50]);
}
    if (guild_level >= 15) {
      skill += (["cast major ztrand": 100]);
      skill += (["focused will": 60]);
      skill += (["powered will": 60]);
      skill += (["mind link": 60]);
      skill += (["faith of izyldran": 30]);
      skill += (["trance": 50]);
      skill += (["meteor storm": 50]);
}
return skill;
}

