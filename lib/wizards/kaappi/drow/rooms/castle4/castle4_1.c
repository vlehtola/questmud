inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/kaappi/drow/vmap/castle4_entrance.c");
  add_exit("west", "castle4_2.c");

  short_desc = "Castle4";
  long_desc = "A hallway.\n";
              
  set_light(1);
}
