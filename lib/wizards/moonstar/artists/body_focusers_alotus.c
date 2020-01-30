inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("southeast","/wizards/moonstar/artists/base_guild.c");
  short_desc = "The body focusers subguild";
  long_desc = "This is the place where martial artist starts focusing"
      "his body and starts training the secrets of finishing blows.\n";
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
  return "str 2 , dex 1 , con 2, ";

}


skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["claws storm": 85]);
 skill += (["claws storm": 85]);
    }
    if (guild_level >= 2) {
      skill += (["whirlwind": 85]);
 skill += (["claws storm": 85]);
 skill += (["claws storm": 85]);
    }
    if (guild_level >= 3) {
      skill += (["claws storm": 95]);
 skill += (["claws storm": 85]);
    }
    if (guild_level >= 4) {
      skill += (["whirlwind": 95]);
 skill += (["claws storm": 85]);
    }
    if (guild_level >= 5) {
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

    }
    if (guild_level >= 8) {
      skill += (["meditation": 40]);
 skill += (["claws storm": 85]);
}
    if (guild_level >= 9) {
      skill += (["mastery of meditation": 25]);
 skill += (["claws storm": 85]);
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
 skill += (["claws storm": 85]);
}
    if (guild_level >= 15) {
      skill += (["mastery of meditation": 100]);
      skill += (["seal wounds": 100]);
      skill += (["meditation": 100]);
      skill += (["inner strength": 65]);
      }
    if (guild_level >= 16) {
      skill += (["seal wounds": 45]);
      skill += (["stun": 85]);
    }
    if (guild_level >= 17) {
      skill += (["meditation": 70]);
      skill += (["mastery of meditation": 45]);
    }
    if (guild_level >= 18) {
      skill += (["stun": 100]);
      skill += (["inner strength": 55]);
    }
    if (guild_level >= 19) {
      skill += (["seal wounds": 75]);
      skill += (["mastery of meditation": 65]);
}
    if (guild_level >= 20) {
      skill += (["mastery of meditation": 100]);
      skill += (["seal wounds": 100]);
      skill += (["meditation": 100]);
      skill += (["inner strength": 65]);
}
return skill;
}
