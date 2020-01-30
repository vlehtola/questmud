inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin5.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin5.c"),

    this_object());

}



  if(arg) return;



  add_exit("north","/wizards/irmeli/area4/ruum39.c");

  set_not_out(1);



  short_desc = "Floor four inside the Orthanc, tower of death";

  long_desc = "This is a really beatiful in this huge hall you don't even have words to\n"+

                "describe this place. If you look down you can see the floor one, two\n"+

                "and three under you. And if you look up you can see two floors above\n"+

                "you before the darkness hides the rest. Similar balcony as in floor\n"+

                "two and three goes round the place.\n";

}

