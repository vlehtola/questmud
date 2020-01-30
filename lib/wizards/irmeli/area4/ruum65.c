inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin8.c"),
    this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/irmeli/area4/ruum67.c");
  add_exit("north","/wizards/irmeli/area4/ruum63.c");
  set_not_out(1);

  short_desc = "On a balcony at the top of Orthanc, tower of death";
  long_desc = "You are standing on a balcony, which continues to the west and north. The\n"+
                "wind blows against your face with full speed, making your eyes wetty.\n"+
                "If you look up you can see someones dark figure making movements\n"+
                "at the top of the tower. \n";
}
