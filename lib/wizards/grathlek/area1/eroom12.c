inherit "room/room";
 
 
reset(arg) {
  add_exit("southwest","/wizards/grathlek/area1/eroom11.c"); 
  
  short_desc = "An empty room.";
  long_desc = "There is nothing in these room besides\n"+
              "curtains on north wall. In curtains there are\n"+
              "something about some holy meteor.\n"; 

items = allocate(4);
  items[0] = "curtains";
  items[1] = "In curtains there are pictures and writing of the holy meteor";
}
init() {
  ::init();
  add_action("open", "open");
  add_action("close", "close");
}

open(str) {
  object ob;
  if(str == "curtains") {
    write("You open the curtains.\n");
    this_player()->set_quest("Open curtains in paladin training area");
    add_exit("stairs","/wizards/grathlek/area1/uproom1.c");
    return 1;
    }
  write("Open what?.\n");
  return 1;
}
close(str) {
  if(str == "curtains") {
    write("You close the curtains");
    remove_exit("stairs"); 
    return 1;
    }
  write("Close what?.\n");
  return 1;
}
