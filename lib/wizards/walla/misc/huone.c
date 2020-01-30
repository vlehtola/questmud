inherit "room/room"; 
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/avanil/monsters/awnshegh");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","/wizards/walla/avanil/mountains/spiderfell/6");
  short_desc = "At the end of the spiderfell";
  long_desc =
"The spiderfell has come to a sudden end. It has stopped, and it is in\n" +
"no way to go further. You can see a small hole up high in the air.\n" +
"From it, you can see the real world, not just the underworld.\n" +
 "A sort of spiderweb covers the wall, but it seems to be very strong\n"  
+
"in its fabric. It leads all the way up to the opening.\n";
 
  items = allocate(4);
  items[0] = "web";
  items[1] = "A spiderweb covering the wall. Could you climb it ?";
 
}
init() {
  ::init();
  add_action("dig", "dig");
}
 
dig(str) {
  ifpresent("shovel", this_player());
write("You start climbing up the web.\n");
say("Someone climbs up the web.\n");                  
  move_object(this_player(), "/wizards/walla/avanil/mountains/3");
  return 1;
}

