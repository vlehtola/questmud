inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/kaappi/drow/vmap/castle1_entrance.c");
  add_exit("north", "castle1_2.c");

  short_desc = "Castle1";
  long_desc = "A hallway.\n";
              
  set_light(1);
}
