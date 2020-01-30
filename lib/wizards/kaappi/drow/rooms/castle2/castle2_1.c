inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/kaappi/drow/vmap/castle2_entrance.c");
  add_exit("south", "castle2_2.c");

  short_desc = "Castle2";
  long_desc = "A hallway.\n";
              
  set_light(1);
}
