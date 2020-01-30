inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("out","/wizards/bulut/forl/house5");
  short_desc = "The Acrobats training area";
  long_desc = "The backroom of a hobbit's home has been transformed into\n"+
          "the training center of the secret acrobat guild.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 6;
}

guild_name() {
    return "Acrobats";
}

check_joining_rec() {
    if(this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
    }
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([2:"coordination:30;"]);
  sk += ([4:"coordination:70;"]);
  sk += ([6:"tumble:60;"]);
  return sk;
}
get_bonuses(level) {
  if(level >= guild_max_level()) return;
  return "dex 3 , con 1 , ";
}
/*
  coordination
  tumble
  agility
*/

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);
    if (guild_level >= 1) {
      skill += (["coordination":(int) 40]);
      skill += (["endurance":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["coordination":(int) 60]);
      skill += (["tumble":(int) 20]);
      skill += (["endurance":(int) 30]);
    }
    if (guild_level >= 3) {
      skill += (["coordination":(int) 100]);
      skill += (["tumble":(int) 40]);
      skill += (["endurance":(int) 50]);
    }
    if (guild_level >= 4) {
      skill += (["agility":(int) 30]);
      skill += (["tumble":(int) 50]);
      skill += (["endurance":(int) 70]);
    }
    if (guild_level >= 5) {
      skill += (["tumble":(int) 60]);
      skill += (["agility":(int) 50]);
      skill += (["endurance":(int) 80]);
    }
    if (guild_level >= 6) {
      skill += (["tumble":(int) 100]);
      skill += (["agility":(int) 100]);
      skill += (["endurance":(int) 100]);
    }
  return skill;
}


