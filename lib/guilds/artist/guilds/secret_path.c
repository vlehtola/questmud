inherit "world/guilds/guild";
inherit "room/room";

reset(arg) {
  object plaque;
  if (!present("plaque")) {
    plaque = clone_object("world/guilds/plaque.c");
    move_object(plaque, this_object());
  }
  if(arg) return;
  add_exit("out","/world/artist/school");
  short_desc = "The training room of the followers of the Secret Path";
  long_desc = short_desc+"\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_long_name() {
    return guild_name();
}
guild_name() {
    return "Secret Path";
}

check_joining_rec() {
  if (this_player()->query_guild_level("Way of the Punch") < 5) {
      write("You must have completed the Way of the Punch first.\n");
      return 0;
  }
  if (this_player()->query_guild_level("Way of the Kick") < 5) {
      write("You must have completed the Way of the Kick first.\n");
      return 0;
  }
  if (this_player()->query_guild_level("Way of Understanding") < 10) {
      write("You must have completed the Way of Understanding first.\n");
      return 0;
  }
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}
/*
  Stats:  
  Str 30%  
  Dex 10%
  Con 10%
*/
get_bonuses(level) {
  if(level >= 10) return;
  return "str 3 , dex 1 , con 1 , ";
}
/*
  fatal blow
  headbang
  cranekick
*/
get_skill_max(num, how, lvl) {
    mapping skill;
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(guild_name());
    skill = ([ ]);
    if (lvl) {
      guild_level = lvl;
      if (guild_level > guild_max_level())
	{ guild_level = guild_max_level(); }
    }
    if (!guild_level) {
	write("Bugged.. not a member\n");
	return 0;
    }
    if (guild_level >= 2) {
      skill += (["headbang":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["cranekick":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["headbang":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["fatal blow":(int) 20]);
    }
    if (guild_level >= 6) {
      skill += (["cranekick":(int) 40]);
    }
    if (guild_level >= 7) {
      skill += (["fatal blow":(int) 40]);
    }
    if (guild_level >= 8) {
      skill += (["headbang":(int) 50]);
    }
    if (guild_level >= 9) {
      skill += (["cranekick":(int) 50]);
    }
    if (guild_level >= 10) {
      skill += (["headbang":(int) 100]);
      skill += (["cranekick":(int) 100]);
      skill += (["fatal blow":(int) 100]);
      skill += (["knowledge of the way":(int) 70]);
    }

    skill_num = m_indices(skill);
    skill_max = m_values(skill);
    if (how == 0) {
	while (i < sizeof(skill_max)) {
	    if (skill_num[i] == num) {
		return skill_max[i];
	    }
	    i += 1;
	}  
    }
    if (how == 1) {
	return skill_max[num];
    }
    if (how == 2 || how == 3) {
	return skill_num[num];
    }
    if (how == 4) {
	return skill_max;
    }
}

