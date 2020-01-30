inherit "room/room";

reset(arg) {
  if(arg) { return; } 

  add_exit("out", "/wizards/torspo/areat/ogre/room8.c");
  set_not_out(1);
  set_light(2);

  short_desc = "Cave shaped by the nature";
  long_desc = "A dark and damp cave, shaped by the nature. The nature has shaped the bottom,\n"+
              "walls and the ceiling of the cave. Cold and translucid water covers the\n"+ 
              "bottom of the cave. Some small stalagmites are hanging from the ceiling.\n"+
              "Here and there, under the translucid water, the bottom of the cave is\n"+
              "covered with mud. Among the mud, shines white piles of bone, bones of\n"+
              "small fishes. The sound of pouring water echoes around the cave. A small,\n"+
              "altar-looking tray is hidden among the mud.\n";

  items = allocate(2);
  items[0] = "tray";
  items[1] = "An underwater tray, carved into the hard stone base. It looks dirty and has some mud on it";
}

 init() {
  ::init();
  add_action("sacrifice", "sacrifice");
 }

sacrifice(str) {
   if(str == "salmon" || str == "fish") {
    if(present("salmon", this_player())) {
     object ob;
     ob = present("salmon" ,this_player());
     destruct(ob);
     write("You place the salmon on the tray and make a mystical sacrifice.\n"+
           "Huge crab rises among the mud!\n");
     say(this_player()->query_name()+ " places salmon on the tray and sacrifices it.\n");
     move_object(clone_object("/wizards/torspo/areat/ogre/monsters/crab.c"), this_object());
     write("You have completed the 'Find the ancient crab' quest\n");
     this_player()->set_quest("Find the ancient crab");
     return 1;
     }
     write("You don't have one.\n");
     return 1;
    }
  write("What do you want to sacrifice?\n");
  return 1;
}
