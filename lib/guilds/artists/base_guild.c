inherit "guilds/guilds/guild";
inherit "room/room";
object monster;
reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
if(arg) return;

if(!monster)
monster = clone_object("/guilds/artists/rhee.c");
move_object(monster, this_object());


//add_exit("northwest","/guilds/artists/body_focusers.c");
add_exit("northeast","/guilds/artists/mind_focusers.c");
add_exit("up","/guilds/artists/path_of_masters.c");
add_exit("leave","/guilds/artists/entrance.c");
  short_desc = "Martial artists guild room";
  long_desc = "A huge hall where martial artists starts their training progress. There\n"+
      "are many different banners around the room and small fire is emiting light.\n";
    property = allocate(3);
    property[0] = "no_spell";
    property[1] = "no_skill";
    property[2] = "no_kill";
}



init() {
  ::init();
  guild_init();
}

// maxlevel to 50 by C
guild_max_level() {
  return 50;
}
guild_name() {
  return "Martial artist";
}
check_joining_rec() {
return 1;
}
check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}

get_bonuses(level) {
return "dex 2 , con 1 , ";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }


    if (guild_level >= 1) {
      skill += (["attack": 10]);
      skill += (["dragon blow": 5]);
      skill += (["punch": 5]);
      skill += (["bare hands": 15]);
      skill += (["consider": 20]);
    }
    if (guild_level >= 2) {
      skill += (["attack": 15]);
     skill += (["dragon blow": 15]);
    }
    if (guild_level >= 3) {

      skill += (["bare hands": 20]);
      skill += (["punch": 15]);
    }
   if (guild_level >= 4) {
      skill += (["consider": 45]);
     skill += (["dragon blow": 35]);
     skill += (["bare hands": 35]);
     skill += (["attack": 25]);
}
    if (guild_level >= 5) {
      skill += (["bare hands": 45]);
      skill += (["punch": 40]);
     skill += (["dragon blow": 55]);
     skill += (["consider": 75]);
     skill += (["martial arts": 5]);
    }
    if (guild_level >= 6) {
      skill += (["bare hands": 65]);
      skill += (["punch": 55]);
      skill += (["dragon blow": 65]);
     skill += (["critical": 5]);
     skill += (["stun": 5]);
     skill += (["attack": 35]);
}
    if (guild_level >= 7) {
      skill += (["bare hands": 80]);
      skill += (["punch": 70]);
      skill += (["consider": 100]);
     skill += (["dragon blow": 85]);
     skill += (["stun": 15]);
     skill += (["critical": 15]);
     skill += (["martial arts": 25]);
    }
    if (guild_level >= 8) {
      skill += (["attack": 45]);
     skill += (["dragon blow": 75]);
    }
    if (guild_level >= 9) {
     skill += (["dragon blow": 85]);
     skill += (["martial arts": 45]);
    }
    if (guild_level >= 10) {
     skill += (["bare hands": 100]);
     skill += (["punch": 100]);
     skill += (["dragon blow": 100]);
     skill += (["attack": 50]);
    }
   if (guild_level >= 11) {
      skill += (["attack": 80]);
    }
    if (guild_level >= 12) {
      skill += (["attack": 100]);
      skill += (["critical": 40]);
    }
    if (guild_level >= 13) {
      skill += (["doublehit": 10]);
}
    if (guild_level >= 14) {
      skill += (["critical": 50]);
      skill += (["doublehit": 20]);
    }
    if (guild_level >= 15) {
      skill += (["critical": 60]);
      skill += (["doublehit": 40]);
      skill += (["find weakness": 15]);
    }

    if (guild_level >= 16) {
      skill += (["martial arts": 55]);
      skill += (["torch creation": 25]);
      skill += (["stun": 25]);

    }
      if (guild_level >= 17) {
      skill += (["torch creation": 40]);
    }
    if (guild_level >= 18) {
      skill += (["martial arts": 65]);
    }
    if (guild_level >= 19) {
      skill += (["stun": 45]);
      skill += (["torch creation": 60]);
    }
    if (guild_level >= 20) {
}
    if (guild_level >= 21) {
      skill += (["martial arts": 70]);
      skill += (["stun": 55]);
      skill += (["torch creation": 100]);
    }
    if (guild_level >= 22) {
      skill += (["two weapons combat": 15]);
      skill += (["claws storm": 10]);
      skill += (["whirlwind": 10]);
      skill += (["advanced martial arts": 5]);
    }
    if (guild_level >= 23) {
      skill += (["two weapons combat": 25]);
      skill += (["claws storm": 15]);
    }
    if (guild_level >= 24) {
      skill += (["whirlwind": 15]);
      skill += (["advanced martial arts": 15]);
    }
  if (guild_level >= 25) {
      skill += (["claws storm": 25]);
    }
    if (guild_level >= 26) {
      skill += (["two weapons combat": 35]);
    }
    if (guild_level >= 27) {
      skill += (["claws storm": 35]);
      skill += (["whirlwind": 35]);
    }
    if (guild_level >= 28) {
      skill += (["two weapons combat": 45]);
}
    if (guild_level >= 29) {
      skill += (["advanced martial arts": 25]);
      skill += (["claws storm": 45]);
      skill += (["whirlwind": 45]);
    }
    if (guild_level >= 30) {
      skill += (["claws storm": 55]);
      skill += (["whirlwind": 55]);
      skill += (["advanced martial arts": 30]);
      skill += (["two weapons combat": 55]);
    }
// maxlevelcode by C
  guild_level -= 5;


    if (guild_level >= 31) {
      skill += (["critical": 70]);
      skill += (["doublehit": 50]);
      skill += (["inner strength": 5]);
    }
    if (guild_level >= 32) {
      skill += (["stun": 60]);
      skill += (["martial arts": 80]);
    }
  if (guild_level >= 33) {
      skill += (["two weapons combat": 65]);
      skill += (["inner strength": 25]);
    }
    if (guild_level >= 34) {
      skill += (["claws storm": 65]);
      skill += (["whirlwind": 65]);
    }
    if (guild_level >= 35) {
      skill += (["claws storm": 75]);
      skill += (["whirlwind": 75]);
      skill += (["inner strength": 30]);
      skill += (["two weapons combat": 75]);
    }
    if (guild_level >= 36) {
      skill += (["martial arts": 100]);
}
    if (guild_level >= 37) {
      skill += (["advanced martial arts": 60]);
      skill += (["two weapons combat": 85]);

    }
    if (guild_level >= 38) {
      skill += (["advanced martial arts": 80]);
      skill += (["doublehit": 65]);
    }
    if (guild_level >= 39) {
    }
     if (guild_level >= 40) {
      skill += (["shadow blow": 10]);
    }
   if (guild_level >= 41) {
      skill += (["advanced martial arts": 100]);
      skill += (["doublehit": 75]);
      skill += (["inner strength": 45]);
      skill += (["stun": 75]);
    }
    if (guild_level >= 42) {
      skill += (["two weapons combat": 95]);
    skill+= (["shadow blow": 30]);
}
    if (guild_level >= 43) {
      skill += (["critical": 80]);
      skill += (["doublehit": 80]);

    }
    if (guild_level >= 44) {
    skill += (["shadow blow": 40]);
}
    if (guild_level >= 45) {
      skill += (["doublehit": 100]);
      skill += (["critical": 100]);
      skill += (["two weapons combat": 100]);
   skill += (["shadow blow": 65]);

}
return skill;
}

