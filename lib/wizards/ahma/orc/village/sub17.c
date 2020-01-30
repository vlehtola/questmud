inherit "room/room";
int open;

reset(arg) {
  add_exit("down", "/wizards/ahma/orc/village/sub12");
  short_desc = "In a dark tunnel leading up and down";
  long_desc = "The ladders are leading up and down from this platform. Some light is\n" + 
              "shining into this part of the tunnel from down where seems to be some\n" + 
              "lit torches. The tunnel feels very moist. In the air floats a stench\n" + 
              "of sewage. A quiet sound of running and dripping water can be heard\n" + 
              "coming from down where the slimy ladders lead. A metallic hatch can be\n" + 
              "seen in the top of the ladders.\n";
   
  items = allocate(4);
  items[0] = "lid";
  items[1] = "A shining metallic lid. These kind of lids are usually used to block the\n" + 
             "sewer entrances";
  items[2] = "ladders";
  items[3] = "A bit slimy and greenish ladders lead up and down from the platform you\n" + 
            "are standing on. The ladders are not entirely covered in slime, some\n" + 
            "symmetrical spots with no slime can be seen in each ladder. Seems like\n" + 
            "someone would have been climbing them not too long ago";

}

init() {
  ::init();
  add_action("hep", "open");
  add_action("hap", "close");
}

hep(str) {
  if(str == "lid") {
  if(!open) {
  if(!call_other("/wizards/ahma/orc/village/tent01", "check")) {
    write("You push the metallic lid open, revealing a new exit to up.\n");
    say(this_player()->query_name() + " opens a metallic lid, revealing a new exit to up.\n");
    add_exit("up", "/wizards/ahma/orc/village/tent01");
    call_other("/wizards/ahma/orc/village/tent01", "add_exit", "down", "/wizards/ahma/orc/village/sub17");
    call_other("/wizards/ahma/orc/village/tent01", "opened");
    call_other("/wizards/ahma/orc/village/tent01", "carpetmoved");
    tell_room("/wizards/ahma/orc/village/tent01", "The metallic lid opens, revealing a new exit leading down.\n");
    open = 1;
    return 1;
  }
  else {
    write("Something is blocking the lid from outside and it cannot be opened right now.\n");
    say(this_player()->query_name() + " tries to push the lid open, but something seems to be blocking it from outside.\n");
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
    call_other("/wizards/ahma/orc/village/tent01", "remove_exit", "down");
    call_other("/wizards/ahma/orc/village/tent01", "closed");
    tell_room("/wizards/ahma/orc/village/tent01", "The metallic lid leading down closes.\n");
    open = 0;
    return 1;
  }
  else {
    write("The lid is already closed.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

opened() {
  open = 1;
}

closed() {
  open = 0;
}
