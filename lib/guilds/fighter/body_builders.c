inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("northeast","/guilds/fighter/warrior");
  short_desc = "The Body Builders exercising area";
  long_desc =
short_desc+"\n"+
"Heavy weights lay all about the floor. A few big muscular fighters\n"+
"are doing their dayly excersice. The training area holds a bitter\n"+
"smell of sweat. The sworn Body Builders are serious people doing\n"+
"their best to gain more physical abilities. A poster has been nailed\n"+
"on the wall.\n";
 items = allocate(2);
 items[0] = "poster";
 items[1] = "There is some writing on the poster:\n"+
        "NOTE: The bodybuilder's guild is only for raising stats";
  set_light(3);
  set_not_out(1);
}

init() {
  ::init();
  guild_init();
}

show_bb_info() {
  write("The stat bonuses are increased each level. Look at the poster for more info.\n");
  return 1;
}


// max level 30 set by Celtron. 1.11.2005
// players must take other guilds if they want more levels.
guild_max_level() {
  return 30;
}

guild_name() {
    return "Body builders";
}
check_joining_rec() {
    if(strlen(this_player()->query_total_string()) < 10) {
        write("You lack the power to join. (1G worth)\n");
        return 0;
    }
    if(this_player()->query_guild_level("Fighters") < "/guilds/fighter/fighter"->guild_max_level()) {
        write("You must have completed the Fighter guild first.\n");
        return 0;
    }
    return 1;
}

check_advance_rec(int lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([2:"body building:80;"]);
  sk += ([3:"body building:90;"]);
  sk += ([5:"body building:100;"]);
  return sk;
}

get_bonuses(int level) {
  if(level <= 5)
    return "str 2 , dex 2 , con 2 , int 2 , wis 2 , ";
  else
    return "str 1 , dex 1 , con 1 , int 1 , wis 1 , ";

}

skill_list(int guild_level) {
  mapping skill;
    skill = ([ ]);
    if (guild_level >= 1) {
      skill += (["body building":(int) 100]);
    }
  return skill;
}

