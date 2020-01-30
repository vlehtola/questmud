inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("south","wizards/nalle/area/i1");
  short_desc = "The veterans training area";
  long_desc = "The knights of Chamron train here their own special\n"+
              "skills they have learned in many different battles.\n"+ 
	      "This is the training area of the Veterans.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Veterans";
}

check_joining_rec() {
    if (this_player()->query_guild_level("fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
    }
    if (this_player()->query_guild_level("defenders") < 10) {
        write("You must have completed atleast 10 levels of the defenders guild first.\n");
        return 0;
    }
    if (this_player()->query_guild_level("weaponmaster") < 10) {
        write("You must have completed the Weaponmasters guild first.\n");
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
  return "str 1 , dex 1 , ";
}

/*
  deceived attack
  find weakness
  inner strength
  enhance criticals
  tremendous blow
  first strike
*/

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
      skill += (["first strike":(int) 20]);
      skill += (["inner strength":(int) 20]);
      skill += (["enhance criticals":(int) 10]);
    }
    if (guild_level >= 2) {
      skill += (["find weakness":(int) 40]);
      if(this_player()->query_skills("defend") >= 40)
      skill += (["defend":(int) 70]);
    }
    if (guild_level >= 3) {
      skill += (["inner strength":(int) 40]);
      skill += (["deceived attack":(int) 20]);  
      if(this_player()->query_skills("defend") >= 40)
      skill += (["defend":(int) 80]);
    }
    if (guild_level >= 4) {
      skill += (["first strike":(int) 40]);
      skill += (["inner strength":(int) 50]);
      skill += (["tremendous blow":(int) 20]);
      skill += (["enhance criticals":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["inner strength":(int) 60]);
      skill += (["tremendous blow":(int) 40]);
      skill += (["deceived attack":(int) 30]);  
      if(this_player()->query_skills("defend") >= 40)
      skill += (["defend":(int) 100]);
    }
    if (guild_level >= 6) {
      skill += (["first strike":(int) 60]);
      skill += (["tremendous blow":(int) 50]);
      skill += (["find weakness":(int) 50]);
      skill += (["enhance criticals":(int) 30]);
    }
    if (guild_level >= 7) {
      skill += (["inner strength":(int) 70]);
      skill += (["tremendous blow":(int) 70]);
      skill += (["enhance criticals":(int) 40]);
      skill += (["deceived attack":(int) 40]);  
    }
    if (guild_level >= 8) {
      skill += (["first strike":(int) 80]);
      skill += (["inner strength":(int) 80]);
      skill += (["find weakness":(int) 60]);
      skill += (["deceived attack":(int) 50]);  
    }
    if (guild_level >= 9) {
      skill += (["first strike":(int) 100]);
      skill += (["tremendous blow":(int) 80]);
      skill += (["find weakness":(int) 70]);
      skill += (["enhance criticals":(int) 50]);
    }
    if (guild_level >= 10) {
      skill += (["inner strength":(int) 100]);
      skill += (["tremendous blow":(int) 100]);
      skill += (["find weakness":(int) 100]);
      skill += (["enhance criticals":(int) 100]);
      skill += (["deceived attack":(int) 100]);  
    }
  return skill;
}

