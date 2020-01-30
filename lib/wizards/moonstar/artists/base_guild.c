inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
add_exit("northwest","/wizards/moonstar/artists/body_focusers.c");
add_exit("northeast","/wizards/moonstar/artists/mind_focusers.c");
add_exit("up","/wizards/moonstar/artists/path_of_masters.c");
  add_exit("leave","/wizards/moonstar/workroom.c");
  short_desc = "Martial artists guild room";
  long_desc = "A huge hall where martial artists starts their training progress.\n"+
      "There are many different banners around the room and small fire is emiting light.\n";
}



init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 45;
}
guild_name() {
    return "Martial artists";
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
 return "dex 3 , con 2 , ";
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
     skill += (["dodge": 5]);
     skill += (["parry": 5]);
     skill += (["dragon blow": 55]);
     skill += (["consider": 75]);
     skill += (["blades": 5]);
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
     skill += (["blades": 25]);
    }
    if (guild_level >= 8) {
      skill += (["attack": 45]);
      skill += (["dodge": 15]);
     skill += (["parry": 15]);
     skill += (["dragon blow": 75]);
    }
    if (guild_level >= 9) {
     skill += (["dragon blow": 85]);     
     skill += (["blades": 45]);
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
      skill += (["dodge": 25]);
      skill += (["parry": 25]);
      skill += (["blades": 55]);
      skill += (["torch creation": 25]);
      skill += (["stun": 25]); 

    }  
      if (guild_level >= 17) {
      skill += (["torch creation": 40]);
      skill += (["parry": 35]);
    }
    if (guild_level >= 18) {
      skill += (["blades": 65]);
      skill += (["dodge": 35]);
    }
    if (guild_level >= 19) {
      skill += (["stun": 45]);
      skill += (["torch creation": 60]);
    }
    if (guild_level >= 20) {
      skill += (["parry": 50]);
      skill += (["dodge": 50]);
}
    if (guild_level >= 21) {
      skill += (["blades": 70]);
      skill += (["stun": 55]);
      skill += (["torch creation": 100]);
    }
    if (guild_level >= 22) {
      skill += (["two weapons combat": 15]);
      skill += (["claws storm": 10]);
      skill += (["whirlwind": 10]);
      skill += (["slash": 5]);
    }
    if (guild_level >= 23) {
      skill += (["two weapons combat": 25]);
      skill += (["claws storm": 15]);
    }
    if (guild_level >= 24) {
      skill += (["whirlwind": 15]);
      skill += (["slash": 15]);
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
      skill += (["slash": 25]);
      skill += (["claws storm": 45]);
      skill += (["whirlwind": 45]);
    }
    if (guild_level >= 30) {
      skill += (["claws storm": 55]);
      skill += (["whirlwind": 55]);
      skill += (["slash": 30]);
      skill += (["two weapons combat": 55]);
    }
    if (guild_level >= 31) {
      skill += (["critical": 70]);
      skill += (["doublehit": 50]);
      skill += (["inner strength": 5]);
    }
    if (guild_level >= 32) {
      skill += (["stun": 60]);
      skill += (["blades": 80]);
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
      skill += (["blades": 100]);
}
    if (guild_level >= 37) {
      skill += (["slash": 60]);
      skill += (["two weapons combat": 85]);

    }
    if (guild_level >= 38) {
      skill += (["slash": 80]);
      skill += (["doublehit": 65]);
      skill += (["focus elements": 15]);
    }
    if (guild_level >= 39) {
      skill += (["power of ice": 10]);
      skill += (["power of fire": 10]);
      skill += (["power of thunder": 10]);
    }
    if (guild_level >= 40) {
      skill += (["shadow blow": 10]);
      skill += (["focus elements": 30]);

    }
   if (guild_level >= 41) {
      skill += (["slash": 100]);
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
      skill += (["focus elements": 40]);
      skill += (["power of ice": 25]);
      skill += (["power of fire": 25]);
    skill += (["shadow blow": 40]);
}
    if (guild_level >= 45) {
      skill += (["power of thunder": 25]);
      skill += (["doublehit": 100]);
      skill += (["critical": 100]);
      skill += (["two weapons combat": 100]);
   skill += (["shadow blow": 65]);
}
return skill;
}
