inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/kaappi/drow/vmap/temple_entrance.c");
  add_exit("north", "t3.c");

  short_desc = "A temple of Lloth";
  long_desc = "A very short hallway leading inside the temple.\n"+ 
              "There is only a small table next to wall and a \n"+
              "picture of a giant spider above it. A quiet\n"+
              "mumbling can be heard from the temple.\n";
              
  set_light(1);
}
