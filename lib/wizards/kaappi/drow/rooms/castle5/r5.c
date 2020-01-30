inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("south", "r2.c");
  add_exit("northeast", "r8.c");
  add_exit("stairs", "torni1.c");

  short_desc = "A hallway";
  long_desc = "You are standing in a quite small room. There is\n"+
              "only a spiral stairs leading up and a small\n"+
              "hallway continues to the northeast. At the end\n"+
              "of the hallway you can see a wooden door.\n";  
 
  set_light(1);
}
