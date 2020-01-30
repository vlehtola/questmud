inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int cycle;

reset(arg) {
  add_exit("east", "swa2b");
  if(mode) add_exit("south", "swa3a");
  short_desc = "swamp";
  long_desc = "swamp 2 a.\n";
  call_out("moving", 45);
}

moving() {
  if(!cycle) {
    remove_exit("east");
    tell_room(this_object(), "exitti meni\n");
    cycle++;
    call_out("moving", 45 + random(31));
    "/wizards/ahma/swamp/rooms/swa2b"->remexit();
    return 1;
  }
  add_exit("east", "swa2b");
  tell_room(this_object(), "exitti tuli\n");
  cycle--;
  call_out("moving", 45 + random(31));
  "/wizards/ahma/swamp/rooms/swa2b"->addexit();
}