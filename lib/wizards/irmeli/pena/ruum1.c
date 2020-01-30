inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angel.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angel.c"), 
    this_object());
}
  
  if(arg) return;

  add_exit("gates","/wizards/irmeli/pena/ruum2.c");
  add_exit("out","/wizards/irmeli/pena/entrance");
 
  short_desc = "The Gates to the Valley of Angels";
  long_desc = "You have arrived to the Valley of Angels. You can hear somebodys scream coming\n"+
                "from behind gates. There are some corpses and bones lying on the dusty\n"+
                "path. You can see some dark figures flying above you.\n";   

}


