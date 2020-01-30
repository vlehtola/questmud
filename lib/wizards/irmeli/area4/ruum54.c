inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),

    this_object());

}



  if(arg) return;



  add_exit("north","/wizards/irmeli/area4/ruum53.c");

  set_not_out(1);



  short_desc = "Floor six inside the Orthanc, tower of death";

  long_desc = "You have arrived at huge hall in the top of tower. Small amount light and\n"+

                "fresh air comes from the hole in the roof. If you look down you can see\n"+

                "the floors one, two, three, four and five under you. Similar balcony as\n"+

                "in floors one, two, three, four and five goes round the place.\n";

}

