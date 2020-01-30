

inherit "room/room";
inherit "room/door";


reset(arg) {
  if (arg) { return; }
  short_desc = "On the bottom of the well";
  long_desc = "Inside of the drained well. The bottom of the well is still damp. The ground\n"+
              "is muddy and some old footprints have been left in the mud. The well is more\n"+
              "than fifteen metres deep. There are moss growing on the walls. A long rope\n"+
              "is hanging above you. A sign is placed on the wall.\n";

  items = allocate(6);
  items[0] = "footprints";
  items[1] = "Old footprints have been left in the mud.";
  items[2] = "rope";
  items[3] = "A long rope is hanging above your head.";
  items[4] = "sign";
  items[5] = "The sign reads: DUNGEON.";

  door_reset();
  set_door_label("Dungeon door", 1);
  set_door_dir("north", "/wizards/irmeli/castle/dungeon.c", 1);
  set_door_link("/wizards/irmeli/castle/dungeon.c", 1);
  set_door_code("447", 1);
  set_locked(1, 1);
}


init() {
  ::init();
  door_init();
  add_action("climb", "climb");

}

climb(str) {
  if(str != "up") return;
write("You jump and grab from the rope and climb up.\n");
    move_object(this_player(),"/wizards/irmeli/castle/yard17.c");
    this_player()->look(); 
 return 1;
}