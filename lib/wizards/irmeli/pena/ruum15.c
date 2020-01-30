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

  add_exit("east","/wizards/irmeli/pena/ruum16.c");
  add_exit("north","/wizards/irmeli/pena/ruum14.c");
  set_not_out(1);

  short_desc = "Tiny corridor inside a solid rock";
  long_desc = "This is a tiny corridor inside a solid rock. Some dark figures are moving\n"+
                "in the corner. There are few bones lying on the floor.\n";
}


