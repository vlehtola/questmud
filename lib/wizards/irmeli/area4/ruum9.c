inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

}  



  if(arg) return;



  add_exit("east","/wizards/irmeli/area4/ruum10.c");

  add_exit("west","/wizards/irmeli/area4/ruum8.c");

  set_not_out(1);



  short_desc = "Inside the Dungeons of Orthanc, tower of death";

  long_desc = "A corridor leading to the main hall of this Dungeon. Corridors in here\n"+

                "are different than the floors above you, because these are under the\n"+

                "earth. This corridor looks like humans handwork, probably the humans\n"+   

                "were captured to the Dungeons, if the legend is true.\n";

}





