inherit "room/room";
 
reset(arg) {
  add_exit("north","/wizards/grathlek/area2/hrooma.c");
  set_light(0);

  short_desc = "A dead end.";
  long_desc = "This is a dead end. It is\n"+
              "really cold and dark here.\n"+
              "the floor is covert with ice.\n"; 

  items = allocate(4);
    items[0] = "floor"; 
    items[1] = "This floor is pure ice maybe you should.\n"+
               "melt it.\n";

}
