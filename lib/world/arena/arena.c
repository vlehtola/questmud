inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "Arena";
    long_desc = "You are standing center of the arena.\n"+
                "You can 'leave' here.\n";
    property = allocate(1);
    property[0] = "no_summon";
}

init() {
   object ob;
   ::init();
   add_action("leave_arena","leave");
}

leave_arena() {
  this_player()->stop_fight();
  this_player()->stop_all_hunting();
  this_player()->end_death_shadow();
  this_player()->move_player("X#/world/arena/entrance");
  if(this_player()->query_wiz()) write("Death shadow ended.\n");
  return 1;
}
