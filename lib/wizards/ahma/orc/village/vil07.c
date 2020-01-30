inherit "room/room";
int bushes_moved;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/house05");
  add_exit("west", "/wizards/ahma/orc/village/vil05");
  add_exit("northeast", "/wizards/ahma/orc/village/vil26");
  short_desc = "Eastern part of Galor street";
  long_desc = "########### The Galor street continues to west and northeast. The forest lining\n" + 
              "# |  H /  # the road gets thicker when advancing to northeast and thinner when\n" + 
              "#-+--*'   # heading to west. A house is located north from the road. Its weak-\n" + 
              "# |       # looking doors are open. In southeast couple of bushes seem to be\n" + 
              "########### bent a little, making them look uglier than the others.\n";

  items = allocate(4);
  items[0] = "bush";
  items[1] = "Try looking at 'bushes'";
  items[2] = "bushes";
  items[3] = "Couple of the greenish bushes lining the road have been bent in purpose\n" + 
             "by someone. You cannot see behind the thick bushes without moving them\n" + 
             "away from the way";

}          
init() {
  ::init();
  add_action("map", "map");
  add_action("hep", "move");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

hep(str) {
  if(str == "bush" || str == "bushes") {
  if(!bushes_moved) {
    write("You move the bent bushes away from your way and discover a small path leading\n" + 
          "deeper into the bushes.\n");
    say(this_player()->query_name() + " moves the bent bushes away and opens a new entrance deeper into\n" + 
                                      "the bushes.\n");
    add_exit("southeast", "/wizards/ahma/orc/village/bush01");
    call_other("/wizards/ahma/orc/village/bush01", "add_exit", "northwest", "/wizards/ahma/orc/village/vil07");
    call_other("/wizards/ahma/orc/village/bush01", "exit_open");
    tell_room("/wizards/ahma/orc/village/bush01", "The bushes move, opening a new exit to northwest.\n");
    items[3] = "Couple of the greenish bushes lining the road have been bent by someone in\n" + 
               "purpose. Seems that they were hiding an entrance deeper into the bushes.\n" + 
               "A path leads deeper into the bushes in southeast";    
    bushes_moved = 1;
    return 1;
  }
  else {
    write("You move the bent bushes back to their original place. The entrance to deeper\n" + 
          "into the bushes is closed.\n");
    say(this_player()->query_name() + " moves the bent bushes back to their original place. The entrance to\n" + 
                                      "bushes is closed.\n");
    remove_exit("southeast");
    call_other("/wizards/ahma/orc/village/bush01", "remove_exit", "northwest");
    call_other("/wizards/ahma/orc/village/bush01", "exit_closed");
    tell_room("/wizards/ahma/orc/village/bush01", "The bushes move, closing the exit to northwest.\n");
    items[3] = "Couple of the greenish bushes lining the road have been bent by someone in\n" + 
             "purpose. You cannot see behind the thick bushes without moving them away\n" + 
             "from the way";
    bushes_moved = 0;
    return 1;
  }
  {
    write("Move what?\n");
    return 1;
  }
}
}

exit_open() {
  bushes_moved = 1;
}

exit_closed() {
  bushes_moved = 0;
}
