inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("east","/guilds/sorcerer/tower/floor1/basement.c");
  short_desc = "Guild room";
  long_desc = "A spacious chamber. Heroic pictures fill the walls.\n";
}


init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}
guild_name() {
    return "Guardians of the Gods";
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
  return "con 1, dex 1";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["attack": 10]);
      skill += (["smack": 10]);
    }
    if (guild_level >= 2) {
      skill += (["attack": 20]);
      skill += (["bludgeons": 5]);
      skill += (["smack": 20]);
    }
    if (guild_level >= 3) {
      skill += (["attack": 30]);
      skill += (["bludgeons": 10]);
      skill += (["staff handling": 10]);
    }
   if (guild_level >= 4) {
      skill += (["attack": 40]);
      skill += (["bludgeons": 20]);
      skill += (["smack": 30]);
      skill += (["staff handling": 15]);
    }
    if (guild_level >= 5) {
      skill += (["attack": 50]);
      skill += (["bludgeons": 35]);
      skill += (["pound": 5]);
      skill += (["smack": 45]);
      skill += (["staff handling": 25]);
    }
    if (guild_level >= 6) {
      skill += (["attack": 60]);
      skill += (["bludgeons": 45]);
      skill += (["weapon parry": 10]);
      skill += (["pound": 10]);
      skill += (["smack": 60]);
      skill += (["staff handling": 40]);
    }
    if (guild_level >= 7) {
      skill += (["attack": 70]);
      skill += (["bludgeons": 55]);
      skill += (["pound": 50]);
    }
    if(guild_level >= 8) {
      skill += (["bludgeons": 60]);
      skill += (["smack": 75]);
      skill += (["staff handling": 55]);
    }
    if(guild_level >= 9) {
      skill += (["weapon parry": 20]);
      skill += (["pound": 25]);
      skill += (["smack": 90]);
      skill += (["staff handling": 75]);
    }
    if(guild_level >= 10) {
      skill += (["bludgeons": 70]);
      skill += (["weapon parry": 30]);
      skill += (["pound": 50]);
      skill += (["smack": 100]);
      skill += (["staff handling": 100]);
    }
return skill;
}

