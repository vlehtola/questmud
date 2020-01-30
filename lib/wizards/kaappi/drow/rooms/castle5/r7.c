inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("south", "r4.c");
  add_exit("northwest", "r8.c");
  add_exit("stairs", "torni3.c");

  short_desc = "A hallway";
  long_desc = "You are standing in a quite small room. There is\n"+
              "only a spiral stairs leading up and a small\n"+
              "hallway continues to the northwest. At the end\n"+
              "of the hallway you can see a wooden door.\n"; 
 
  set_light(1);
}
