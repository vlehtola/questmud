inherit "room/room";
int bushes_moved, moved, lid_open;
object hitman01, hitman02;

reset(arg) {
  short_desc = "A little opening inside thick bushes";
  long_desc = "Some thick bushes are surrounding this area. The small opening inside\n" + 
              "the bushes seems to be a dead end. All of the green bushes seem to be\n" + 
              "nature's creations, not planted by anyone. The bushes look all alike,\n" + 
              "though couple of them seem to be bent a little in northwest. The air\n" + 
              "smells of fresh topsoil and some other, more annoying stench. Few\n" + 
              "fading footprints can be seen pressed in the soil.\n";
              
  items = allocate(10);
  items[0] = "bush";
  items[1] = "Try looking at 'bushes'";
  items[2] = "bushes";
  items[3] = "Couple of the greenish bushes in northwest have been bent by someone in\n" + 
             "purpose. You cannot see behind the thick bushes without moving them away\n" + 
             "from the way";
  items[4] = "footprints";
  items[5] = "The fading footprints are leading from northwest to the eastern edge of the\n" + 
             "opening. They disappear near a grassy hummock";
  items[6] = "hummock";
  items[7] = "A small hummock consists of normal grass and some other weeds. It seems,\n" + 
             "however, that the weeds are not getting enough nutrients. Even the grass\n" + 
             "is turning into a light yellow in colour. In their roots, from where the\n" + 
             "weeds are sucking the nutrients, must be something wrong";
  items[8] = "lid";
  items[9] = "You see nothing special";
  
  if(!moved) { items[9] = "You see nothing special"; }
  set_blocker("hitman", "northwest");
}

init() {
  ::init();
  add_action("hep", "move");
  add_action("hap", "open");
  add_action("pep", "close");
}

hep(str) {
  if(str == "bush" || str == "bushes") {
  if(!bushes_moved) {
    write("You move the bent bushes away from your way and discover a small path leading\n" + 
          "out of the bushes.\n");
    say(this_player()->query_name() + " moves the bent bushes away and opens a new entrance out of\n" + 
                                      "the bushes.\n");
    add_exit("northwest", "/wizards/ahma/orc/village/vil07");
    call_other("/wizards/ahma/orc/village/vil07", "add_exit", "southeast", "/wizards/ahma/orc/village/bush01");
    call_other("/wizards/ahma/orc/village/vil07", "exit_open");
    tell_room("/wizards/ahma/orc/village/vil07", "The bushes move, opening a new exit to southeast.\n");
    exit_open();
    return 1;
  }
  else {
    write("You move the bent bushes back to their original place. The entrance out of\n" + 
          "the bushes is closed.\n");
    say(this_player()->query_name() + " moves the bent bushes back to their original place. The entrance out\n" + 
                                      "of the bushes is closed.\n");
    remove_exit("northwest");
    call_other("/wizards/ahma/orc/village/vil07", "remove_exit", "southeast");
    call_other("/wizards/ahma/orc/village/vil07", "exit_closed");
    tell_room("/wizards/ahma/orc/village/vil07", "The bushes move, closing the exit to southeast.\n");
    exit_closed();
    return 1;
  }
  }
  if(str == "hummock") {
  if(!moved) {
    write("You pull the hummock and discover that it was cut off from the ground long\n" + 
          "before you pulled it. Under the hummock is revealed a dirty metallic lid.\n");
    say(this_player()->query_name() + " moves the hummock, revealing a dirty metallic lid under it.\n");
    items[9] = "A dirty metallic lid. These kind of lids are usually used to block\n" + 
               "the sewer entrances";
    moved = 1;
    return 1;
  }
  else {
    write("You put the hummock back in its original place, hiding the metallic lid.\n");
    say(this_player()->query_name() + " hides the metallic lid with a hummock.\n");
    remove_exit("down");
    items[9] = "You see nothing special";
    moved = 0;
    lid_open = 0;
    return 1;
  }
  }
}

hap(str) {
  if(str == "lid") {
  if(moved) {
  if(!lid_open) {
    write("You try to open the metallic lid, but do not manage to move it even a bit.\n" + 
          "It must be locked from other side.\n");
    say(this_player()->query_name() + " tries to open the metallic lid, but does not manage to move it even a bit.\n");
    return 1;
  }
  else {
    write("The lid is already open.\n");
    return 1;
  }
  }
  else {
    write("You don't see a lid around here.\n");
    return 1;
  }
  }
  else {
    write("Open what?\n");
    return 1;
  }
}

pep(str) {
  if(str == "lid") {
  if(moved) {
  if(lid_open) {
    write("You close the dirty metallic lid. A soft click can be heard when the lid locks up from the other side.\n");
    say(this_player()->query_name() + " closes the metallic lid. A soft click can be heard when the lid locks up from the other side.\n");
    call_other("/wizards/ahma/orc/village/sub10", "remove_exit", "up");
    tell_room("/wizards/ahma/orc/village/sub10", "The metallic lid leading up closes.\n");
    lid_open = 0;
    return 1;
  }
  else {
    write("The metallic lid is already closed.\n");
    return 1;
  }
  }
  else {
    write("You don't see a lid around here.\n");
    return 1;
  }
  }
  else {
    write("Close what?\n");
    return 1;
  }
}

exit_open() {
  bushes_moved = 1;
  items[3] = "Couple of the greenish bushes in northwest have been bent by someone in\n" + 
             "purpose. Seems that they were hiding the entrance out of the bushes.\n" + 
             "A path is leading out of the bushes in northwest";
}

exit_closed() {
  bushes_moved = 0;
  items[3] = "Couple of the greenish bushes in northwest have been bent by someone in\n" + 
               "purpose. You cannot see behind the thick bushes without moving them away\n" + 
               "from the way";
}

opened() {
  lid_open = 1;
}

closed() {
  lid_open = 0;
}

hummockmoved() {
  moved = 1;
}

summonkillers() {
  if(!hitman01) { move_object(hitman01 = clone_object("/wizards/ahma/orc/mob/hitman"), this_object()); }
  if(!hitman02) { move_object(hitman02 = clone_object("/wizards/ahma/orc/mob/hitman"), this_object()); }
}