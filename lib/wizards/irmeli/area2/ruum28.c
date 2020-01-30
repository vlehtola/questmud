inherit "room/room";

reset(arg) {
 
  add_exit("up","/wizards/irmeli/area2/ruum15.c");
  set_not_out(1);

  short_desc = "Bottom of the lift shaft";
  long_desc = "You are standing in the bottom of lift shaft. The ground is rough and dusty\n"+
                "and therefore here is difficult to move. There is a sole rock lying on\n"+
                "the ground next to you.\n";

  items = allocate(2);
  items[0] = "rock";
  items[1] = "A sole rock has been here so long that layer of moss has grown on it. If you are strong you might lift it"; }

init() {
  ::init(); 
  add_action("lift", "lift");
}

lift(str) {
  if(str == "rock") {
    write("You take a good holding from the sole rock and lift it up. There is a secret gallery under it.\n"); 
    move_object(this_player(),"/wizards/irmeli/area2/ruum23.c");
     command("look", this_player());
    this_player()->set_quest("Find the secret hobbit gallery");
    return 1; 
}
    write("Try another command.\n");
    return 1;
}

