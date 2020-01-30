inherit "room/room";
inherit "/guilds/guilds/guild";

string wskill, mskill;

reset(arg) {
  load_plaque();
  if(arg) return;
  set_not_out(1);
  set_light(3);
  add_exit("south","/guilds/fighter/bludgeons");
  short_desc = "The axe users training area";
  long_desc = 
"A big training hall contains very little decoration. There are all kinds of\n"+
"axes, from small to two-edged huge ones. Axe wielding fighters come\n"+
"here to perfect their skills.\n";
  wskill = "axes";
  mskill = "cut";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 14;
}

guild_name() {
    return "Axers";
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
  sk += ([4:wskill+":40;"]);
  sk += ([10:wskill+":70;"]);
  return sk;
}

get_bonuses(level) {
  return "str 1 , con 1 , ";
}

skill_list(int guild_level) {
  mapping skill;
  int wsk, msk;
  skill = ([ ]);

  wsk = 60 + (guild_level-3)*5;
  if(wsk > 100) wsk = 100;
  skill += ([wskill: wsk ]);

  msk = (guild_level-6) *10;
  if(msk < 0) msk = 0;
  if(msk > 80) msk = 80;
  skill += ([mskill: msk ]);

  return skill;
}

