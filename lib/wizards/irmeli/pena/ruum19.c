inherit "room/room";
object monster;

reset(arg) {
  if(!present("crow")) { 
    move_object(clone_object("/wizards/irmeli/pena/crow.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("up","/wizards/irmeli/pena/ruum18.c");
  set_not_out(1);

  short_desc = "Room of the royal Crow";
  long_desc = "This is a huge room where the evil crow lives. The floor is made from gold.\n"+
                "There is lying lots of well-eaten corpses of humans and angels on the\n"+
                "golden floor.\n"; 
}

