inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("south", "/guilds/mage/illusionists");
  short_desc = "The school of Poisons";
  long_desc = "The school of Poisons.\nStudents here learn to use efficiency poisons.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 7;
}

guild_name() {
    return "poison school";
}

check_joining_rec() {
  if (this_player()->query_guild_level("apprentice mages") != 20 &&
      this_player()->query_guild_level("abjurers") < 10) {
    write("Must have completed the Appretice Mage guild or 10 levels\n"+
          "of the Abjurers guild first.\n");
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
  /* yhteensa 5 stattia / levelli */
  return "int 2 , ";
}
/*
cast electric: 100%
theory of electricity 100%
*/
skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast poison":(int) 40]);
    }
    if (guild_level >= 2) {
      skill += (["cast poison":(int) 45]);
    }
    if (guild_level >= 3) {
      skill += (["cast poison":(int) 50]);
    }
    if (guild_level >= 4) {
      skill += (["cast poison":(int) 55]);
      skill += (["lore of poison":(int) 10]);
    }
    if (guild_level >= 5) {
      skill += (["cast poison":(int) 60]);
      skill += (["lore of poison":(int) 30]);
    }
    if (guild_level >= 6) {
      skill += (["cast poison":(int) 70]);
      skill += (["lore of poison":(int) 65]);
    }
    if (guild_level >= 7) {
      skill += (["cast poison":(int) 100]);
      skill += (["lore of poison":(int) 100]);
    }

return skill;
}

