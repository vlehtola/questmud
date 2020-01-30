inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("north","/guilds/necro/base_guild");
  add_exit("west","/guilds/necro/animators");
  short_desc = "A small room";
  long_desc ="A dusty room full of old tomes and scrolls. Spider webs cover the\n"+
"corners and there is an awful thick smell in the air.\n";
}


init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 8;
}
guild_name() {
    return "apprentice controllers";
}

check_joining_rec() {
  if(this_player()->query_guild_level("necromancers") < 10) {
    write("You must first complete the guild of necromancers.\n");
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
  control corp -> 80
  control ethe -> 60
  control grea -> 40
*/

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }

    if (guild_level >= 1) {
      skill += (["control corporeal": 20]);
    }
    if (guild_level >= 2) {
      skill += (["control corporeal": 35]);

    }
    if (guild_level >= 3) {

      skill += (["control corporeal": 45]);
      skill += (["control ethereal": 10]);
    }
    if (guild_level >= 4) {
      skill += (["control ethereal": 25]);
}
    if (guild_level >= 5) {
      skill += (["control greater undead": 5]);
      skill += (["control corporeal": 60]);
    }
    if (guild_level >= 6) {
      skill += (["control corporeal": 70]);
      skill += (["control ethereal": 35]);
      skill += (["control greater undead": 15]);
    }
    if (guild_level >= 7) {
      skill += (["control corporeal": 80]);
      skill += (["control ethereal": 50]);
      skill += (["control greater undead": 25]);
    }
    if (guild_level >= 8) {
      skill += (["control ethereal": 60]);
      skill += (["control greater undead": 40]);
    }

return skill;
}
