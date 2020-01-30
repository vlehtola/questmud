inherit "room/room";
int open, event;

reset(arg) {
  add_exit("down", "/wizards/ahma/orc/village/sub02");
  short_desc = "In a dark tunnel leading up and down";
  long_desc = "The ladders are leading up and down from this platform. Some light is\n" + 
              "shining into this part of the tunnel from down where seems to be some\n" + 
              "lit torches. The tunnel feels very moist. In the air floats a stench\n" + 
              "of sewage. A quiet sound of running and dripping water can be heard\n" + 
              "coming from down where the slimy ladders lead. A metallic hatch can be\n" + 
              "seen in the top of the ladders.\n";
   
   items = allocate(4);
   items[0] = "hatch";
   items[1] = "A metallic hatch shimmers weakly in the dim light. Seems that there is\n" + 
              "no lock or such thing in it, so it can be opened and closed whenever needed";
   items[2] = "ladders";
   items[3] = "A bit slimy and greenish ladders lead up and down from the platform you\n" + 
              "are standing on. The ladders are not entirely covered in slime, some\n" + 
              "symmetrical spots with no slime can be seen in each ladder. Seems like\n" + 
              "someone would have been climbing them not too long ago";

}

init() {
  ::init();
  if(event) {
    call_out("hatchcloses", 1);
    event = 0;
  }
  add_action("hep", "open");
  add_action("hap", "close");
}

hep(str) {
  if(str == "hatch") {
  if(call_other("/wizards/ahma/orc/village/house08", "movedi")) {
  if(!open) {
    write("You open the metallic hatch leading up.\n");
    say(this_player()->query_name() + " opens a metallic hatch leading up.\n");
    add_exit("up", "/wizards/ahma/orc/village/house08");
    call_other("/wizards/ahma/orc/village/house08", "add_exit", "down", "/wizards/ahma/orc/village/sub01");
    call_other("/wizards/ahma/orc/village/house08", "opened");
    tell_room("/wizards/ahma/orc/village/house08", "The metallic hatch leading down opens.\n");
    open = 1;
    return 1;
  }
  else {
    write("The metallic hatch is already open.\n");
    return 1;
  }
  }
  else {
    write("Something seems to be blocking the hatch from outside.\n");
    say(this_player()->query_name() + " tries to open the hatch but something seems to be blocking it from outside.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

hap(str) {
  if(str == "hatch") {
  if(open) {
    write("You close the metallic hatch leading up.\n");
    say(this_player()->query_name() + " closes the metallic hatch leading up.\n");
    remove_exit("up");
    call_other("/wizards/ahma/orc/village/house08", "remove_exit", "down");
    call_other("/wizards/ahma/orc/village/house08", "closed");
    tell_room("/wizards/ahma/orc/village/house08", "The metallic hatch leading down closes.\n");
    open = 0;
    return 1;
  }
  else {
    write("The metallic hatch is already closed.\n");
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

moveda() {
  event = 1;
}

hatchcloses() { 
  open = 0;
  remove_exit("up");
  tell_room(this_object(), "Tas'gand leaves up and slams the hatch close. Some rumbling can be heard upstairs.\n");
  move_object(present("tas'gand", this_object()), "/wizards/ahma/orc/village/house08");
  tell_room("/wizards/ahma/orc/village/house08", "Chief Tas'gand rushes in from the hatch in the corner of the room and slams it close.\n");
}