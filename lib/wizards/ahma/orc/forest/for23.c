inherit "room/room";
int moved;

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/forest/for24");
  short_desc = "At the base of a high cliff";
  long_desc = "The stony subterranean bedrock makes the ground much harder and more\n" + 
              "uncomfortable to walk on. A high cliff rises reaching the sky in north.\n" + 
              "Thick forest is surrounding this area and it seems that some trees have\n" + 
              "been cut down from the base of the cliff. A wooden shack, surrounded by\n" + 
              "numerous bushes is sitting in north. Behind quite long distance to west\n" + 
              "can be seen the entrance to a small canyon.\n";
  
  items = allocate(12);
  items[0] = "cliff";
  items[1] = "A high cliff reaches towards the sky behind in north. It looks like a\n" + 
             "common cliff with its few promontories, loose rocks and stunted trees\n" + 
             "growing in it. Though the cliff could look like a boring and every way\n" + 
             "dead place, it is full of life. Many birds and few sheep-like animals\n" + 
             "live in its bluffs all around the year";
  items[2] = "shack";
  items[3] = "A crude-looking small wooden shack must have stood here quite a long time.\n" + 
             "The roof seems to be partly broken, so as the walls, too. No windows are\n" + 
             "in sight on the frontside of the shack. A door stands in the middle of the\n" + 
             "wooden wall. The door is closed";
  items[4] = "bush";
  items[5] = "Try looking at 'bushes'";
  items[6] = "bushes";
  items[7] = "Numerous green bushes surround the shack. It almost seems, like the shack\n" + 
             "would be growing from the middle of the bushes. The bushes seem all alike,\n" + 
             "but an exception is made by a bush where is attached some kind of a torn\n" + 
             "piece of cloth";
  items[8] = "cloth";
  items[9] = "A piece of cloth has been torn off probably from some clothing by one of\n" + 
             "the green bushes. Because the bushes cannot move, someone must have walked\n" + 
             "very close to the bushes to rip the clothing";
 items[10] = "door";
 items[11] = "An ordinary-looking wooden door. When compared to the rest of the shack,\n" + 
             "the door looks very clean and new. The door seems to be closed";
}

init() {
  ::init();
  add_action("hep", "move");
  add_action("hap", "open");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

hep(str) {
  if(str == "bushes" || str == "bush") {
  if(!moved) {
    write("You push the bushes aside, revealing a small path leading to north inside the bushes.\n");
    say(this_player()->query_name() + " moves some bushes aside, revealing a new exit to north.\n");
    add_exit("north", "/wizards/ahma/orc/forest/bush01");
    call_other("/wizards/ahma/orc/forest/bush01", "add_exit", "south", "/wizards/ahma/orc/forest/for23");
    call_other("/wizards/ahma/orc/forest/bush01", "exit_open");
    tell_room("/wizards/ahma/orc/forest/bush01", "The bushes move aside, revealing an exit to south.\n");
    moved = 1;
    return 1;
  }
  else {
    write("You move the bushes back to their original place, closing the exit to north.\n");
    say(this_player()->query_name() + " moves the bushes back to their original place, closing the exit to north.\n");
    remove_exit("north");
    call_other("/wizards/ahma/orc/forest/bush01", "remove_exit", "south");
    call_other("/wizards/ahma/orc/forest/bush01", "exit_closed");
    tell_room("/wizards/ahma/orc/forest/bush01", "The bushes move, closing the exit to south.\n");
    moved = 0;
    return 1;
  }
  }
  else {
    return;
  }
}

hap(str) {
  if(str == "door") {
    write("The door seems to be locked.\n");
    say(this_player()->query_name() + " tries to open the wooden door, but it seems to be locked.\n");
    return 1;
  }
}


exit_open() {
  moved = 1;
}

exit_closed() {
  moved = 0;
}
