inherit "room/room";

reset(arg) {
  add_exit("out", "/wizards/ahma/orc/forest/bush01");
  short_desc = "In a small decaying wooden shack";
  long_desc = "It can almost be heard when this horrible-looking shack is decaying. The\n" +
              "shack is quite dimly luminated, no other obvious light sources can be\n" + 
              "seen but the light that is coming through the ceiling which is full of\n" + 
              "small and a bit bigger holes. The floor is full of wreckage: Some pieces\n" + 
              "of ceiling have fell down and two chairs and a big dining table lie broken\n" + 
              "on the floor. Everything is covered with thin greenish layer of mold. In\n" + 
              "the back of the shack there seems to be some kind of a hole in the ground.\n";

  items = allocate(4);
  items[0] = "door";
  items[1] = "An ordinary-looking wooden door. When compared to the rest of the shack,\n" + 
             "the door looks very clean and new. The door seems to be closed";
  items[2] = "hole";
  items[3] = "The topsoil has collapsed deeper into the ground. There must be a small\n" + 
             "hole in the bedrock around this area because the soil has collapsed.\n" + 
             "The hole seems to be safe enough for you to enter it";
}

init() {
  ::init();
  add_action("hep", "enter");
}

hep(str) {
  if(str == "hole") {
    write("You stumble down the steep hill leading downwards inside the earth.\n");
    this_player()->move_player("hole#/wizards/ahma/orc/forest/sub01.c");
    return 1;
  }
}