inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("down","/guilds/sorcerer/tower/floor3/room6.c");
  short_desc = "Guild room";
  long_desc = "A spacious chamber. A tall pillar stands in the center of the room.\n";
}


init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}
guild_name() {
    return "Soul Enchanters";
}

check_joining_rec() {
  if(this_player()->query_guild_level("Sorcerers of the Will") < 15) {
    write("You must first complete the guild 'Sorcerers of the Will'\n");
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
  return "int 3";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast soul chaining": 10]);
      skill += (["will change": 20]);
    }
    if (guild_level >= 2) {
      skill += (["cast soul chaining": 15]);
      skill += (["shield of will": 20]);
      skill += (["gods aura": 10]);
      skill += (["will change": 35]);
    }
    if (guild_level >= 3) {
      skill += (["shield of will": 30]);
      skill += (["gods aura": 35]);
      skill += (["will change": 40]);
    }
   if (guild_level >= 4) {
      skill += (["shield of will": 45]);
      skill += (["gods aura": 50]);
      skill += (["will change": 45]);
    }
    if (guild_level >= 5) {
      skill += (["cast soul chaining": 40]);
      skill += (["shield of will": 55]);
      skill += (["gods aura": 65]);
      skill += (["will change": 60]);
      skill += (["soul curse": 5]);
    }
    if (guild_level >= 6) {
      skill += (["cast soul chaining": 60]);
      skill += (["shield of will": 70]);
      skill += (["soul curse": 20]);
    }
    if (guild_level >= 7) {
      skill += (["shield of will": 80]);
      skill += (["gods aura": 80]);
      skill += (["will change": 70]);
      skill += (["soul curse": 40]);
    }
    if(guild_level >= 8) {
      skill += (["cast soul chaining": 80]);
      skill += (["shield of will": 85]);
      skill += (["gods aura": 85]);
      skill += (["soul curse": 60]);
    }
    if(guild_level >= 9) {
      skill += (["cast soul chaining": 100]);
      skill += (["gods aura": 100]);
      skill += (["will change": 85]);
      skill += (["soul curse": 80]);
    }
    if(guild_level >= 10) {
      skill += (["cast soul chaining": 100]);
      skill += (["shield of will": 100]);
      skill += (["gods aura": 100]);
      skill += (["will change": 100]);
      skill += (["soul curse": 100]);
    }
return skill;
}

