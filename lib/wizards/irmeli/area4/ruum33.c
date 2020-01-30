inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin 2")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin4.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area4/gremlin4.c"),
    this_object());
}

  if(arg) return;

  add_exit("north","/wizards/irmeli/area4/ruum32.c");
  set_not_out(1);

  short_desc = "Floor three inside the Orthanc, tower of death";
  long_desc = "This is a really beatiful in this huge hall you don't even have words to\n"+
                "describe this place. If you look down you can see the floor one and two\n"+
                "under you. And if you look up you can see about three floors above you\n"+
                "before the darkness hides the rest. Similar balcony as in floor two\n"+
                "goes round the place.\n";
}
