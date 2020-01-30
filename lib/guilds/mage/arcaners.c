inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("south","/guilds/mage/tower2");
  short_desc = "The arcaners guild room";
  long_desc =
"This room is the arcaners training area. It is decorated with colored\n"+
"carpets and tapistry. The arcaners guild is specialized in various\n"+
"enhancements of the offensive spells.\n";
 
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Arcaners";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Apprentice mages") != 20) {
        write("Must have completed the Appretice Mages first.\n");
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
  /* yhteensa 2 stattia / levelli */
  return "int 2 , con -1 , ";
}
/*
stunning blast
distract concentration
proximity blast
*/
skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["stunning blast":(int) 10]);
      skill += (["distract concentration":(int) 10]);
    }
    if (guild_level >= 2) {
      skill += (["stunning blast":(int) 15]);
      skill += (["distract concentration":(int) 15]);
      skill += (["cast force field":(int) 10]);
    }
    if (guild_level >= 3) {
      skill += (["stunning blast":(int) 25]);
      skill += (["distract concentration":(int) 25]);
      skill += (["cast force field":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["stunning blast":(int) 30]);
      skill += (["distract concentration":(int) 30]);
      skill += (["proximity blast":(int) 10]);
      skill += (["cast force field":(int) 25]);
    }
    if (guild_level >= 5) {
      skill += (["stunning blast":(int) 40]);
      skill += (["distract concentration":(int) 40]);
      skill += (["proximity blast":(int) 20]);
      skill += (["cast force field":(int) 30]);
    }
    if (guild_level >= 6) {
      skill += (["stunning blast":(int) 50]);
      skill += (["distract concentration":(int) 50]);
      skill += (["proximity blast":(int) 35]);
      skill += (["cast force field":(int) 40]);
    }
    if (guild_level >= 7) {
      skill += (["stunning blast":(int) 60]);
      skill += (["distract concentration":(int) 60]);
      skill += (["proximity blast":(int) 45]);
      skill += (["cast force field":(int) 45]);
    }
    if (guild_level >= 8) {
      skill += (["stunning blast":(int) 70]);
      skill += (["distract concentration":(int) 70]);
      skill += (["proximity blast":(int) 55]);
      skill += (["cast force field":(int) 50]);
    }
    if (guild_level >= 9) {
      skill += (["stunning blast":(int) 80]);
      skill += (["distract concentration":(int) 80]);
      skill += (["proximity blast":(int) 70]);
      skill += (["cast force field":(int) 55]);
    }
    if (guild_level >= 10) {
      skill += (["stunning blast":(int) 100]);
      skill += (["distract concentration":(int) 100]);
      skill += (["proximity blast":(int) 100]);
      skill += (["cast force field":(int) 100]);
    }

return skill;
}
