inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("northeast","/guilds/sorcerer/tower/floor3/room3.c");
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
    return "Archsorcerers of The Will";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Master sorcerers of the Will") < 15) {
    write("You must first complete the guild 'Master sorcerers of the Will'\n");
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
  return "wis 2 , int 1";
}

skill_list(int guild_level) {
    mapping skill;

    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["faith of Izyldran": 35]);
    }
    if (guild_level >= 2) {
      skill += (["faith of Izyldran": 40]);
    }
    if (guild_level >= 3) {
      skill += (["faith of Izyldran": 45]);
      skill += (["trance": 55]);
    }
   if (guild_level >= 4) {
      skill += (["faith of Izyldran": 50]);
    }
    if (guild_level >= 5) {
      skill += (["focused will": 65]);
      skill += (["mind link": 65]);
      skill += (["meteor storm": 65]);
    }
    if (guild_level >= 6) {
      skill += (["faith of Izyldran": 55]);
      skill += (["trance": 60]);
    }
    if (guild_level >= 7) {
      skill += (["powered will": 65]);
    }
    if (guild_level >= 8) {
      skill += (["faith of Izyldran": 60]);
      skill += (["trance": 65]);
      skill += (["meteor storm": 70]);
}
     if (guild_level >= 9) {
      skill += (["focused will": 70]);
      skill += (["powered will": 70]);
      skill += (["mind link": 70]);
      skill += (["faith of Izyldran": 65]);
       }
    if (guild_level >= 10) {
      skill += (["trance": 80]);
    }
    if (guild_level >= 11) {
      skill += (["faith of Izyldran": 70]);
      skill += (["meteor storm": 80]);
    }
    if (guild_level >= 12) {
      skill += (["focused will": 80]);
      skill += (["mind link": 80]);
      skill += (["faith of Izyldran": 75]);
    }
      if (guild_level >= 13) {
      skill += (["powered will": 75]);
      skill += (["faith of Izyldran": 80]);
      skill += (["trance": 85]);
      skill += (["meteor storm": 85]);
    }
    if (guild_level >= 14) {
      skill += (["faith of Izyldran": 85]);
      skill += (["trance": 100]);
}
    if (guild_level >= 15) {
      skill += (["focused will": 100]);
      skill += (["powered will": 100]);
      skill += (["mind link": 100]);
      skill += (["faith of Izyldran": 100]);
      skill += (["meteor storm": 100]);
}
return skill;
}

