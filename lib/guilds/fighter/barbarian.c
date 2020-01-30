inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("out","/world/hallway/cave");
  short_desc = "The Barbarian Guild";
  long_desc = "This is the place, a dim cave, that is also know as the fearsome Barbarian Guild.\n"+
         "The walls are pure granite and the air smells like sweat. What a barbaric place.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Barbarians";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
    }
    return 1;
} 
check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([4:"throw weight:40;inner strength:20;"]);
  sk += ([7:"round blow:50;"]);
  sk += ([10:"stun:30;"]);
  if(lev == 2 && this_player()->query_level() < 10) return 0;
  if(this_player()->query_wiz()) write("Check_advance done.\n");
  return sk;
}

get_bonuses(level) {
  return "str 1 , con 1 , ";
}
/*
Barbarians sub: 10
  Skills:
    throw weight 100
    Round blow: 100
    Stun: 60
    Battlecry: 100
*/
skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);
    if (guild_level >= 1) {
      skill += (["throw weight":(int) 20]);
      skill += (["inner strength":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["throw weight":(int) 40]);
      skill += (["battlecry":(int) 20]);
    } 
    if (guild_level >= 3) {
      skill += (["throw weight":(int) 50]);
      skill += (["inner strength":(int) 40]);
      skill += (["round blow":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["throw weight":(int) 60]);
      skill += (["round blow":(int) 40]);
      skill += (["battlecry":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["throw weight":(int) 70]);
      skill += (["inner strength":(int) 50]);
      skill += (["round blow":(int) 60]);
    }
    if (guild_level >= 6) {
      skill += (["throw weight":(int) 80]); 
      skill += (["inner strength":(int) 60]);
      skill += (["battlecry":(int) 60]);
    }
    if (guild_level >= 7) {
      skill += (["throw weight":(int) 100]);
      skill += (["round blow":(int) 70]);
      skill += (["battlecry":(int) 70]);
      skill += (["strike":30]);
    }
    if (guild_level >= 8) {
      skill += (["stun":(int) 20]);
      skill += (["battlecry":(int) 80]);
      skill += (["strike":50]);
    }
    if (guild_level >= 9) {
      skill += (["round blow":(int) 80]);
      skill += (["stun":(int) 30]);
      skill += (["battlecry":(int) 90]);
      skill += (["strike":60]);
    } 
    if (guild_level >= 10) {
      skill += (["round blow":(int) 100]);
      skill += (["stun":(int) 50]);
      skill += (["battlecry":(int) 100]);
      skill += (["strike":100]);
    }
  return skill;
}
