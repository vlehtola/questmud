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
  short_desc = "The training room of the followers of the inner path";
  long_desc = short_desc+ "\n";
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
    return "Inner Path";
}

check_joining_rec() {
  if (this_player()->query_guild_level("Way of Understanding") < 10) {
      write("You must have completed the Way of Understanding first.\n");
      return 0;
  }
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([6:"sacrifice ritual:60;"]);
  sk += ([8:"ritual strictness:40;ritual exactness:40;"]);
  return sk;
}
get_bonuses(level) {
  if(level >= guild_max_level()) return;
  return "str 1 , dex 3 , con 1 , ";
}
/*
  sacrifice ritual
  ritual exactness
  ritual strictness
  ritual mastery
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
      skill += (["sacrifice ritual":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["ritual strictness":(int) 20]);
      skill += (["sacrifice ritual":(int) 40]);
    }
    if (guild_level >= 4) {
      skill += (["ritual exactness":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["ritual strictness":(int) 40]);
      skill += (["sacrifice ritual":(int) 60]);
    }
    if (guild_level >= 6) {
      skill += (["ritual exactness":(int) 40]);
    }
    if (guild_level >= 7) {
      skill += (["sacrifice ritual":(int) 80]);
      skill += (["ritual mastery":(int) 20]);
    }
    if (guild_level >= 8) {
      skill += (["ritual strictness":(int) 60]);
    }
    if (guild_level >= 9) {
      skill += (["ritual exactness":(int) 60]);
    }
    if (guild_level >= 10) {
      skill += (["sacrifice ritual":(int) 100]);
      skill += (["ritual mastery":(int) 100]);
      skill += (["ritual exactness":(int) 100]);
      skill += (["ritual strictness":(int) 100]);
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


