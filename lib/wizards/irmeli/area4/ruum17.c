inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),
    this_object());
}  

  if(arg) return;

  add_exit("east","/wizards/irmeli/area4/ruum15.c");
  add_exit("west","/wizards/irmeli/area4/ruum16.c");
  set_not_out(1);

  short_desc = "Inside the Dungeons of Orthanc, tower of death";
  long_desc = "You are standing in a small prison cage, which belongs to thiefs and rapers.\n"+
                "This prison cage is in the middle of these three cages but this aren't\n"+
                "similar like the two another ones. Here is no chains hanging from\n"+   
                "the ceiling, but here is a big table covered with blood. They meaby\n"+
                "used this prison cage to torture prisons. Meaby they called this\n"+
                "prison cage to the torture chamber.\n";
}

