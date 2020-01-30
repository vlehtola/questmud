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
      skill += (["chanting":(int) 10]);
      skill += (["channel":(int) 10]);
      skill += (["cast divine":(int) 30]);
      skill += (["cast minor":(int) 30]);
      skill += (["cast transfer":(int) 30]);
      skill += (["cast heal":(int) 30]);
    }
    if (guild_level >= 2) {
      skill += (["channel":(int) 15]);
      skill += (["cast minor":(int) 35]);
    }
    if (guild_level >= 3) {
      skill += (["cast divine":(int) 35]);
      skill += (["cast transfer":(int) 35]);
      skill += (["cast heal":(int) 35]);
    }
    if (guild_level >= 4) {
      skill += (["channel":(int) 20]);
      skill += (["cast minor":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["cast divine":(int) 40]);
    }
    if (guild_level >= 6) {
      skill += (["channel":(int) 25]);
    }
    if (guild_level >= 7) {
      skill += (["chanting":(int) 15]);
      skill += (["cast minor":(int) 45]);
    } 
    if (guild_level >= 8) {
      skill += (["channel":(int) 30]);
      skill += (["cast transfer":(int) 40]);
      skill += (["cast heal":(int) 40]);
    }
    if (guild_level >= 9) {
      skill += (["cast divine":(int) 45]);

}
    if (guild_level >= 10) {
      skill += (["cast minor":(int) 55]);
    }
    if (guild_level >= 11) {
      skill += (["channel":(int) 35]);
      skill += (["cast cure":(int) 10]);
    }
    if (guild_level >= 12) {
      skill += (["chanting":(int) 20]);
    }
    if (guild_level >= 13) {
      skill += (["cast divine":(int) 50]);
      skill += (["cast minor":(int) 60]);
    }
    if (guild_level >= 14) {
      skill += (["channel":(int) 40]);
      skill += (["cast cure":(int) 15]);
    }
    if (guild_level >= 15) {
      skill += (["cast transfer":(int) 45]);
      skill += (["cast heal":(int) 45]);
    }
    if (guild_level >= 16) {
      skill += (["chanting":(int) 25]);
      skill += (["cast minor":(int) 65]);
    }
    if (guild_level >= 17) {
      skill += (["cast divine":(int) 55]);
      skill += (["cast cure":(int) 20]);
    }
    if (guild_level >= 18) {
      skill += (["channel":(int) 45]);
      skill += (["cast minor":(int) 70]);
    }
    if (guild_level >= 19) {
      skill += (["cast minor":(int) 75]);
    }
    if (guild_level >= 20) {
      skill += (["chanting":(int) 30]);
      skill += (["channel":(int) 50]);
      skill += (["cast divine":(int) 60]);
      skill += (["cast minor":(int) 100]);
      skill += (["cast transfer":(int) 50]);
      skill += (["cast heal":(int) 50]);
      skill += (["cast cure":(int) 25]);
    }
return skill;
}
