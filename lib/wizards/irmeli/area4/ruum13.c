inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

}  



  if(arg) return;



  add_exit("north","/wizards/irmeli/area4/ruum11.c");

  set_not_out(1);



  short_desc = "Inside the Dungeons of Orthanc, tower of death";

  long_desc = "You have entered to the prison cage of the killers. This is a bit bigger\n"+

                "than the cages of the rapers and thiefs but still this isen't domestic.\n"+

                "There is a small stocks next to the western wall. If the prisoner were\n"+   

                "angry, it tied to the stocks and released when it was calm.\n";

}





