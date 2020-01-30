inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("north","/guilds/mage/scroll_scribblers");
  add_exit("down","/guilds/mage/tower3");
  short_desc = "The study of master mages";
  long_desc = short_desc+"\n"+
"This room is decorated with colored carpets and tapistry.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Master Mages";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Advanced mages") != 20) {
        write("Must have completed the Advanced Mages first.\n");
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
  return "int 2 , con -1 , ";
}

skill_list(int guild_level) {    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["chanting":(int) 60]);
      skill += (["mana control":(int) 70]);
      skill += (["cast essence":(int) 85]);
      skill += (["cast storm":(int) 55]);
      skill += (["power channeling":(int) 50]);
      skill += (["power focusing":(int) 65]);
      skill += (["power concentration":(int) 55]);
    }
    if (guild_level >= 2) {
      skill += (["power channeling":(int) 55]);
      skill += (["power concentration":(int) 60]);
    }
    if (guild_level >= 3) {
      skill += (["mana control":(int) 75]);
      skill += (["cast storm":(int) 60]);
      skill += (["power channeling":(int) 60]);
      skill += (["power focusing":(int) 70]);
    }
    if (guild_level >= 4) {
      skill += (["chanting":(int) 65]);
      skill += (["invoke ethereal mana":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["cast essence":(int) 90]);
      skill += (["cast storm":(int) 65]);
      skill += (["power channeling":(int) 65]);
      skill += (["power focusing":(int) 75]);
      skill += (["power concentration":(int) 65]);
      skill += (["invoke ethereal mana":(int) 30]);
    }
    if (guild_level >= 6) {
      skill += (["mana control":(int) 80]);
      skill += (["invoke ethereal mana":(int) 40]);
    }
    if (guild_level >= 7) {
      skill += (["chanting":(int) 70]);
      skill += (["cast storm":(int) 70]);
      skill += (["power channeling":(int) 70]);
      skill += (["power concentration":(int) 70]);
      skill += (["invoke ethereal mana":(int) 50]);
    }
    if (guild_level >= 8) {
      skill += (["power focusing":(int) 80]);
      skill += (["invoke ethereal mana":(int) 60]);
    }
    if (guild_level >= 9) {
      skill += (["mana control":(int) 85]);
      skill += (["cast storm":(int) 75]);
      skill += (["power channeling":(int) 75]);
      skill += (["power concentration":(int) 75]);
      skill += (["invoke ethereal mana":(int) 70]);
    }
    if (guild_level >= 10) {
      skill += (["chanting":(int) 100]);
      skill += (["mana control":(int) 100]);
      skill += (["cast essence":(int) 100]);
      skill += (["cast storm":(int) 100]);
      skill += (["power channeling":(int) 100]);
      skill += (["power focusing":(int) 100]);
      skill += (["power concentration":(int) 100]);
      skill += (["invoke ethereal mana":(int) 100]);
    }

return skill;
}
