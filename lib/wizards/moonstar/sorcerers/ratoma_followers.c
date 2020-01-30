inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("up","/guilds/sorcerer/tower/floor2/room9.c");
  add_exit("east","/guilds/sorcerer/ratoma_priests.c");
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
    return "Followers of Ratoma";
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
  return "wis 2";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["Faith of Ratoma": 20]);
      skill += (["grasp of Ratoma": 10]);
    }
    if (guild_level >= 2) {
      skill += (["grasp of Ratoma": 15]);
    }
    if (guild_level >= 3) {
      skill += (["Faith of Ratoma": 25]);
      skill += (["grasp of Ratoma": 20]);
    }
   if (guild_level >= 4) {
      skill += (["grasp of Ratoma": 30]);
      skill += (["teleport": 5]);
    }
    if (guild_level >= 5) {
      skill += (["grasp of Ratoma": 30]);
    }
    if (guild_level >= 6) {
      skill += (["grasp of Ratoma": 40]);
      skill += (["teleport": 15]);
    }
    if (guild_level >= 7) {
      skill += (["Faith of Ratoma": 50]);
      skill += (["grasp of Ratoma": 50]);
      skill += (["teleport": 30]);
    }
return skill;
}

