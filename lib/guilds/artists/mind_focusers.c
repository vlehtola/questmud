inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("southwest","/guilds/artists/base_guild.c");
  short_desc = "The mind focusers";
  long_desc = "This is the place where martial artist starts focusing\n"
      "mind and body for the harder part of becoming a master.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}
guild_name() {
    return "mind focusers";
}

check_joining_rec() {
  if(this_player()->query_guild_level("martial artist") < 45) {
    write("You must first complete the guild of martial artists.\n");
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
  return "str 3 , dex 1 , con 1 , ";

}



skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["claws storm": 85]);
    }
    if (guild_level >= 2) {
      skill += (["whirlwind": 85]);
    }
    if (guild_level >= 3) {
      skill += (["claws storm": 95]);
    }
    if (guild_level >= 4) {
      skill += (["whirlwind": 95]);
    }
     if (guild_level >= 5) {
      skill += (["hiking": 30]);
      skill += (["whirlwind": 100]);
      skill += (["claws storm": 100]);
    }
    if (guild_level >= 6) {
      skill += (["meditation": 20]);
      skill += (["mastery of meditation": 10]);
    }
    if (guild_level >= 7) {
      skill += (["seal wounds": 15]);
      skill += (["inner strength": 40]);
      skill += (["hiking": 60]);
    }
    if (guild_level >= 8) {
      skill += (["meditation": 40]);
}
    if (guild_level >= 9) {
      skill += (["mastery of meditation": 25]);

      }
    if (guild_level >= 10) {
      skill += (["seal wounds": 45]);
      skill += (["stun": 85]);
    }
    if (guild_level >= 11) {
      skill += (["meditation": 70]);
      skill += (["mastery of meditation": 45]);
    }
    if (guild_level >= 12) {
      skill += (["stun": 100]);
      skill += (["inner strength": 55]);
    }
    if (guild_level >= 13) {
      skill += (["seal wounds": 75]);
      skill += (["mastery of meditation": 65]);

    }
    if (guild_level >= 14) {
      skill += (["meditation": 85]);
}
    if (guild_level >= 15) {
      skill += (["hiking": 100]);
      skill += (["mastery of meditation": 100]);
      skill += (["seal wounds": 100]);
      skill += (["meditation": 100]);
      skill += (["inner strength": 65]);
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

