inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin 2")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area4/gremlin.c"),
    this_object());
}  

  if(arg) return;

  add_exit("down","/wizards/irmeli/area4/ruum8.c");
  add_exit("east","/wizards/irmeli/area4/ruum4.c");
  set_not_out(1);

  short_desc = "Inside the Orthanc, tower of death";
  long_desc = "This is the last corridor where the western-wing ends, it ends before it even\n"+
                "really started. Walls are getting closer and closer making you feel like\n"+
                "sardin in a can. A fusty air flows from the down, making you shiver \n"+   
                "with cold.\n";
}


