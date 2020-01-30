inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig4.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("north","/wizards/irmeli/pena/ruum22.c");
  add_exit("east","/wizards/irmeli/pena/ruum10.c");
  add_exit("northeast","/wizards/irmeli/pena/ruum23.c");
 
  short_desc = "Huge field in the Valley of Angels";
  long_desc = "You are walking on the huge field. The ground is wet and when you step\n"+
                "on the mud you can see your footprints on it. Old corn is smelling\n"+
                "strongly here.\n";   
}


