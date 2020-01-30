inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 1")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig3.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("north","/wizards/irmeli/pena/ruum16.c");
  add_exit("south","/wizards/irmeli/pena/ruum18.c");
  set_not_out(1);

  short_desc = "Tiny corridor leading you down under the surface";
  long_desc = "This corridor is smaller than you have ever seen. You notice that\n"+
                "as more south you go the smaller corridors you see. Meaby you\n"+
                "should go backwards.\n"; 
}


