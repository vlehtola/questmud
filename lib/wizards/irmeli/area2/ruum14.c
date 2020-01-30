inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area2/ruum13.c");
  set_not_out(1);
  
  short_desc = "Dead end";
  long_desc = "Here has been a strong explosion because the roof and wall has collapsed.\n"+
                "It looks like somebody repaired this gallery a bit but not enough.\n"+
                "There are huge cracks on the ground.\n";   
 }
