inherit "wizards/yodin/animals/yodingui.c";
inherit "room/room";
#define TP this_player()

void reset(status x) {
  load_plaque();
  if(x) return;
  add_exit("cs","/world/city/cs");
  short_desc = "Animal masters";
  long_desc  = "if you are in here yodin will kill you.\n";
}

void init() {
  ::init();
  guild_init();
}

int guild_max_level() {
  return 50;
}

string guild_name() {
    return "Animal masters";
}

status check_joining_rec() {
    if (this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
}


  if(TP->query_real_name() != "yodintest" && TP->query_real_name() != "yodin") {
      write("You aren't invited to this guild.\n");
      return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  int i;
  sk = ([ ]);
  for(i=2;i<51;i++) { sk += ([i:"summon bear:"+i+";"]); }
  for(i=2;i<51;i++) { sk += ([i:"bear mastery:"+i+";"]); }
return sk;
}

get_bonuses(level) {
  return "str 50 , con 50 , dex 50 , int 50 , wis 50";
}

skill_list(int guild_level) {
  mapping skill;
  int i;
    skill = ([ ]);
   skill += (["summon bear":guild_level+1]);
   skill += (["bear mastery":guild_level+1]);
  return skill;
}
