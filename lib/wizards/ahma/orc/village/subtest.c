inherit "room/room";
int open;

reset(arg) {
  add_exit("down", "/wizards/ahma/orc/village/subXX");
  short_desc = "In a dark tunnel";
  long_desc = "A dark tunnel.\n";
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
    call_other("/wizards/ahma/orc/village/tent01", "add_exit", "down", "/wizards/ahma/orc/village/subtest");
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
