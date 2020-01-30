inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/events/battle/battle3.c");
        add_exit("west","/wizards/jenny/events/battle/battle2.c");

  short_desc = "In the arena";
  long_desc = "You are in the war zone. Everywhere you look you see\n"+
              "corpses of mighty warriors and mages. You can smell the\n"+
              "blood of the fallen ones and you can hear the audience\n"+
              "cheering after every blow they see. Walls are surrounding\n"+
              "the battle zone so no one can escape from here.\n";

  property = allocate(1);
  property[0] = "no_summon";
  set_not_out(1);
  set_light(3);

}


init() {
  ::init();
  add_action("funkka","quit");
}

funkka() { 
write("You can't quit here!");
return 1; 
}
