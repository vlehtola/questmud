inherit "room/room";
inherit "guilds/guilds/guild";

reset(arg) {
  object plaque;
  if (!present("plaque")) {
    plaque = clone_object("world/guilds/plaque.c");
    move_object(plaque, this_object());
  }
  if(arg) return;
  add_exit("out","/world/artist/school");
  short_desc = "A kata training area";
  long_desc = "Students come here to train their kata; minimize the movements,\n"+
	"maximize their effect and to acheive perfect control of their bodies.\n"+
	"It looks like the kata learned here is for unarmed fighting against\n"+
	"animals and bludgeon wielders.\n";
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
    return "Way of the Wood";
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
  sk += ([4:"sneaky hands:50;feeding hands:50;"]);
  sk += ([5:"thunderclap:30;hunting hands:30;"]);
  return sk;
}

/*
  Stats:  
  Str 5%  
  Dex 10%
  Con 10%
*/

get_bonuses(level) {
  if(level >= 5) return;
  return "str 1 , dex 2 , con 2 , ";
}

/*
  str[1] = "sneaky hands";
  str[4] = "feeding hands";
  str[6] = "thunderclap";
  str[9] = "hunting hands";
*/

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
      skill += (["sneaky hands":(int) 20]);
      skill += (["feeding hands":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["sneaky hands":(int) 30]);
      skill += (["feeding hands":(int) 30]);
    }
    if (guild_level >= 3) {
      skill += (["sneaky hands":(int) 50]);
      skill += (["feeding hands":(int) 50]);
      skill += (["thunderclap":(int) 20]);
      skill += (["hunting hands":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["sneaky hands":(int) 70]);
      skill += (["feeding hands":(int) 70]);
      skill += (["thunderclap":(int) 40]);
      skill += (["hunting hands":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["sneaky hands":(int) 100]);
      skill += (["feeding hands":(int) 100]);
      skill += (["thunderclap":(int) 100]);
      skill += (["hunting hands":(int) 100]);
      skill += (["knowledge of the way":(int) 40]);
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

