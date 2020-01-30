inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  call_other("/wizards/celtron/cemetary/virtual_map", "loading_hc", 0);
  add_exit("out","/wizards/celtron/cemetary/virtual_map: 30 8");
  add_exit("south", "/guilds/necro/control1");
  add_exit("northwest", "/guilds/necro/dark_power");
  add_exit("northeast", "/guilds/necro/necro");
  short_desc = "The room of dark mystics; the necromancers";
  long_desc = "Necromancers train here their unholy skills and so that\n"+
        "they might get better in practicing their vile art.\n"+
        "This is the most unholy place on Deleria: the guild of necromancers.\n"+
        "An old writing is scribbled on the wall 'thou must mock the dead to\n"+
        "truly master the secrets'.\n"+
        "Some bone bracelets are hanging from hooks attached to the wall.\n";
}

ota_bracu(string str) {
  if(str != "bracelet" && str != "at bracelets") return 0;
  if (this_player()->query_guild_level(guild_name()) < 10) {
    write("You are not worthy.\n");
    return 1;
  }
  write("You take one bracelet from the hook.\n");
move_object(clone_object("/guilds/necro/obj/bone_bracelet"), this_player());
  return 1;
}

guild_max_level() {
  return 10;
}
init() {
  ::init();
  guild_init();
// add_action("ota_bracu", "get");
// add_action("ota_bracu", "take");
// add_action("ota_bracu", "look");
}

guild_name() {
    return "necromancers";
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
  /* yhteensa 5 stattia / levelli */
  return "int 1 , wis 1 , ";
}
/*
  cast dark power -> 60
  cast r corp -> 60
  cast r ethe -> 40
  cast minorn -> 60
  cast focus dp -> 60
  dark power -> 30
  dark lore -> 100
  cast raise soul -> 100
*/

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast dark power": 30]);
      skill += (["cast focus dark power": 30]);
      skill += (["cast raise corporeal": 30]);
      skill += (["cast minor necromancy": 30]);
      skill += (["cast raise soul": 30]);
      skill += (["freeze corpse": 30]);
    }
    if (guild_level >= 2) {
      skill += (["dark power": 10]);
    }
    if (guild_level >= 3) {
      skill += (["cast dark power": 40]);
      skill += (["cast focus dark power": 40]);
      skill += (["cast raise corporeal": 40]);
      skill += (["cast minor necromancy": 40]);
      skill += (["cast raise soul": 50]);
      skill += (["freeze corpse": 50]);
    }
    if (guild_level >= 4) {
      skill += (["dark power": 15]);
      skill += (["cast raise ethereal": 20]);
    }
    if (guild_level >= 5) {
      skill += (["dark lore": 60]);
    }
    if (guild_level >= 6) {
      skill += (["cast dark power": 45]);
      skill += (["cast focus dark power": 45]);
      skill += (["cast raise corporeal": 45]);
      skill += (["cast raise soul": 55]);
      skill += (["cast minor necromancy": 45]);
      skill += (["freeze corpse": 75]);
    }
    if (guild_level >= 7) {
      skill += (["dark lore": 80]);
    }
    if (guild_level >= 8) {
      skill += (["dark power": 20]);
      skill += (["cast raise ethereal": 30]);
    }
    if (guild_level >= 9) {
      skill += (["cast dark power": 50]);
      skill += (["cast focus dark power": 50]);
      skill += (["cast raise corporeal": 50]);
      skill += (["cast minor necromancy": 50]);
      skill += (["dark lore": 100]);
      skill += (["cast raise soul": 80]);
    }
    if (guild_level >=10) {
      skill += (["dark power": 30]);
      skill += (["cast raise ethereal": 40]);
      skill += (["cast dark power": 60]);
      skill += (["cast focus dark power": 60]);
      skill += (["cast raise corporeal": 60]);
      skill += (["cast minor necromancy": 60]);
      skill += (["cast raise soul": 100]);
      skill += (["freeze corpse": 100]);
    }
return skill;
}

