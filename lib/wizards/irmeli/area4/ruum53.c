inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),

    this_object());

}  



  if(arg) return;



  add_exit("south","/wizards/irmeli/area4/ruum54.c");

  add_exit("north","/wizards/irmeli/area4/ruum48.c");

  set_not_out(1);



  short_desc = "Floor six inside the Orthanc, tower of death";

  long_desc = "You are standing in a corridor, which leads to the south and north. The light\n"+

                "is probably enemy to lodgers of this tower because here aren't torches or\n"+

                "fireplaces to light up the tower. The air is getting thicker and heavier.\n"+

                "A huge pillar rises from the floor through the roof into sky.\n";

}

