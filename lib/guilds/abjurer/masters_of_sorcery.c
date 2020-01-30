inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("down", "/guilds/abjurer/stairs8");
  short_desc = "The guild hall of Masters of Sorcery";
  long_desc =
"The top of the tower of Masters of Sorcery. The room is full of\n"+
"old books, scrolls and formulas. The is a bookshelf which covers the\n"+
"whole round room leaving no stone wall visible. The roof is made of\n"+
"thick glass and large iron bars. Silver spiral stairs in the middle\n"+
"of the room leave back to the lower floors of the building. \n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 8;
}

guild_name() {
    return "masters of sorcery";
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
  sk += ([2:"cast sorcery:15;"]);
  sk += ([3:"cast enchantment:25;"]);
  sk += ([4:"cast antimagic:50;"]);
  sk += ([5:"cast enchantment:60;"]);
  return sk;
}


get_bonuses(level) {

  return "wis 1 , int 1 , ";
}
skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
    if (guild_level >= 1) {
                skill += (["cast sorcery":(int) 15]);
                skill += (["cast enchantment":(int) 15]);
                skill += (["cast antimagic":(int) 15]);
    }
    if (guild_level >= 2) {
                skill += (["cast sorcery":(int) 30]);
                skill += (["cast enchantment":(int) 30]);
                skill += (["cast antimagic":(int) 30]);
    }
    if (guild_level >= 3) {
                skill += (["cast sorcery":(int) 50]);
                skill += (["cast enchantment":(int) 50]);
                skill += (["cast antimagic":(int) 50]);
    }
    if (guild_level >= 4) {
                skill += (["cast sorcery":(int) 75]);
                skill += (["cast enchantment":(int) 75]);
                skill += (["cast antimagic":(int) 75]);
    }
    if (guild_level >= 5) {
                skill += (["cast sorcery":(int) 100]);
                skill += (["cast enchantment":(int) 100]);
                skill += (["cast antimagic":(int) 100]);
    }
return skill;
}

