inherit "room/room";
object monster;

reset(arg) {
  add_exit("up","/wizards/rehti/workroom");
  add_exit("north","/wizards/rehti/dormund/city");
  short_desc = "Fortress Dormund entrance";
  long_desc = "You have come by a heavily protected fort. It is surrounded by enormous walls which\n"+
              "protect it from surrounding dangers. You can see a huge castle rising behind the walls.\n"+
              "This fort seems to be very old, but it's still in very good condition. It must have been\n"+
              "built centuries ago. Whatever lived here before humans, made an everlasting fortress\n"+
              "There is also a sign standing at the front of the gate.\n";
  items = allocate(4);
  items[0] = "sign";
  items[1] = "Something is scribbled in the sign: Welcome to Dormund fellow traveler!";
  if(!present("guard")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/guard"), this_object());
  if(arg) { return; }
}
}