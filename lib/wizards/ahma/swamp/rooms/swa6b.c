inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int alldone, seconddone, tmp;

reset(arg) {
  add_exit("west", "swa6a");
  add_exit("east", "swa6c");
  short_desc = "swamp";
  long_desc = "swamp 6 b.\n";
}

init() {
  ::init();
  add_action("sikret", "install");
}

sikret(str) {
  if(tmp) return 0;
  if(mode != 2) return 0;
  if(!seconddone) return 0;
  if(str == "gema") {
    if(alldone) {
      write("Nothing happens.\n");
      return 1;
    }
    say(this_player()->query_name() + " install a gema-package.\n");
    write("You install a gema-package.\n");
    "/wizards/ahma/swamp/rooms/swafun"->thirdmore();
    call_out("thirddelay", 4);
    tmp++;
    return 1;
  }
  return 0;
}

set_seconddone() {
  seconddone = 1;
  reset();
}

set_alldone() {
  alldone = 1;
  tell_room(this_object(), "You hear a distant rumbling somewhere in the east.\n");
}

remove_tmp() {
  if(!tmp) return 1;
  "/wizards/ahma/swamp/rooms/swafun"->thirdless();
  tmp = 0;
  write("remove_tmp() called.\n");
}

tmp() {
  set_seconddone();
  mode = 2;
}

thirddelay() {
  "/wizards/ahma/swamp/rooms/swafun"->thirdcheck();
}