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
  
  add_exit("east","/wizards/irmeli/area4/ruum42.c");
  set_not_out(1);

  short_desc = "Floor five inside the Orthanc, tower of death";
  long_desc = "You are now at western-wing on floor five, but unfortunately there is only\n"+
                "one exit and it's backwards. The floor looks a bit flimsy and slippery\n"+
                "like someone has just polished it. A black and rusty iron-chains is\n"+
                "hanging from the roof with some poor skeleton in chains.\n";
}
