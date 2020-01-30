inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("east","/guilds/sorcerer/anrax_followers.c");
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
    return "Priests of Anrax";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Followers of Anrax") < 7) {
    write("You must first complete the guild 'Followers of Anrax'\n");
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
      skill += (["faith of Anrax": 60]);
      skill += (["wrath of phoenix": 55]);
    }
    if (guild_level >= 2) {
      skill += (["wrath of phoenix": 60]);
      skill += (["cry of phoenix": 50]);
    }
    if (guild_level >= 3) {
      skill += (["faith of Anrax": 70]);
      skill += (["cry of phoenix": 60]);
    }
   if (guild_level >= 4) {
      skill += (["wrath of phoenix": 65]);
      skill += (["cry of phoenix": 65]);
    }
    if (guild_level >= 5) {
      skill += (["faith of Anrax": 80]);
      skill += (["wrath of phoenix": 75]);
    }
    if (guild_level >= 6) {
      skill += (["wrath of phoenix": 80]);
      skill += (["cry of phoenix": 85]);
    }
    if (guild_level >= 7) {
      skill += (["faith of Anrax": 100]);
      skill += (["wrath of phoenix": 100]);
      skill += (["cry of phoenix": 100]);
    }
return skill;
}

