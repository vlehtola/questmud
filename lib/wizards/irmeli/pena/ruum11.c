inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"), 
    this_object());
}
  
  if(arg) return;

  add_exit("north","/wizards/irmeli/pena/ruum9.c");
  add_exit("west","/wizards/irmeli/pena/ruum12.c");
  set_not_out(1);

  short_desc = "Small corridor under the surface of the earth";
  long_desc = "This is a small corridor leading you deep under the surface of the earth.\n"+
                "You notice that the floor is covered by water. You can hear some\n"+
                "noises coming from western corridor.\n";   
}

 

