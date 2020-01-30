inherit "room/room";
init() {
  ::init();
  add_action("pull", "pull");
}

pull(str) {
  if(str != "railing") return;
  write("As you take hold of the railing, it comes loose in your hands.\n");
  say(""+this_player()->query_name()+" fumbles with the torchholder.\n");
  move_object(clone_object("/wizards/walla/northern/stuph/railing"),this_player());
  return 1;
}

object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/ziral");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("up","/wizards/walla/northern/rooms/lvl3/stairs_d");
  add_exit("north","court_15");
  short_desc = "At a staircase";
  long_desc =
  long_desc =
"You are standing next to stairs, leading up to the ramparts, where you can hear\n" +
"more noises. The stairs wounds like a spiral, to take less space, but is a bit\n" +
"harder to climb with all the gear. There is a railing crafted out of iron, that\n" +
"is about to come loose, due to dwarves pulling at it when going up.\n";
 
}
