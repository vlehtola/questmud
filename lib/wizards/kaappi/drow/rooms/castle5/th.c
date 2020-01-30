inherit "room/room";
inherit "room/door";

reset(arg) {  
  short_desc = "A training hall";
  long_desc = "As you step inside from the door, a huge hall\n"+
              "opens in front of you. There are many drow children\n"+
              "around the hall training their weaponskills. Only male \n"+
              "drows can be seen here. The walls of this hall are full\n"+
              "of different kind of weapons, spears, bows, shields and\n"+                                       "many kind of swords can be seen.\n"; 
  set_light(1);

door_reset();
  set_door_label("wooden door",1);
  set_door_dir("south", "r8.c",1);
  set_door_link("/wizards/kaappi/drow/rooms/castle5/r8.c",1);
  set_locked(0, 1);
set_not_out();
}

init() {
  ::init();
  door_init();
}
