inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("east", "t9.c");
  add_exit("south", "t4.c");
  add_exit("north", "t13.c");
  add_exit("west", "t7.c");
  
  short_desc = "A temple of Lloth";
  long_desc = "A huge temple. The walls of this gorgeous temple\n"+
              "rises until it reaches the ceiling of the whole\n"+
              "tunnel. The temple is full of benches and huge\n"+
              "black stalactites separates the hall. Some drow\n"+
              "priestesses are here mumbling their prayers to Lloth.\n";

  set_light(1);
}
