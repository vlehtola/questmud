inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int cycle;

reset(arg) {
  add_exit("south", "swa4f");
  add_exit("west", "swa3e");
  if(mode) remove_exit("west");
  short_desc = "swamp";
  long_desc = "swamp 3 f.\n";
  call_out("moving", 45);
}

moving() {
  if(!cycle) {
    remove_exit("south");
    tell_room(this_object(), "exitti meni\n");
    cycle++;
    call_out("moving", 45 + random(31));
    "/wizards/ahma/swamp/rooms/swa4f"->remexit();
    return 1;
  }
  add_exit("south", "swa4f");
  tell_room(this_object(), "exitti tuli\n");
  cycle--;
  call_out("moving", 45 + random(31));
  "/wizards/ahma/swamp/rooms/swa4f"->addexit();
}