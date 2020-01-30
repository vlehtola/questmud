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
  short_desc = "The training room of the followers of the Way of Understanding";
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
    return "Way of Understanding";
}

check_joining_rec() {
  int i;
  if (this_player()->query_guild_level("Way of the Stone") == 5) {
     i = 1;
  }
  if (this_player()->query_guild_level("Way of the Wood") == 5) {
     i = 1;
  }
  if(i) return 1;    
  write("You must have completed the Way of the Wood or Stone first.\n");
  return 0;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([5:"meditation:40;"]);
  sk += ([8:"nerve mastery:30;"]);
  sk += ([9:"sixth instinct:40;"]);
  sk += ([10:"breath control:40;"]);
  return sk;
}
get_bonuses(level) {
  if(level >= 10) return;
  return "str 1 , dex 1 , con 2 , int 2 , wis 2 , ";
}
/*
  -meditation (joku healing skilli)
  -breath control
  -sixth instinct (joku defense juttu)
  -nerve mastery
  -anatomy (massage mastery)
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
    if (guild_level >= 1) {
      skill += (["meditation":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["nerve mastery":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["anatomy":(int) 20]);
      skill += (["meditation":(int) 40]);
    }
    if (guild_level >= 4) {
      skill += (["sixth instinct":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["breath control":(int) 20]);
    }
    if (guild_level >= 6) {
      skill += (["meditation":(int) 50]);
    }
    if (guild_level >= 7) {
      skill += (["anatomy":(int) 40]);
      skill += (["nerve mastery":(int) 40]);
    }
    if (guild_level >= 8) {
      skill += (["sixth instinct":(int) 40]);
      skill += (["meditation":(int) 60]);
    }
    if (guild_level >= 9) {
      skill += (["breath control":(int) 40]);
    }
    if (guild_level >= 4) {
      skill += (["sixth instinct":(int) 100]);
      skill += (["breath control":(int) 100]);
      skill += (["anatomy":(int) 100]);
      skill += (["meditation":(int) 100]);
      skill += (["nerve mastery":(int) 100]);
      skill += (["knowledge of the way":(int) 50]);
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

