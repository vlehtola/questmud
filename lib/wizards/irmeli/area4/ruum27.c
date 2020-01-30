inherit "room/room";  
object monster;
  
reset(arg) {
  if(!present("guard")) {
    move_object(clone_object("/wizards/irmeli/area4/guard2.c"),
    this_object());
}

if(arg) return;

  add_exit("west","/wizards/irmeli/area4/ruum28.c");

  add_exit("east","/wizards/irmeli/area4/ruum30.c");

  add_exit("up","/wizards/irmeli/area4/ruum34.c");

  add_exit("south","/wizards/irmeli/area4/ruum32.c");

  add_exit("down","/wizards/irmeli/area4/ruum20.c");

  set_not_out(1);



  short_desc = "Floor three inside the Orthanc, tower of death";

  long_desc = "You find your way in the floor three in a big hall, which is about thirty\n"+

                "feets above the surface of the earth. This hall is similar like the\n"+

                "two halls under you but you can feel some magic in the air. If you\n"+

                "fear the high places you need to go downwards, but if you are\n"+

                "enought brave you should continue.\n";

}

