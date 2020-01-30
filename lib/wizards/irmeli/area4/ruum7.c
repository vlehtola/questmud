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

  add_exit("west","/wizards/irmeli/area4/ruum6.c");
  set_not_out(1);

  short_desc = "Inside the Orthanc, tower of death";
  long_desc = "This is the last corridor where the eastern-wing ends, it ends before it even\n"+
                "really started. Walls are getting closer and closer making you feel like\n"+
                "sardin in a can. There is nothing strange in this corridor, except\n"+   
                "the air, which is fusty and cold.\n";
}


