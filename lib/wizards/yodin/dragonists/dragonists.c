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
    if (this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
}
    if(TP->query_real_name() != "jenny" && TP->query_real_name() != "yodin") {
      write("You aren't invited to this guild.\n");
      return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  int i;
  sk = ([ ]);
  for(i=2;i<51;i++) { sk += ([i:"summon dragon:"+i+";"]); }
  for(i=2;i<51;i++) { sk += ([i:"shaldrin:"+i+";"]); }
return sk;
}

get_bonuses(level) {
  return "str 50 , con 50 , dex 50 , int 50 , wis 50";
}

skill_list(int guild_level) {
  mapping skill;
  int i;
    skill = ([ ]);
   skill += (["summon dragon":guild_level+1]);
   skill += (["shaldrin":guild_level+1]);
  return skill;
}
