inherit "room/room";
 
 
reset(arg) {
  add_exit("east","/wizards/grathlek/area2/croom1.c");
  add_exit("out","/wizards/grathlek/area2/roome.c");  
  set_light(0);  
  short_desc = "Entrance of dark cathedral Kahnduras.";
  long_desc = "You are standing on the entrance of dark cathedral \n"+
              "Kahnduras. The cathedral is really cold and dark.\n"+
              "A small table is in the center of this room.\n"; 

  items = allocate(4);
    items[0] = "table"; 
    items[1] = "You can see a large book on the table.\n";
}

 
init() {
  ::init();
  add_action("read", "read");
}


read(str) {
  if(str == "book") {
    write("You start reading the book:\n"+
             "\n"+
             "Seven is the number of the power of hell,\n"+
             "and seven is the number of great evils.\n"+ 
             "\n"+
             "Duriel the lord of Pain\n"+
             "Andariel the maiden of Anguish\n"+
             "Belial the lord of Lies\n"+
             "Azmodan the lord of Sin\n"+
             "\n"+
             "Diablo the lord of Terror\n"+
             "Mephisto the lord of Hatred\n"+
             "Baal the lord of Destruction\n");
    return 1;
    }
    write("read what?");
    return 1;
}
