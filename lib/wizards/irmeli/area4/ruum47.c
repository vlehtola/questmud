inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

}



  if(arg) return;



  add_exit("north","/wizards/irmeli/area4/ruum46.c");

  set_not_out(1);



  short_desc = "Floor five inside the Orthanc, tower of death";

  long_desc = "This is a really beatiful in this huge hall you don't even have words to\n"+

                "describe this place. If you look down you can see the floor one, two,\n"+

                "three and four under you. And if you look up you can see one floor\n"+

                "above you before the darkness hides the rest. Similar balcony as\n"+

                "in floors one, two, three and four goes round the place.\n";

}

