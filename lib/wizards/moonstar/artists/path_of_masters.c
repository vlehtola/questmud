
inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("down","/guilds/artists/base_guild.c");
  short_desc = "The Path of Masters";
  long_desc = "Huge hall where masters trains final secrets of martial arts.\n"
"Floor is made of marmor and the room is filled with different kind\n"
"of plants and trees. There is a statue of Grand Master Rhee Ki Haa who\n"
"is teacher of all martial artists.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}
guild_name() {
    return "Path of Masters";
}

check_joining_rec() {
  if(this_player()->query_guild_level("body focusers") < 20) {
    write("You must first complete the guild of body focusers.\n");
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
  return "str 1 , dex 2 , con 2, ";

}
skill_list(int guild_level) {
    mapping skill;

    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["sky strike": 80]);
    }
    if (guild_level >= 2) {
      skill += (["body anatomy": 15]);
 skill += (["find weakness": 25]);
    }
    if (guild_level >= 3) {
      skill += (["focused sky strike": 65]);
      skill += (["focused shadow blow": 85]);
    }
   if (guild_level >= 4) {
      skill += (["enhance criticals": 15]);
 skill += (["deceived attack": 10]);
    }
    if (guild_level >= 5) {
      skill += (["first strike": 15]);
    }
    if (guild_level >= 6) {
      skill += (["sky strike": 85]);
    }
    if (guild_level >= 7) {
      skill += (["body anatomy": 25]);
    }
    if (guild_level >= 8) {
      skill += (["enhance criticals": 25]);
      skill += (["endurance": 25]);
}
     if (guild_level >= 9) {
      skill += (["focused sky strike": 75]);
      skill += (["focused shadow blow": 95]);
      skill += (["find weakness": 35]);

       }
    if (guild_level >= 10) {
      skill += (["first strike": 25]);
      skill += (["enhance criticals": 35]);
      skill += (["sky strike": 100]);
      skill += (["body anatomy": 45]);
      skill += (["deceived attack": 25]);
    }
    if (guild_level >= 11) {
      skill += (["find weakness": 45]);
      skill += (["focused sky strike": 85]);
    }
    if (guild_level >= 12) {
      skill += (["focused shadow blow": 100]);
      skill += (["body anatomy": 55]);
    }
      if (guild_level >= 13) {
      skill += (["first strike": 35]);
      skill += (["enhance criticals": 45]);
    }
    if (guild_level >= 14) {
      skill += (["focused sky strike": 95]);
      skill += (["endurance": 35]);
}
    if (guild_level >= 15) {
      skill += (["focused sky strike": 100]);
      skill += (["body anatomy": 65]);
      }
    if (guild_level >= 16) {
      skill += (["enhance criticals": 55]);
    }
    if (guild_level >= 17) {
      skill += (["first strike": 45]);
      skill += (["find weakness": 50]);
    }
    if (guild_level >= 18) {
      skill += (["body anatomy": 75]);
      skill += (["deceived attack": 45]);
    }
    if (guild_level >= 19) {
      skill += (["body anatomy": 85]);
      skill += (["find weakness": 60]);

}
     if (guild_level >= 20) {
      skill += (["endurance": 50]);
      skill += (["body anatomy": 100]);
      skill += (["deceived attack": 60]);
      skill += (["first strike": 60]);
      skill += (["find weakness": 70]);
      skill += (["enhance criticals": 65]);

}
return skill;
}

