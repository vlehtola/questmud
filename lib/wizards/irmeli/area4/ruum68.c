inherit "room/room";



reset(arg) {

  add_exit("west","/wizards/irmeli/area4/ruum66.c");

  add_exit("east","/wizards/irmeli/area4/ruum67.c");



  short_desc = "On a balcony at the top of the Orthanc, tower of death";

  long_desc = "You are standing on a balcony, which is made from wood. It goes round the\n"+

              "tower. There are exits to east and west, if you want to take sightseeing\n"+

              "around the tower. On the northern wall is some strange holes.\n";



  items = allocate(4);

  items[0] = "wall";

  items[1] = "You are looking the northern wall. There is some holes starting from down here to the top of the tower";

  items[2] = "holes";

  items[3] = "A holes, which were used to climb up to the top of this tower";

}



init() {

  ::init(); 

  add_action("climb", "climb");

}



climb(str) {

  if(str == "up") {

    write("You start climbing up to the top of this tower.\n"); 

    this_player()->move_player("up to the top of this tower","/wizards/irmeli/area4/ruum69.c");

    this_player()->set_quest("Tower_Orthanc_holes", 2);

    return 1; 

}

    write("What?\n");

    return 1;

}



