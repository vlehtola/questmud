inherit "room/room";
inherit "room/door";

reset(arg) {
 
  short_desc = "Entrance to the warehouse";
  long_desc = ""
"###########       You have arrived to the northern part of this city.\n"+
"#    *            There is a door in front of you that leads to the\n"+
"#  A |            warehouse. To the south you see the crossing of\n"+
"#+---+-9-+-       Dalvur and Mormain street.\n"+
"#| B |      \n"+
"#|S W| ####\n";

  add_exit("south", "katu41.c");
 
  set_light(3);
  
door_reset();
set_door_label("wooden door",1);
 set_door_dir("north", "warehouse.c",1);
set_door_link("/wizards/kaappi/dcity/rooms/warehouse.c",1);
set_door_code("999", 1);
set_locked(1, 1);

set_not_out();
}
init() {
  ::init();
  door_init();
}
