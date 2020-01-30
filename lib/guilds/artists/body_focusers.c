inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("southeast","/guilds/artists/base_guild.c");
  short_desc = "The body focusers";
  long_desc = "This is the place where martial artist trains\n"+
      "focusing elements and starts training the secrets of finishing blows.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}
guild_name() {
    return "Body focusers";
}

check_joining_rec() {
  if(this_player()->query_guild_level("mind focusers") < 15) {
    write("You must first complete the guild of mind focusers.\n");
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
  return "str 2 , dex 1 , con 2 , ";

}
skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["focus elements": 45]);
    }
    if (guild_level >= 2) {
      skill += (["power of fire": 35]);
 skill += (["power of ice": 35]);
 skill += (["power of thunder": 35]);
    }
    if (guild_level >= 3) {
      skill += (["focus elements": 55]);
      skill += (["power of fire": 45]);
 skill += (["power of ice": 45]);
 skill += (["power of thunder": 45]);
    }
     if (guild_level >= 4) {
      skill += (["power of fire": 55]);
 skill += (["power of ice": 55]);
    }
    if (guild_level >= 5) {
      skill += (["focus elements": 65]);
      skill += (["power of thunder": 55]);
    }
    if (guild_level >= 6) {
      skill += (["focus elements": 70]);
    }
    if (guild_level >= 7) {
      skill += (["power of fire": 60]);
    }
    if (guild_level >= 8) {
      skill += (["power of ice": 60]);
}
    if (guild_level >= 9) {
      skill += (["power of thunder": 60]);
       }
    if (guild_level >= 10) {
      skill += (["focus elements": 80]);
      skill += (["power of fire": 70]);
    }
    if (guild_level >= 11) {
      skill += (["power of thunder": 70]);
      skill += (["power of ice": 70]);
    }
    if (guild_level >= 12) {
      skill += (["focus elements": 100]);
      skill += (["power of ice": 85]);
    }
    if (guild_level >= 13) {
      skill += (["power of fire": 85]);
      skill += (["power of thunder": 85]);
    }
    if (guild_level >= 14) {
      skill += (["power of fire": 100]);
 skill += (["power of thunder": 100]);
skill += (["power of ice": 100]);
}
    if (guild_level >= 15) {
      skill += (["sky strike": 20]);
      skill += (["focused sky strike": 15]);
      skill += (["focused shadow blow": 25]);
      skill += (["shadow blow": 85]);
      }
    if (guild_level >= 16) {
      skill += (["sky strike": 35]);
      skill += (["focused shadow blow": 40]);
    }
    if (guild_level >= 17) {
      skill += (["sky strike": 45]);
      skill += (["focused sky strike": 30]);
    }
    if (guild_level >= 18) {
      skill += (["shadow blow": 100]);
      skill += (["focused shadow blow": 55]);
    }
    if (guild_level >= 19) {
      skill += (["sky strike": 55]);
      skill += (["focused sky strike": 40]);
}
    if (guild_level >= 20) {
      skill += (["sky strike": 70]);
      skill += (["focused sky strike": 55]);
      skill += (["focused shadow blow": 75]);
}
return skill;
}

