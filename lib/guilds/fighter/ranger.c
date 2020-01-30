inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  set_not_out(1);
  set_light(3);
  add_exit("north", "out: 43 93");
  add_exit("south", "out: 43 93");
  add_exit("east", "out: 43 93");
  add_exit("west", "out: 43 93");
  short_desc = "A little clearing";
  long_desc = "A little clearing is surrounded by dense forest.\n"+
                "The relaxed athmosphere makes you feel easy. This is the place\n"+
                "where the ranger guild is located.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 7;
}

guild_name() {
    return "Rangers";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([3:"camping:40;"]);
  sk += ([5:"fire building:40;"]);  
  return sk;
}

get_bonuses(level) {
  return "dex 1 , con 3 , ";
}
/*
  two weapons combat
  hunting
  camping
  fire building
  torch creation
  hiking
*/

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
        skill += (["hunting": 40]);
        skill += (["hiking": 20]);
        skill += (["torch creation": 60]);
    }
    if (guild_level >= 2) {
        skill += (["hunting": 60]);
        skill += (["torch creation": 100]);
        skill += (["camping": 40]);
        skill += (["tame animal": 20]);
        skill += (["control animal": 10]);  
    }
    if (guild_level >= 3) {
        skill += (["hiking": 40]);
        skill += (["hunting": 80]);
        skill += (["camping": 60]);
        skill += (["fire building": 30]);
        skill += (["two weapons combat": 15]);
    }
    if (guild_level >= 4) {
        skill += (["hiking": 60]);
        skill += (["hunting": 100]);
        skill += (["camping": 80]);
        skill += (["fire building": 50]);
        skill += (["two weapons combat": 30]);
    }
    if (guild_level >= 5) {
        skill += (["hiking": 70]);
        skill += (["camping": 100]);
        skill += (["fire building": 100]);
        skill += (["two weapons combat": 70]);
        skill += (["tame animal": 50]);
        skill += (["control animal": 30]);
    }
    if (guild_level >= 6) {
        skill += (["hiking": 80]);
        skill += (["camping": 100]);
        skill += (["fire building": 100]);
        skill += (["two weapons combat": 90]);
        skill += (["tame animal": 50]);
        skill += (["control animal": 60]);
    }
    if (guild_level >= 7) {
        skill += (["hiking": 100]);
        skill += (["camping": 100]);
        skill += (["fire building": 100]);
        skill += (["two weapons combat": 100]);
        skill += (["tame animal": 100]);
        skill += (["control animal": 100]);
    }

  return skill;
}

