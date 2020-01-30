inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("east","/guilds/sorcerer/grizz_priests.c");
  add_exit("up","/guilds/sorcerer/tower/floor2/room12.c");
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
    return "Followers of Grizz";
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
      skill += (["faith of grizz": 20]);
      skill += (["ice meteor": 10]);
    }
    if (guild_level >= 2) {
      skill += (["ice meteor": 15]);
    }
    if (guild_level >= 3) {
      skill += (["faith of grizz": 25]);
      skill += (["ice meteor": 20]);
    }
   if (guild_level >= 4) {
      skill += (["ice meteor": 30]);
      skill += (["bless of grizz": 5]);
    }
    if (guild_level >= 5) {
      skill += (["ice meteor": 30]);
    }
    if (guild_level >= 6) {
      skill += (["ice meteor": 40]);
      skill += (["bless of grizz": 15]);
    }
    if (guild_level >= 7) {
      skill += (["faith of grizz": 50]);
      skill += (["ice meteor": 50]);
      skill += (["bless of grizz": 30]);
    }
return skill;
}

