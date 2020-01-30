inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("west","/guilds/sorcerer/grizz_followers.c");
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
    return "Priests of Grizz";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Followers of Grizz") < 7) {
    write("You must first complete the guild 'Followers of Grizz'\n");
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
      skill += (["faith of Grizz": 60]);
      skill += (["ice meteor": 55]);
    }
    if (guild_level >= 2) {
      skill += (["ice meteor": 60]);
      skill += (["Bless of Grizz": 50]);
    }
    if (guild_level >= 3) {
      skill += (["faith of Grizz": 70]);
      skill += (["Bless of Grizz": 60]);
    }
   if (guild_level >= 4) {
      skill += (["ice meteor": 65]);
      skill += (["Bless of Grizz": 65]);
    }
    if (guild_level >= 5) {
      skill += (["faith of Grizz": 80]);
      skill += (["ice meteor": 75]);
    }
    if (guild_level >= 6) {
      skill += (["ice meteor": 80]);
      skill += (["Bless of Grizz": 85]);
    }
    if (guild_level >= 7) {
      skill += (["faith of Grizz": 100]);
      skill += (["ice meteor": 100]);
      skill += (["Bless of Grizz": 100]);
    }
return skill;
}

