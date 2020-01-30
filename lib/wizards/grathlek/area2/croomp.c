inherit "room/room";
 
 
reset(arg) {
  add_exit("west","/wizards/grathlek/area2/croomla.c");  

  short_desc = "Portal room.";
  long_desc = "This is the portal room. There is a lever on the \n"+
              "wall and a huge pentagram on the floor.\n"; 
  items = allocate(4);
    items[0] = "lever"; 
    items[1] = "The lever is made of bone.\n";

}

 
init() {
  ::init();
  add_action("pull", "pull");
}


pull(str) {
  if(str == "lever") {
    write("You pull the lever.\n");
    write("The pentagram starts glowin red\n"+
          "and Black. A portal raises above the\n"+
          "pentagram.\n");
    add_exit("portal","/wizards/grathlek/area2/hroom.c");
    return 1;
    }
    write("Pull what?");
    return 1;
}
