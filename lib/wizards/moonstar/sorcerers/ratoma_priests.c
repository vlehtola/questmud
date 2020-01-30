inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("west","/guilds/sorcerer/ratoma_followers.c");
  short_desc = "Guild room";
  long_desc = "A spacious chamber. In the middle of the room is statue.\n";
}


init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 7;
}
guild_name() {
    return "Priests of Ratoma";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Followers of Ratoma") < 7) {
    write("You must first complete the guild 'Followers of Ratoma'\n");
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
  return "int 1";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["faith of Ratoma": 60]);
      skill += (["grasp of Ratoma": 55]);
    }
    if (guild_level >= 2) {
      skill += (["grasp of Ratoma": 60]);
      skill += (["teleport": 50]);
    }
    if (guild_level >= 3) {
      skill += (["faith of Ratoma": 70]);
      skill += (["teleport": 60]);
    }
   if (guild_level >= 4) {
      skill += (["grasp of Ratoma": 65]);
      skill += (["teleport": 65]);
    }
    if (guild_level >= 5) {
      skill += (["faith of Ratoma": 80]);
      skill += (["grasp of Ratoma": 75]);
    }
    if (guild_level >= 6) {
      skill += (["grasp of Ratoma": 80]);
      skill += (["teleport": 85]);
    }
    if (guild_level >= 7) {
      skill += (["faith of Ratoma": 100]);
      skill += (["grasp of Ratoma": 100]);
      skill += (["teleport": 100]);
    }
return skill;
}

