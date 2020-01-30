inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("south","/guilds/channel/r13");

  short_desc = "The guild room of High Clerics";
  long_desc = "A room full of holy candles. The marble walls glow warmth and\n"+
              "there is a painting on the northern wall. This is where the high\n"+
              "Clerics of Cyral get their tuition.\n";

items = allocate(4);
items[0] = "candles";
items[1] = "White candles burning brightly, lighting the whole room";
items[2] = "painting";
items[3] = "A holy painting representing the holy hero, Tevf";

}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 25;
}

guild_name() {
    return "High clerics";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Adept clerics") != 25) {
        write("Must have completed the Adept Clerics first.\n");
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
  return "wis 2 , ";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }

    if (guild_level >= 1) {
      skill += (["chanting":(int) 60]);
      skill += (["channel":(int) 70]);
      skill += (["cast divine":(int) 85]);
      skill += (["cast heal":(int) 80]);
      skill += (["cast transfer":(int) 80]);
      skill += (["cast major":(int) 10]);
      skill += (["cast bless":(int) 50]);
      skill += (["cast soul":(int) 30]);
    }
    if (guild_level >= 2) {
      skill += (["cast wide":(int) 20]);
      skill += (["cast major":(int) 20]);
      skill += (["cast transfer":(int) 85]);
    }
    if (guild_level >= 3) {
      skill += (["cast wide":(int) 40]);
      skill += (["cast divine":(int) 85]);
      skill += (["cast major":(int) 25]);
      skill += (["cast soul":(int) 35]);
    }
    if (guild_level >= 4) {
      skill += (["channel":(int) 75]);
      skill += (["cast cure":(int) 50]);
      skill += (["cast major":(int) 30]);
      skill += (["cast transfer":(int) 90]);
      }
    if (guild_level >= 5) {
      skill += (["cast wide":(int) 60]);
      skill += (["cast major":(int) 35]);
      skill += (["mastery of medicine":(int) 10]);
      skill += (["cast bless":(int) 55]);
      skill += (["cast transfer":(int) 95]);
    }
    if (guild_level >= 6) {
      skill += (["cast cure":(int) 60]);
      skill += (["cast major":(int) 40]);
      skill += (["mastery of medicine":(int) 15]);
      skill += (["cast soul":(int) 40]);
    }
    if (guild_level >= 7) {
      skill += (["cast wide":(int) 70]);
      skill += (["chanting":(int) 65]);
      skill += (["cast major":(int) 45]);
      skill += (["mastery of medicine":(int) 20]);
    }
    if (guild_level >= 8) {
      skill += (["cast cure":(int) 75]);
      skill += (["cast major":(int) 50]);
      skill += (["mastery of medicine":(int) 25]);
      skill += (["cast bless":(int) 60]);
      skill += (["cast alignment":(int) 15]);  
    }
    if (guild_level >= 9) {
      skill += (["cast divine":(int) 90]);
      skill += (["cast cure":(int) 90]);
      skill += (["cast major":(int) 70]);
      skill += (["mastery of medicine":(int) 30]);
    }
    if (guild_level >= 10) {
      skill += (["cast heal":(int) 100]);
      skill += (["cast transfer":(int) 100]);
      skill += (["cast cure":(int) 100]);
      skill += (["cast major":(int) 100]);
      skill += (["cast bless":(int) 65]);
      skill += (["cast soul":(int) 45]);  
      skill += (["cast alignment":(int) 25]);  
    }
    if (guild_level >= 11) {
      skill += (["channel":(int) 80]);
      skill += (["mastery of medicine":(int) 35]);
      skill += (["cast wide":(int) 80]);
    }
    if (guild_level >= 12) {
      skill += (["mastery of medicine":(int) 40]);
      skill += (["cast soul":(int) 55]);  
      skill += (["cast wide":(int) 100]);
      skill += (["cast alignment":(int) 35]);  
    }
    if (guild_level >= 13) {
      skill += (["chanting":(int) 70]);
      skill += (["mastery of medicine":(int) 45]);
    }
    if (guild_level >= 14) {
      skill += (["mastery of medicine":(int) 50]);
      skill += (["cast bless":(int) 70]);
      skill += (["cast holy alteration":(int) 25]);
      skill += (["cast soul":(int) 65]);
      skill += (["cast alignment":(int) 45]);  
    }
    if (guild_level >= 15) {
      skill += (["mastery of medicine":(int) 55]);
    }
    if (guild_level >= 16) {
      skill += (["mastery of medicine":(int) 60]);
      skill += (["cast soul":(int) 75]);
      skill += (["cast holy alteration":(int) 35]);
      skill += (["cast alignment":(int) 65]);  
    }
    if (guild_level >= 17) {
      skill += (["channel":(int) 85]);
      skill += (["mastery of medicine":(int) 65]);
      skill += (["cast bless":(int) 75]);
      skill += (["cast holy alteration":(int) 40]);
    }
    if (guild_level >= 18) {
      skill += (["mastery of medicine":(int) 70]);
    }
    if (guild_level >= 19) {
      skill += (["mastery of medicine":(int) 75]);
      skill += (["cast holy alteration":(int) 50]);
      skill += (["cast alignment":(int) 90]);  
    }
    if (guild_level >= 20) {
      skill += (["cast holy alteration":(int) 60]);
      skill += (["cast bless":(int) 80]);
    }
    if (guild_level >= 21) {
      skill += (["mastery of medicine":(int) 80]);
      skill += (["channel":(int) 90]);
    }
    if (guild_level >= 22) {
      skill += (["cast alignment":(int) 95]);
    }
    if (guild_level >= 23) {
      skill += (["cast holy alteration":(int) 70]);
    }
    if (guild_level >= 24) {
      skill += (["cast holy alteration":(int) 80]);
    }
    if (guild_level >= 25) {
      skill += (["chanting":(int) 100]);
      skill += (["channel":(int) 100]);
      skill += (["cast divine":(int) 100]);
      skill += (["cast heal":(int) 100]);
      skill += (["cast transfer":(int) 100]);
      skill += (["cast major":(int) 100]);
      skill += (["mastery of medicine":(int) 100]);
      skill += (["cast bless":(int) 100]);
      skill += (["cast soul":(int) 100]);
      skill += (["cast holy alteration":(int) 100]);
      skill += (["cast alignment":(int) 100]);  
    }

return skill;
}
