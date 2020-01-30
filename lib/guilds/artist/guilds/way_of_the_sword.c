inherit "world/guilds/guild";
inherit "room/room";

reset(arg) {
  object plaque;
  if (!present("plaque")) {
    plaque = clone_object("world/guilds/plaque.c");
    move_object(plaque, this_object());
  }
  if(!present("note")) {
    move_object(clone_object("/world/artist/note"),this_object());
  }
  if(arg) return;
  add_exit("out","/world/artist/school");
  short_desc = "A kata training area";
  long_desc = "Students come here to train their kata; minimize the movements,\n"+
	"maximize their effect and to acheive perfect control of their bodies.\n"+
	"It looks like the kata learned here is for fighting with sword against\n"+
	"all kinds of enemies. It looks really efficient.\n";
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
    return "Way of the Sword";
}

check_joining_rec() {
  if (this_player()->query_guild_level("Way of the Wood") < 5) {
      write("You must have completed the Way of the Wood first.\n");
      return 0;
  }
  if (this_player()->query_guild_level("Way of the Stone") < 5) {
      write("You must have completed the Way of the Stone first.\n");
      return 0;
  }
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([9:"slicing blade:40;sneaky wind:40;sharp lightning:40;"+
	"invisible storm:40;bloodhunt:40;"]);
  return sk;
}

/*
  Stats:  
  Str 10%  
  Dex 30%
  Con 10%
*/

get_bonuses(level) {
  if(level >= 10) return;
  return "str 1 , dex 3 , con 1 , ";
}

/*
  slicing blade
  sneaky wind
  sharp lightning
  invisible storm
  bloodhunt
*/

get_skill_max(num, how, lvl) {
    mapping skill;
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(guild_name());
    skill = ([ ]);
    if (lvl) {
	 guild_level = lvl;
	 if (guild_level > 10) { guild_level = 10; }
    }
    if (!guild_level) {
	write("Bugged.. not a member\n");
	return 0;
    }
    if (guild_level >= 3) {
      skill += (["blades":(int) 30]);
      skill += (["slicing blade":(int) 20]);
      skill += (["sneaky wind":(int) 20]);
      skill += (["sharp lightning":(int) 20]);
      skill += (["invisible storm":(int) 20]);
      skill += (["bloodhunt":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["blades":(int) 60]);
      skill += (["slicing blade":(int) 30]);
      skill += (["sneaky wind":(int) 30]);
      skill += (["sharp lightning":(int) 30]);
      skill += (["invisible storm":(int) 30]);
      skill += (["bloodhunt":(int) 30]);
    }
    if (guild_level >= 7) {
      skill += (["blades":(int) 80]);
      skill += (["slicing blade":(int) 40]);
      skill += (["sneaky wind":(int) 40]);
      skill += (["sharp lightning":(int) 40]);
      skill += (["invisible storm":(int) 40]);
      skill += (["bloodhunt":(int) 40]);
    }
    if (guild_level >= 9) {
      skill += (["blades":(int) 90]);
      skill += (["slicing blade":(int) 50]);
      skill += (["sneaky wind":(int) 50]);
      skill += (["sharp lightning":(int) 50]);
      skill += (["invisible storm":(int) 50]);
      skill += (["bloodhunt":(int) 50]);
    }
    if (guild_level >= 10) {
      skill += (["blades":(int) 100]);
      skill += (["slicing blade":(int) 100]);
      skill += (["sneaky wind":(int) 100]);
      skill += (["sharp lightning":(int) 100]);
      skill += (["invisible storm":(int) 100]);
      skill += (["bloodhunt":(int) 100]);
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

