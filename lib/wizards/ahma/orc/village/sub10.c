inherit "room/room";
int locked = 1, open;

reset(arg) {
  add_exit("down", "/wizards/ahma/orc/village/sub04");
  short_desc = "In a dark tunnel leading up and down";
  long_desc = "The ladders are leading up and down from this platform. Some light is\n" + 
              "shining into this part of the tunnel from down where seems to be some\n" + 
              "lit torches. The tunnel feels very moist. In the air floats a stench\n" + 
              "of sewage. A quiet sound of running and dripping water can be heard\n" + 
              "coming from down where the slimy ladders lead. A metallic lid can be\n" + 
              "seen in the top of the ladders. A metallic lever is attached on the\n" +
              "eastern wall.\n";
   
  items = allocate(6);
  items[0] = "lid";
  items[1] = "A dirty metallic lid. These kind of lids are usually used to block the\n" + 
             "sewer entrances";
  items[2] = "ladders";
  items[3] = "A bit slimy and greenish ladders lead up and down from the platform you\n" + 
              "are standing on. The ladders are not entirely covered in slime, some\n" + 
              "symmetrical spots with no slime can be seen in each ladder. Seems like\n" + 
              "someone would have been climbing them not too long ago";
  items[4] = "lever";
  items[5] = "A cold-looking, metallic lever has been attached on the eastern wall of\n" +
             "this tunnel. Maybe it is somehow connected with the metallic lid above";
}

init() {
  ::init();
  add_action("hep", "open");
  add_action("hap", "close");
  add_action("pep", "pull");
  add_action("pep", "move");
}

hep(str) {
  if(str == "lid") {
  if(!open) { 
  if(!locked) {
    write("You open the metallic lid leading up.\n");
    say(this_player()->query_name() + " opens the lid leading up.\n");
    add_exit("up", "/wizards/ahma/orc/village/bush01");
    call_other("/wizards/ahma/orc/village/bush01", "add_exit", "down", "/wizards/ahma/orc/village/sub10");
    call_other("/wizards/ahma/orc/village/bush01", "opened");
    call_other("/wizards/ahma/orc/village/bush01", "hummockmoved");
    tell_room("/wizards/ahma/orc/village/bush01", "The metallic lid opens up from the ground, revealing a new exit leading down.\n");
    open = 1;
    return 1;
  }
  else {
    write("The metallic lid seems to be locked.\n");
    say(this_player()->query_name() + " tries to open the lid leading up, but seems that it is locked.\n");
    return 1;
  }
  }
  else {
    write("The lid is already open.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

hap(str) {
  if(str == "lid") {
  if(open) {
    write("You close the metallic lid leading up.\n");
    say(this_player()->query_name() + " closes the metallic lid leading up.\n");
    remove_exit("up");
    call_other("/wizards/ahma/orc/village/bush01", "remove_exit", "down");
    call_other("/wizards/ahma/orc/village/bush01", "closed");
    call_other("/wizards/ahma/orc/village/bush01", "hummockmoved");
    tell_room("/wizards/ahma/orc/village/bush01", "The metallic lid closes, hiding the entrance which was leading down.\n");
    open = 0;
    return 1;
  }
  else {
    write("The metallic lid is already closed.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

pep(str) {
  if(str == "lever") {
  if(locked) {
    write("You pull the metallic lever on the wall and hear a quiet click as the lid unlocks.\n");
    say(this_player()->query_name() + " pulls the metallic lever on the wall, unlocking the lid.\n");
    locked = 0;
    return 1;
  }
  else {
    write("You pull the metallic lever on the wall and hear a quiet click as the lid locks up.\n");
    say(this_player()->query_name() + " pulls the metallic lever on the wall, locking the lid up.\n");
    locked = 1;
    return 1;
  }
  }
}

lockup() {
  locked = 1;
  open = 0;
}
