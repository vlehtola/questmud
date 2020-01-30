inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),
    this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/irmeli/area4/ruum50.c");
  add_exit("east","/wizards/irmeli/area4/ruum48.c");
  set_not_out(1);

  short_desc = "Floor six inside the Orthanc, tower of death";
  long_desc = "A small corridor leading you to the western-wing in floor six. You can hear\n"+
                "the winds snarl outside the tower. Some rocks have dropped from the wall\n"+
                "because the wind used to blow with ultimate speed to this tower when the\n"+
                "evil force ruled in here. \n";
}
