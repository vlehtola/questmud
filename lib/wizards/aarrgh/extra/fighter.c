inherit "world/guilds/guild";
inherit "room/room";

reset(arg) {
  object plaque;
  if (!present("plaque")) {
    plaque = clone_object("world/guilds/plaque.c");
    move_object(plaque, this_object());
  }
  if(arg) return;
  move_object(clone_object("/world/monsters/fightermaster"),this_object());
  add_exit("east","/world/city/gold3");
  add_exit("north","/world/fighter/defender");
  add_exit("west","/world/fighter/bludgeon");
  add_exit("south","/world/fighter/special");
  add_exit("up","/world/fighter/weapon_master");
  short_desc = "The Fighters Guild";
  long_desc = "The famous Fighters Guild of Duranghom: training center.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_long_name() {
    return guild_name();
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
  sk += ([2:"bare hands:10;"]);
  sk += ([10:"attack:30;"]);
  return sk;
}

get_bonuses(level) {
    if (level == 0) { return "str 2 , con 2 , "; }
    if (level == 1) { return "str 2 , con 1 , dex 2 , "; }
    if (level == 2) { return "con 5 , "; }
    if (level == 3) { return "str 5 , "; }
    if (level == 4) { return "str 1 , dex 3 , epregen 2 , "; }
    if (level == 5) { return "con 5 , hpregen 2 , "; }
    if (level == 6) { return "str 2 , con 1 , epregen 3 , "; }
    if (level == 7) { return "str 2 , dex 2 , "; }
    if (level == 8) { return "str 2 , con 2 , hpregen 1 , "; }
    if (level == 9) { return "str 4 , dex 10 , con 3 , epregen 2 , "; }
}

get_skill_max(num, how, lvl) {
    mapping skill;
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(call_other("/world/guilds/guildfun", "get_guild_number", guild_name()));
    skill = ([ ]);

    if (lvl) {
         guild_level = lvl;
         if (guild_level > 10) { guild_level = 10; }
    }
    if (!guild_level) {
        write("Bugged.. not a member\n");
        return 0;
    }
    if (guild_level >= 1) {
      skill += (["attack":(int) 10]);
      skill += (["bludgeons":(int) 10]);
      skill += (["bare hands":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["attack":(int) 10]);
      skill += (["bludgeons":(int) 30]);
      skill += (["bare hands":(int) 40]);
    }
    if (guild_level >= 3) {
      skill += (["attack":(int) 30]);
      skill += (["bludgeons":(int) 40]);
      skill += (["bare hands":(int) 60]);
      skill += (["kick":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["attack":(int) 30]);
      skill += (["bludgeons":(int) 50]);
      skill += (["bare hands":(int) 80]);
      skill += (["kick":(int) 40]);
      skill += (["dodge":(int) 20]);
      skill += (["blades":(int) 10]);
    }
    if (guild_level >= 5) {
      skill += (["attack":(int) 40]);
      skill += (["bludgeons":(int) 50]);
      skill += (["bare hands":(int) 100]);
      skill += (["kick":(int) 50]);
      skill += (["dodge":(int) 30]);
      skill += (["blades":(int) 30]);
      skill += (["parry":(int) 10]);
    }
    if (guild_level >= 6) {
      skill += (["attack":(int) 50]);
      skill += (["bludgeons":(int) 60]);
      skill += (["kick":(int) 60]);
      skill += (["dodge":(int) 30]);
      skill += (["blades":(int) 30]);
      skill += (["parry":(int) 20]);
      skill += (["critical":(int) 10]);
    }
    if (guild_level >= 7) {
      skill += (["attack":(int) 50]);
      skill += (["bludgeons":(int) 60]);
      skill += (["kick":(int) 60]);
      skill += (["dodge":(int) 30]);
      skill += (["blades":(int) 30]);
      skill += (["parry":(int) 20]);
    }
    if (guild_level >= 8) {
      skill += (["attack":(int) 60]);
      skill += (["bludgeons":(int) 60]);
      skill += (["kick":(int) 70]);
      skill += (["dodge":(int) 30]);
      skill += (["blades":(int) 30]);
      skill += (["parry":(int) 20]);
      skill += (["stun":(int) 10]);
      skill += (["axes":(int) 20]);
    }
    if (guild_level >= 9) {
      skill += (["kick":(int) 80]);
      skill += (["blades":(int) 40]);
      skill += (["parry":(int) 20]);
      skill += (["stun":(int) 15]);
      skill += (["critical":(int) 20]);
    }
    if (guild_level >= 10) {
      skill += (["kick":(int) 100]);
      skill += (["blades":(int) 40]);
      skill += (["parry":(int) 30]);
      skill += (["stun":(int) 25]);
      skill += (["axes":(int) 40]);
      skill += (["critical":(int) 35]);
    }
    skill_num = m_indices(skill);
    skill_max = m_values(skill);
    if (how == 0) {
        while (i < sizeof(skill_max)) {
            if (skill_num[i] == num) {
                return skill_max[i];
            }
            i += 1;
        }  
    }
    if (how == 1) {
        return skill_max[num];
    }
    if (how == 2 || how == 3) {
        return skill_num[num];
    }
    if (how == 4) {
        return skill_max;
    }
}

