inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("down","/guilds/fighter/fighter");
  short_desc = "The Weaponmasters Guild";
  long_desc = "As this room is on the top of the base fighter guild,\n"+
              "so are it's fighting techniques on top of what is teached\n"+
              "down there. This is the weaponmaster's training area.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Weaponmaster";
}

check_joining_rec() {
    int i;
    if (this_player()->query_guild_level("Bludgeonists") == "/guilds/fighter/bludgeons"->guild_max_level()) {
        i += 1;
    }
    if (this_player()->query_guild_level("Axers") == "/guilds/fighter/axes"->guild_max_level()) {
        i += 1;
    }
    if (this_player()->query_guild_level("Blademasters") == "/guilds/fighter/blades"->guild_max_level()) {
        i += 1;
    }
    if (i < 2) {
      write("You must complete atleast 2 weapon specialist guilds.\n");
      return 0;
    }
    if(this_player()->query_guild_level("Warriors") < 5) {
      write("You must first complete the Warrior guild.\n");
      return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([4:"weapon parry:30;"]);
  sk += ([10:"doublehit:40;"]);
  return sk;
}

get_bonuses(level) {
  return " str 1 , dex 1 , ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
      skill += (["weapon parry":(int) 20]);
      if(this_player()->query_guild_level("Bludgeonists") == "/guilds/fighter/bludgeons"->guild_max_level())
        skill += (["pound":(int) 100]);
      if(this_player()->query_guild_level("Axers") == "/guilds/fighter/axes"->guild_max_level())
        skill += (["cut":(int) 100]);
      if(this_player()->query_guild_level("Blademasters") == "/guilds/fighter/blades"->guild_max_level())
        skill += (["slash":(int) 100]);
    }
    if (guild_level >= 2) {
      skill += (["weapon parry":(int) 30]);
      skill += (["critical":(int) 70]);
      skill += (["disarm":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["weapon parry":(int) 40]);
      skill += (["disarm":(int) 40]);
    }
    if (guild_level >= 4) {
      skill += (["weapon parry":(int) 60]);
      skill += (["critical":(int) 80]);
      skill += (["disarm":(int) 60]);
    }
    if (guild_level >= 5) {
      skill += (["weapon parry":(int) 70]);
      skill += (["doublehit":(int) 20]);
      skill += (["disarm":(int) 80]);
    }
    if (guild_level >= 6) {
      skill += (["find weakness":(int) 20]);
      skill += (["doublehit":(int) 20]);
      skill += (["double strike":(int) 20]);
    }
    if (guild_level >= 7) {
      skill += (["weapon parry":(int) 80]);
      skill += (["doublehit":(int) 30]);
      skill += (["double strike":(int) 30]);
    }
    if (guild_level >= 8) {
      skill += (["doublehit":(int) 40]);
      skill += (["find weakness":(int) 25]);
      skill += (["double strike":(int) 40]);
      skill += (["disarm":(int) 100]);
    }
    if (guild_level >= 9) {
      skill += (["weapon parry":(int) 100]);
      skill += (["doublehit":(int) 60]);
      skill += (["double strike":(int) 50]);
    }
    if (guild_level >= 10) {
      skill += (["critical":(int) 100]);
      skill += (["find weakness":(int) 30]);
      skill += (["doublehit":(int) 100]);
      skill += (["double strike":(int) 100]);
    }
  return skill;
}

