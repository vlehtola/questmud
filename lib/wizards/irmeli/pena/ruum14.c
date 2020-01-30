inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig3.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig3.c"), 
    this_object());
}
  
  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum15.c");
  add_exit("north","/wizards/irmeli/pena/ruum13.c");
  set_not_out(1);

  short_desc = "Tiny corridor inside solid rock";
  long_desc = "This is a tiny corridor inside solid rock. Some dark figures are flying\n"+
                "above you. There are lots of corpses and blood on the floor.\n";
                   
}


