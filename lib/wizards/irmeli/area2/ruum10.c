inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 1")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area2/ruum11.c");
  add_exit("north","/wizards/irmeli/area2/ruum9.c");
  set_not_out(1);
  
  short_desc = "Tiny gallery in the second level";
  long_desc = "This tiny gallery collapsed totally in the explosion. It was rebuilt in a\n"+
                "hurry and therefore there are some cracks on the wall. There is water\n"+
                "coming from the cracks.\n";   
 }
