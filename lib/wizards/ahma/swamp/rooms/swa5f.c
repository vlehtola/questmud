inherit "room/room";
int done;

reset(arg) {
  add_exit("south", "swa6f");
  short_desc = "swamp";
  long_desc = "swamp 5 f.\n";
}

init() {
  ::init();
  add_action("sikret", "install");
}

sikret(str) {
  if(str == "nyo") {
    if(done) {
      write("Nothing happens.\n");
      return 1;
    }
    say(this_player()->query_name() + " install a nyo-package.\n");
    write("You install a nyo-package.\n");
    done++;
    // call_other("/wizards/ahma/swamp/rooms/swa1f", "mode2");
    // "/wizards/ahma/swamp/rooms/swafun.c"->callfirst();
    "/wizards/ahma/swamp/rooms/swafun"->callfirst();
    return 1;
  }
  return 0;
}

testi() {
  write("testi\n");
  return 1;
}