inherit "room/room";
int moved, picked;

reset(arg) {
  short_desc = "Inside the thick bushes";
  long_desc = "The bushes end in the eastern wall of the wooden shack. In the wall\n" + 
              "there seems to be a huge hole leading to west, into the building.\n" + 
              "The bushes and the wet soil emit quite strong smell, which is mixed\n" + 
              "with the smell of rotting wood coming inside from the shack.\n";
  items = allocate(8);
  items[0] = "bush";
  items[1] = "Try looking at 'bushes'";
  items[2] = "bushes";
  items[3] = "Numerous green bushes surround the shack. It almost seems, like the shack\n" + 
             "would be growing from the middle of the bushes. The bushes seem all alike\n" + 
             "and a strong smell is emitting from them. One of the bushes seems to grow\n" + 
             "some flowers";
  items[4] = "hole";
  items[5] = "A darkish gaping hole leads from here into the lousy-looking shack. Looks\n" + 
             "like the hole would have formed in the wall just by natural decaying. But\n" + 
             "it could also have been made by some creature. Some sharp ends of wooden\n" + 
             "logs look almost like teeth in the edges of the hole";
  items[6] = "flowers";
  items[7] = "Quite ugly-looking grayish flowers grow in one of the bushes surrounding\n" + 
             "the shack. The flowers look also quite fragile, they seem to survive only\n" + 
             "with the help of great luck. The flowers seem to be ordinary carnations,\n" + 
             "but only living in very difficult terrain";

  picked = 0;
}
            

init() {
  ::init();
  add_action("hep", "move");
  add_action("hap", "enter");
  add_action("pep", "pick");
}

hep(str) {
  if(str == "bush" || str == "bushes") {
  if(!moved) {
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
    moved = 1;
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
    moved = 0;
    return 1;
  }
  {
    write("Move what?\n");
    return 1;
  }
}
}

hap(str) {
  if(str == "hole") {
    write("You enter the gaping hole in the wall of the wooden shack.\n");
    this_player()->move_player("hole#/wizards/ahma/orc/forest/house03.c");
    return 1;
  }
}

pep(str) {
  if(str == "flowers" || str == "flower" || str == "carnation") {
  if(picked != 2) {
    write("You pick one of the fragile and ugly carnations growing in one of the bushes.\n");
    say(this_player()->query_name() + " picks a flower growing in one of the bushes.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/carnation"), this_player());
    picked++;
    return 1;
  }
  else {
    write("Someone has already been picking the flowers from the bush. You do not want\n" +
          "to ruin the whole bunch by picking the rest of the flowers away. You will\n" + 
          "have to wait for a moment to some new flowers to grow up.\n");
    return 1;
  }
  }
  else { return; }
}

exit_open() {
  moved = 1;
}

exit_closed() {
  moved = 0;
}
