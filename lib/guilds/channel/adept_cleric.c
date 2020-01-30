inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
     load_plaque();
     if (arg) { return; }
     set_not_out(1);
     set_light(3);
  short_desc = "The guild room of Adept Clerics";
  long_desc =
"A room full of holy candles. The marble walls glow warmth and\n"+
"there is a painting on the western wall. This is where the adept\n"+
"Clerics of Cyral get their tuition.\n";

items = allocate(4);
items[0] = "candles";
items[1] = "White candles burning brightly, lighting the whole room";
items[2] = "painting";
items[3] = "A holy painting representing Cyral";

  add_exit("east", "/guilds/channel/r12");
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 25;
}

guild_name() {
    return "Adept clerics";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Apprentice clerics") < 20) {
        write("Must have completed the Apprentice Clerics first.\n");
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
      skill += (["chanting":(int) 35]);
      skill += (["channel":(int) 50]);
      skill += (["cast divine":(int) 60]);
      skill += (["cast lesser":(int) 10]);
      skill += (["cast transfer":(int) 50]);
      skill += (["cast heal":(int) 50]);
      skill += (["cast cure":(int) 25]);
      skill += (["cast bless":(int) 25]);
    }

    if (guild_level >= 2) {
      skill += (["cast cure":(int) 30]);
      skill += (["cast lesser":(int) 20]);
      skill += (["cast satisfy":(int) 30]);
    }
    if (guild_level >= 3) {
      skill += (["cast heal":(int) 55]);
      skill += (["cast lesser":(int) 25]);
      skill += (["cast satisfy":(int) 60]);
    }
    if (guild_level >= 4) {
      skill += (["cast transfer":(int) 55]);
      skill += (["cast bless":(int) 30]);
      skill += (["cast satisfy":(int) 100]);
    }
    if (guild_level >= 5) {
      skill += (["chanting":(int) 40]);
      skill += (["channel":(int) 55]);
      skill += (["cast lesser":(int) 30]);
    }
    if (guild_level >= 6) {
      skill += (["cast divine":(int) 65]);
      skill += (["cast lesser":(int) 35]);
    }
    if (guild_level >= 7) {
      skill += (["cast heal":(int) 60]);
      skill += (["cast lesser":(int) 40]);
    }
    if (guild_level >= 8) {
      skill += (["cast transfer":(int) 60]);
      skill += (["cast lesser":(int) 45]);
    }
    if (guild_level >= 9) {
      skill += (["channel":(int) 60]);
      skill += (["cast lesser":(int) 50]);
      skill += (["cast bless":(int) 35]);
    }
    if (guild_level >= 10) {
      skill += (["chanting":(int) 45]);
      skill += (["cast divine":(int) 70]);
      skill += (["cast lesser":(int) 55]);
      skill += (["cast soul":(int) 10]);
      skill += (["cast gender":(int) 20]);
    }
    if (guild_level >= 11) {
      skill += (["cast cure":(int) 35]);
      skill += (["cast lesser":(int) 60]);
    }
    if (guild_level >= 12) {
      skill += (["cast heal":(int) 65]);
      skill += (["cast bless":(int) 40]);
      skill += (["cast soul":(int) 15]);
    }
    if (guild_level >= 13) {
      skill += (["cast transfer":(int) 65]);
      skill += (["cast lesser":(int) 65]);
    }
    if (guild_level >= 14) {
      skill += (["chanting":(int) 50]);
      skill += (["cast divine":(int) 75]);
      skill += (["cast soul":(int) 20]);
    }
    if (guild_level >= 15) {
      skill += (["channel":(int) 65]);
      skill += (["cast lesser":(int) 70]);
      skill += (["cast gender":(int) 50]);
    }
    if (guild_level >= 16) {
      skill += (["cast bless":(int) 45]);
    }
    if (guild_level >= 17) {
      skill += (["cast lesser":(int) 75]);
      skill += (["cast soul":(int) 25]);
    }
    if (guild_level >= 18) {
      skill += (["chanting":(int) 55]);
      skill += (["cast divine":(int) 80]);
    }
    if (guild_level >= 19) {
      skill += (["cast lesser":(int) 80]);
    }
    if (guild_level >= 20) {
      skill += (["mental unity":(int) 10]);
      skill += (["cast gender":(int) 75]);
    }
    if (guild_level >= 21) {
      skill += (["mental unity":(int) 25]);
    }
    if (guild_level >= 22) {
      skill += (["mental unity":(int) 35]);
    }
    if (guild_level >= 23) {
      skill += (["mental unity":(int) 50]);
    }
    if (guild_level >= 24) {
      skill += (["mental unity":(int) 75]);
    }
    if (guild_level >= 25) {
      skill += (["chanting":(int) 60]);
      skill += (["channel":(int) 70]);
      skill += (["cast divine":(int) 80]);
      skill += (["cast heal":(int) 80]);
      skill += (["cast transfer":(int) 80]);
      skill += (["cast cure":(int) 40]);
      skill += (["cast lesser":(int) 100]);
      skill += (["cast bless":(int) 50]);
      skill += (["cast soul":(int) 30]);
      skill += (["mental unity":(int) 100]);
      skill += (["cast gender":(int) 100]);
    }

return skill;
}
