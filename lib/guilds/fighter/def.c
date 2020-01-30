inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("south","/guilds/fighter/fighter");
  short_desc = "The Defenders Guild";
  long_desc = "Various shields and armour hang on the walls,\n"+
		"this is the place to a defender to train.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Defenders";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
    }
    if (this_player()->query_guild_level("martial artist") != 0) {
        write("Anrax had some cross words with Rhee and after few fights he decided that\n"+
                 "he wont let artists join defenders guild anymore.\n");
        return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([2:"parry:30;"]);
  sk += ([3:"dodge:30;"]);
  sk += ([7:"shield parry:50;"]);
  sk += ([11:"dodge:60;"]);
  sk += ([13:"stunned maneuvers:20;"]);
  sk += ([16:"ignore wrong strike:30;"]);
  sk += ([20:"foresee attack:40;defend:40;"]);
  return sk;
}

get_bonuses(level) {
  return "dex 1 , con 1 , ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
      skill += (["dodge":(int) 40]);
      skill += (["parry":(int) 30]);
    }
    if (guild_level >= 2) {
      skill += (["alertness":(int) 20]);
      skill += (["shield parry":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["parry":(int) 40]);
      skill += (["shield parry":(int) 30]);
    }
    if (guild_level >= 4) {
      skill += (["shield bash":(int) 20]);
      skill += (["shield parry":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["dodge":(int) 50]);
      skill += (["parry":(int) 50]);
      skill += (["bravery":(int) 20]);
    }
    if (guild_level >= 6) {
      skill += (["alertness":(int) 40]);
      skill += (["shield parry":(int) 50]);
      skill += (["bravery":(int) 40]);
    }
    if (guild_level >= 7) {
      skill += (["parry":(int) 60]);
      skill += (["riposte":(int) 20]);
    }
    if (guild_level >= 8) {
      skill += (["alertness":(int) 50]);
      skill += (["shield parry":(int) 60]);
      skill += (["bravery":(int) 60]);
    }
    if (guild_level >= 9) {
      skill += (["riposte":(int) 40]);
      skill += (["dodge":(int) 60]);
    }
    if (guild_level >= 10) {
      skill += (["alertness":(int) 60]);
      skill += (["shield bash":(int) 60]);
    }
    if (guild_level >= 11) {
      skill += (["foresee attack":(int) 20]);
      skill += (["stunned maneuvers":(int) 20]);
      skill += (["bravery":(int) 80]);
    }
    if (guild_level >= 12) {
      skill += (["ignore wrong strike":(int) 20]);
      skill += (["parry":(int) 70]);
      skill += (["shield parry":(int) 70]);
    }
    if (guild_level >= 13) {
      skill += (["foresee attack":(int) 30]);
      skill += (["shield bash":(int) 70]);
    }
    if (guild_level >= 14) {
      skill += (["stunned maneuvers":(int) 40]);
      skill += (["ignore wrong strike":(int) 30]);
    }
    if (guild_level >= 15) {
      skill += (["riposte":(int) 60]);
      skill += (["dodge":(int) 70]);
      skill += (["bravery":(int) 100]);
    }
    if (guild_level >= 16) {
      skill += (["alertness":(int) 70]);
      skill += (["dodge":(int) 80]);
      skill += (["parry":(int) 80]);
    }
    if (guild_level >= 17) {
      skill += (["riposte":(int) 70]);
      skill += (["shield parry":(int) 80]);
      skill += (["stunned maneuvers":(int) 50]);
      skill += (["ignore wrong strike":(int) 40]);
      skill += (["defend":(int) 30]);
    }
    if (guild_level >= 18) {
      skill += (["foresee attack":(int) 50]);
      skill += (["ignore wrong strike":(int) 50]);
    }
    if (guild_level >= 19) {
      skill += (["alertness":(int) 80]);
      skill += (["riposte":(int) 80]);
      skill += (["foresee attack":(int) 60]);
      skill += (["ignore wrong strike":(int) 60]);
      skill += (["stunned maneuvers":(int) 60]);
      skill += (["defend":(int) 40]);
    }
    if (guild_level >= 20) {
      skill += (["shield parry":(int) 100]);
      skill += (["alertness":(int) 100]);
      skill += (["riposte":(int) 100]);
      skill += (["foresee attack":(int) 100]);
      skill += (["ignore wrong strike":(int) 100]);
      skill += (["stunned maneuvers":(int) 100]);
      skill += (["dodge":(int) 100]);
      skill += (["parry":(int) 100]);
      skill += (["shield bash":(int) 100]);
      skill += (["defend":(int) 60]);
    }

  return skill;
}


