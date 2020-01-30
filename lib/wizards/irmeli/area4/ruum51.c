inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),
    this_object());
}  

  if(arg) return;

  add_exit("east","/wizards/irmeli/area4/ruum52.c");
  add_exit("west","/wizards/irmeli/area4/ruum48.c");
  set_not_out(1);

  short_desc = "Floor six inside the Orthanc, tower of death";
  long_desc = "A small corridor leading you to the eastern-wing in floor five. The floor is\n"+
                "covered with old blood and sand. The roof is lower down than in earlier\n"+
                "rooms. And the walls are slanted from power of nature or result of \n"+
                "builders urgent deadline.\n";
}
