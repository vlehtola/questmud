inherit "guilds/guilds/guild";
inherit "room/room";

string wskill, mskill;

reset(arg) {
  load_plaque();
  if(arg) return;
  set_not_out(1);
  set_light(3);
  add_exit("north","/guilds/fighter/axes");
  add_exit("east","/guilds/fighter/fighter");
  add_exit("south","/guilds/fighter/blades");
  short_desc = "The bludgeon specialists training area";
  long_desc = 
"A big training hall contains very little decoration. There are all kinds of\n"+
"hammers, clubs, chained weapons and weapons with no sharp edges.\n"+
"The different bludgeonusers train here to get better in hammering their"+
" enemies.\n";
  wskill = "bludgeons";
  mskill = "pound";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 4;
}

guild_name() {
    return "Bludgeonists";
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
  sk += ([2:wskill+":40;"]);
  sk += ([4:mskill+":30;"+wskill+":70;"]);
  return sk;
}

get_bonuses(level) {
  /* yhteensa 5 stattia / levelli */
  return "str 2 , ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) { skill += ([wskill:(int) 70]); }
    if (guild_level >= 2) {
      skill += ([wskill:(int) 80]);
      skill += ([mskill:(int) 30]);
    }
    if (guild_level >= 3) {
      skill += ([wskill:(int) 90]);
      skill += ([mskill:(int) 60]);
    }
    if (guild_level >= 4) {
      skill += ([wskill:(int) 100]);
      skill += ([mskill:(int) 80]);
    }
  return skill;
}

