inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int cycle;

reset(arg) {
  add_exit("north", "swa3c");
  add_exit("south", "swa5c");  
  add_exit("west", "swa4b");
  add_exit("east", "swa4d");
  if(mode) remove_exit("north");
  short_desc = "swamp";
  long_desc = "swamp 4 c.\n";
  call_out("moving", 45);
}

moving() {
  if(!cycle) {
    remove_exit("east");
    add_exit("south", "swa5c");
    tell_room(this_object(), "exitti southiin\n");
    cycle++;
    call_out("moving", 45 + random(31));
    "/wizards/ahma/swamp/rooms/swa4d"->remexit();
    "/wizards/ahma/swamp/rooms/swa5c"->addexit();
    return 1;
  }
  remove_exit("south");
  add_exit("east", "swa4d");
  tell_room(this_object(), "exitti eastiin\n");
  cycle--;
  call_out("moving", 45 + random(31));
  "/wizards/ahma/swamp/rooms/swa4d"->addexit();
  "/wizards/ahma/swamp/rooms/swa5c"->remexit();
}