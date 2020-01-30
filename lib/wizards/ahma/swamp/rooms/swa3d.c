inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int firstdone, done;

reset(arg) {
  if(!mode) {
    add_exit("north", "swa2d");
    add_exit("south", "swa4d");
    add_exit("east", "swa3e");
  }
  else {
    if(mode == 1) {
      remove_exit("north");
      remove_exit("south");
      remove_exit("east");
      }
    else {
      add_exit("west", "swa3c");
    }
  }
  short_desc = "swamp";
  long_desc = "swamp 3 d.\n";
}

init() {
  ::init();
  add_action("sikret", "install");
}

sikret(str) {
  if(!firstdone) return 0;
  if(str == "nyu") {
    if(done) {
      write("Nothing happens.\n");
      return 1;
    }
    say(this_player()->query_name() + " install a nyu-package.\n");
    write("You install a nyu-package.\n");
    done++;
    "/wizards/ahma/swamp/rooms/swafun"->callsecond();
    return 1;
  }
  return 0;
}

set_firstdone() {
  firstdone = 1;
  return 1;
}