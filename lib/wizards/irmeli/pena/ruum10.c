inherit "room/room";

reset(arg) {
  add_exit("south","/wizards/irmeli/pena/ruum33.c");
  add_exit("north","/wizards/irmeli/pena/ruum23.c");
  add_exit("west","/wizards/irmeli/pena/ruum20.c");
  add_exit("east","/wizards/irmeli/pena/ruum21.c");
  add_exit("northwest","/wizards/irmeli/pena/ruum22.c");
  add_exit("northeast","/wizards/irmeli/pena/ruum24.c");
 
  short_desc = "Huge field in the Valley of Angels";
  long_desc = "You have arrived to the begin of huge field. The ground is muddy and sandy.\n"+
                "There is some footprints left to the mud. Old corn or something like\n"+
                "that is smelling here.\n";   
}


