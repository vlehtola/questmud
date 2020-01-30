inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("down", "/guilds/abjurer/stairs5.c");
  short_desc = "The guild hall of Masters of Abjuration";
  long_desc =

"The top of the tower of Masters of Abjuration. The room is full of\n"+
"old books, scrolls and formulas. The is a bookshelf which covers the\n"+
"whole round room leaving no stone wall visible. The roof is made of\n"+
"thick glass and large iron bars. Golden spiral stairs in the middle\n"+
"of the room leave back to the lower floors of the building. \n";

  items = allocate(12);
  items[0] = "books";
  items[1] = "Old spellbooks with strange magical symbols and words";
  items[2] = "scrolls";
  items[3] = "Dusty magical scrolls lying on the floor";
  items[4] = "formulas";
  items[5] = "Magical formulas, propably old notes of some master abjurer";
  items[6] = "bookshelf";
  items[7] = "A huge wooden bookshelf full of different books";
  items[8] = "stairs";
  items[9] = "Golden spiral stairs leading down";
  items[10] = "roof";
  items[11] = "A glass, dome shaped roof with large iron bars";

}



init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 8;
}

guild_name() {
    return "masters of abjuration";
}
check_joining_rec() {
  if(this_player()->query_guild_level("abjurer") < 5 ) {
    write("You must first complete the guild of Abjurers.\n");
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

  return "wis 1 , ";
}
    skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["mental unity": (int) 100]);
      skill += (["shielding mastery": 15]);
      skill += (["mastery of protection": 50]);
    }
    if (guild_level >= 2) {
      skill += (["abjuration": 60]);
      skill += (["shielding mastery": 25]);
      skill += (["mastery of protection": 55]);
    }
    if (guild_level >= 3) {
      skill += (["shielding mastery":35 ]);
      skill += (["mastery of protection": 65]);
    }
    if (guild_level >= 4) {
      skill += (["abjuration": 70]);
      skill += (["shielding mastery": 45]);
      skill += (["mastery of protection": 70]);
    }
    if (guild_level >= 5) {
      skill += (["shielding mastery": 55]);
      skill += (["mastery of protection": 80]);
    }
    if (guild_level >= 6) {
      skill += (["shielding mastery": 70]);
      skill += (["mastery of protection": 85]);
    }
    if (guild_level >= 7) {
      skill += (["abjuration": 85]);
      skill += (["shielding mastery": 85]);
    }
    if (guild_level >= 8) {
      skill += (["abjuration": 100]);
      skill += (["shielding mastery": 100]);
      skill += (["mastery of protection": 100]);
    }
return skill;
}


