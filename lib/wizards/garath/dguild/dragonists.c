inherit "guilds/guilds/guild";
inherit "room/room";
#define TP this_player()

void reset(status x) {
  load_plaque();
  if(x) return;
  add_exit("cs","/world/city/cs");
  short_desc = "Huge hall full of Dra'gondar";
  long_desc  = "There are Dragon eggs in every corner of this room, maybe this is\n"+
               "the place where Dragons hatch their eggs. Some eggs have already\n"+
               "hatched and some baby Dragons are yelling food from bigger Dragons\n"+
               "Few big silver Dragons are watching your every move...\n";
}

void init() {
  ::init();
  guild_init();
}

int guild_max_level() {
  return 50;
}

string guild_name() {
    return "Dra'gondar";
}

status check_joining_rec() {
    if(TP->query_level() < 100) {
      write("You feel too weak to join. Maybe you should come back when you're stronger?\n");
      return 0;
    }
    if(TP->query_guild_level("Fighters") < 10) {
      write("You must have completed the Fighters guild first.\n");
      return 0;
    }
    if(!TP->query_tester()) {
      write("You aren't invited to this guild.\n");
      return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  int i;
  sk = ([ ]);
  /* tosi vittumainen req systeemi, joka levelli pit^D^D treenaa yks prossa joka skilli^D t. Celtron */
  /* niin ja jos levelli on 1 niin se on joining req my^Vs */
  for(i=2;i<51;i++) { sk += ([i:"summon dragon:"+i+";"]); }
  for(i=2;i<51;i++) { sk += ([i:"shaldrin:"+i+";"]); }
  return sk;
}

get_bonuses(level) {
  return "str 2 , con 3 , dex 3 , int 2 , wis 2";
}

skill_list(int guild_level) {
  mapping skill;
  int i;
   skill = ([ ]);
   skill += (["summon dragon":guild_level*2]);
   skill += (["shaldrin":guild_level*2]);
   
  return skill;
}
