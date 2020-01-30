inherit "guilds/guilds/guild";
inherit "room/room";

string wskill, mskill;

reset(arg) {
  load_plaque();
  if(arg) return;
  set_not_out(1);
  set_light(3);
  add_exit("north","/guilds/fighter/bludgeons");
  add_exit("northwest", "/guilds/paladin/baseguild");
  short_desc = "The blademaster's training area";
  long_desc = 
"A big training hall contains very little decoration. There are all kinds of\n"+
"blades: daggers, swords, scimitars and others, are hanging from the south\n"+
"wall. Fighters who favor blades take their training here.\n";
  wskill = "blades";
  mskill = "slash";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 7;
}

guild_name() {
    return "Blademasters";
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
  sk += ([3:wskill+":40;"]);
  sk += ([7:mskill+":30;"+wskill+":70;"]);
  return sk;
}

get_bonuses(level) {
  return "dex 1 , str 1 , ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) { skill += ([wskill:(int) 50]); }
    if (guild_level >= 2) { skill += ([wskill:(int) 60]); }
    if (guild_level >= 3) {
      skill += ([wskill:(int) 70]);
      skill += ([mskill:(int) 10]);
    }
    if (guild_level >= 4) {
      skill += ([wskill:(int) 80]);
      skill += ([mskill:(int) 20]);
    }
    if (guild_level >= 5) {
      skill += ([wskill:(int) 90]);
      skill += ([mskill:(int) 40]);
    }
    if (guild_level >= 6) {
      skill += ([mskill:(int) 60]);
    }
    if (guild_level >= 7) {
      skill += ([wskill:(int) 100]);
      skill += ([mskill:(int) 80]);
    }
  return skill;
}

