inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

}  



  if(arg) return;

  

  add_exit("west","/wizards/irmeli/area4/ruum44.c");

  set_not_out(1);



  short_desc = "Floor five inside the Orthanc, tower of death";

  long_desc = "You are now at eastern-wing on floor five, but unfortunately there is only\n"+

                "one exit and it's backwards. The evil force lived in this tower but now\n"+

                "it has moved away or died. There is a marks from a big fight all around\n"+

                "this tower especially in this room. Old blood smells strongly in here.\n";

}

