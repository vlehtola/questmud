inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin 2")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin3.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area4/gremlin3.c"),
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area4/ruum25.c");
  set_not_out(1);

  short_desc = "Floor two inside the Orthanc, tower of death";
  long_desc = "Whoa it's really beatiful in this huge hall, you don't even have words to\n"+
                "describe this place. If you look down, you can see the floor one about\n"+
                "twenty feets below you. And if you look up you can see about four\n"+
                "floors above you before the darkness hides the rest. The balcony\n"+ 
                "made from wook goes round the place.\n"; 
}
