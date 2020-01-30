inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  move_object(clone_object("/guilds/fighter/fightermaster"),this_object());
  add_exit("east","/world/city/gold3");
  add_exit("north","/guilds/fighter/defender");
  add_exit("west","/guilds/fighter/bludgeons");
  add_exit("south","/guilds/fighter/warrior");
  add_exit("up","/guilds/fighter/weapon_master");
  short_desc = "The Fighters Guild";
  long_desc = "This building is the famous Fighter guild of Duranghom, the place where\n"+
"all adventurers who seek hand-to-hand combat training, come. The streets\n"+
"of Duranghom lie to the east.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Fighters";
}

check_joining_rec() {
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([3:"bare hands:15;"]);
  sk += ([9:"attack:20;"]);
  return sk;
}

get_bonuses(level) {
  return "str 1 , con 1 , ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
      skill += (["consider":(int) 30]);
      skill += (["attack":(int) 10]);
      skill += (["bare hands":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["consider":(int) 60]);
      skill += (["attack":(int) 10]);
      skill += (["bare hands":(int) 40]);
    }
    if (guild_level >= 3) {
      skill += (["consider":(int) 80]);
      skill += (["attack":(int) 30]);
      skill += (["bare hands":(int) 60]);
      skill += (["kick":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["consider":(int) 100]);
      skill += (["attack":(int) 30]);
      skill += (["bare hands":(int) 80]);
      skill += (["kick":(int) 40]);
      skill += (["dodge":(int) 10]);
      skill += (["punch":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["attack":(int) 40]);
      skill += (["bare hands":(int) 100]);
      skill += (["kick":(int) 50]);
      skill += (["dodge":(int) 20]);
      skill += (["punch":(int) 40]);
    }
    if (guild_level >= 6) {
      skill += (["attack":(int) 50]);
      skill += (["kick":(int) 60]);
      skill += (["blades":(int) 10]);
      skill += (["axes":(int) 10]);
      skill += (["bludgeons":(int) 10]);
      skill += (["punch":(int) 60]);
    }
    if (guild_level >= 7) {
      skill += (["attack":(int) 50]);
      skill += (["kick":(int) 60]);
      skill += (["parry":(int) 10]);
      skill += (["punch":(int) 70]);
      skill += (["blades":(int) 20]);
      skill += (["axes":(int) 20]);
      skill += (["bludgeons":(int) 20]);
      skill += (["critical":(int) 10]);
    }
    if (guild_level >= 8) {
      skill += (["attack":(int) 60]);
      skill += (["kick":(int) 70]);
      skill += (["dodge":(int) 30]);
      skill += (["punch":(int) 80]);
      skill += (["blades":(int) 30]);
      skill += (["axes":(int) 30]);
      skill += (["bludgeons":(int) 30]);
    }
    if (guild_level >= 9) {
      skill += (["kick":(int) 80]);
      skill += (["parry":(int) 20]);
      skill += (["stun":(int) 10]);
      skill += (["critical":(int) 20]);
      skill += (["punch":(int) 90]);
      skill += (["attack":(int) 70]);
    }
    if (guild_level >= 10) {
      skill += (["kick":(int) 100]);
      skill += (["parry":(int) 30]);
      skill += (["stun":(int) 20]);
      skill += (["critical":(int) 30]);
      skill += (["punch":(int) 100]);
      skill += (["blades":(int) 40]);
      skill += (["axes":(int) 40]);
      skill += (["bludgeons":(int) 40]);
    }

  return skill;
}

