inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("east","/guilds/sorcerer/tower/floor2/room1.c");
  add_exit("down", "/guilds/sorcerer/tower/floor1/room11.c");
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
    return "Sorcerers of the Will";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Sorcerer scholars of the Will") < 20) {
    write("You must first complete the guild 'Sorcerer scholars of the Will'\n");
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
      skill += (["cast ztrand": 10]);
      skill += (["path of the will": 40]);
      skill += (["knowledge of power": 40]);
      skill += (["aurabeam": 20]);
    }
    if (guild_level >= 2) {
      skill += (["cast ztrand": 30]);
      skill += (["aurabeam": 30]);
    }
    if (guild_level >= 3) {
      skill += (["sorcerers touch": 15]);
      skill += (["knowledge of power": 20]);
      skill += (["chanting": 45]);
    }
   if (guild_level >= 4) {
      skill += (["sorcerers touch": 20]);
      skill += (["eyes of phoenix": 10]);
      skill += (["move items": 10]);
    }
    if (guild_level >= 5) {
      skill += (["cast ztrand": 40]);
      skill += (["sorcerers touch": 30]);
      skill += (["eyes of phoenix": 20]);
      skill += (["knowledge of power": 30]);
      skill += (["chanting": 50]);
      skill += (["move items": 20]);
      skill += (["aurabeam": 40]);
      skill += (["focused will": 5]);
    }
    if (guild_level >= 6) {
      skill += (["path of the will": 50]);
      skill += (["move items": 30]);
      skill += (["powered will": 5]);
      skill += (["mind link": 5]);
    }
    if (guild_level >= 7) {
      skill += (["sorcerers touch": 40]);
      skill += (["eyes of phoenix": 30]);
    }
    if (guild_level >= 8) {
      skill += (["cast ztrand": 50]);
      skill += (["knowledge of power": 40]);
      skill += (["chanting": 55]);
      skill += (["aurabeam": 50]);
}
     if (guild_level >= 9) {
      skill += (["focused will": 10]);
      skill += (["powered will": 10]);
      skill += (["mind link": 10]);
       }
    if (guild_level >= 10) {
      skill += (["cast ztrand": 60]);
      skill += (["path of the will": 70]);
      skill += (["eyes of phoenix": 40]);
      skill += (["move items": 40]);
    }
    if (guild_level >= 11) {
      skill += (["sorcerers touch": 50]);
      skill += (["knowledge of power": 50]);
    }
    if (guild_level >= 12) {
      skill += (["path of the will": 80]);
      skill += (["eyes of phoenix": 50]);
      skill += (["chanting": 60]);
      skill += (["move items": 20]);
      skill += (["aurabeam": 55]);
    }
      if (guild_level >= 13) {
      skill += (["cast ztrand": 75]);
      skill += (["path of the will": 90]);
      skill += (["sorcerers touch": 65]);
      skill += (["move items": 20]);
    }
    if (guild_level >= 14) {
      skill += (["cast ztrand": 80]);
      skill += (["path of the will": 100]);
      skill += (["sorcerers touch": 75]);
      skill += (["eyes of phoenix": 55]);
      skill += (["move items": 70]);
}
    if (guild_level >= 15) {
      skill += (["cast ztrand": 100]);
      skill += (["sorcerers touch": 80]);
      skill += (["eyes of phoenix": 70]);
      skill += (["knowledge of power": 70]);
      skill += (["aurabeam": 70]);
      skill += (["focused will": 35]);
      skill += (["powered will": 30]);
      skill += (["mind link": 35]);
}
return skill;
}

