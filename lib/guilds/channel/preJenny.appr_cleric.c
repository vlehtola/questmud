inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
     load_plaque();
     if (arg) { return; }
     set_not_out(1);
     set_light(3);
  short_desc = "The guild room of Apprentice Clerics";
  long_desc =
"A narrow room full of holy candles. A statue of Cyral raises high\n"+
"in the middle of the room. A holy feeling fills you in this total\n"+
"silence. This is where the apprentice Clerics of Cyral get their\n"+
"tuition.\n";

  add_exit("south", "/guilds/channel/r03");

items = allocate(4);
items[0] = "statue";
items[1] = "A statue of Cyral made out of the fine white marble";
items[2] = "candles";
items[3] = "White candles burning brightly, lighting the whole room";


}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}


guild_name() {
    return "Apprentice clerics";
}




check_joining_rec() {
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([2:"channel:10;cast divine:20;cast minor:20;cast transfer:20;"]);
  return sk;
}

get_bonuses(level) {
  return "con 1 , wis 1 , ";
}



skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }

    if (guild_level >= 1) {
      skill += (["chanting":(int) 5 + guild_level*95/20]);
      skill += (["channel":(int) 5 + guild_level*95/20]);
      skill += (["cast divine":(int) 25 + guild_level*75/20]);
      skill += (["cast minor":(int) 25 + guild_level*75/20]);
      skill += (["cast transfer":(int) 25 + guild_level*75/20]);
      skill += (["cast heal":(int) 25 + guild_level*75/20]);
    }
return skill;
}
