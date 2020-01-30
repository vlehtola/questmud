inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  set_not_out(1);
  set_light(3);
  move_object(clone_object("/world/objects/weapon_rack"), this_object());
  add_exit("north","/guilds/fighter/fighter");
  add_exit("southwest","/guilds/fighter/body_builders"); 
  short_desc = "The warrior training area";
  long_desc =
"Located in the fighter's guild facility, this place is not very\n"+
"different from the other rooms. There seems to be a small storage\n";
"area for weapons in one corner of the room though.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 5;
}

guild_name() {
    return "Warriors";
}
check_joining_rec() {
    if(this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
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
  return "str 1 , con 2 , ";
}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
      skill += (["attack":(int) 80]);
      skill += (["evaluate":(int) 30]);
      skill += (["compare":(int) 30]);
    }
    if (guild_level >= 2) {
      skill += (["attack":(int) 100]);
      skill += (["critical":(int) 40]);
      skill += (["evaluate":(int) 50]);
      skill += (["compare":(int) 50]);
    }
    if (guild_level >= 3) {
      skill += (["doublehit":(int) 10]);
      skill += (["evaluate":(int) 70]);
      skill += (["compare":(int) 70]);
    }
    if (guild_level >= 4) {
      skill += (["critical":(int) 50]);
      skill += (["doublehit":(int) 20]);
      skill += (["evaluate":(int) 90]);
      skill += (["compare":(int) 90]);
    }
    if (guild_level >= 5) {
      skill += (["evaluate":(int) 100]);
      skill += (["compare":(int) 100]);
      skill += (["critical":(int) 60]);
      skill += (["doublehit":(int) 40]);
      skill += (["find weakness":(int) 15]);
    }
  return skill;
}

