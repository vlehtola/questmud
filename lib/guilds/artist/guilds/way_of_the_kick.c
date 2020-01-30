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
  short_desc = "The training room of the followers of the Way of the Kick";
  long_desc = short_desc+"\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 5;
}

guild_long_name() {
    return guild_name();
}
guild_name() {
    return "Way of the Kick";
}

check_joining_rec() {
  if (this_player()->query_guild_level("Artists") < 20) {
      write("You must have completed the Artists guild first.\n");
      return 0;
  }
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([4:"turnkick:50;"]);
  sk += ([5:"snapkick:40;"]);
  return sk;
}

/*
  Stats:  
  Str 10%  
  Dex 10%
  Con 5%
  Hpregen: 5
*/

get_bonuses(level) {
  if(level >= 5) return;
  return "str 2 , dex 2 , con 2 , ";
}

get_skill_max(num, how, lvl) {
    mapping skill;
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(guild_name());
    skill = ([ ]);

    if (lvl) {
	 guild_level = lvl;
	 if (guild_level > 5) { guild_level = 5; }
    }
    if (!guild_level) {
	write("Bugged.. not a member\n");
	return 0;
    }
    if (guild_level >= 1) {
      skill += (["sidekick":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["turnkick":(int) 60]);
    }
    if (guild_level >= 3) {
      skill += (["sidekick":(int) 40]);
      skill += (["snapkick":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["sidekick":(int) 60]);
      skill += (["snapkick":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["turnkick":(int) 100]);
      skill += (["sidekick":(int) 100]);
      skill += (["snapkick":(int) 100]);
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

