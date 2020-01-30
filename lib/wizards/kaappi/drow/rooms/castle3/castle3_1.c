inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/kaappi/drow/vmap/castle3_entrance.c");
  add_exit("south", "castle3_2.c");

  short_desc = "Castle3";
  long_desc = "A hallway.\n";
              
  set_light(1);
}
