inherit "room/room";

object monster;



reset(arg) {

  if(!present("mummy")) {

    move_object(clone_object("/wizards/irmeli/area3/mummy.c"),

    this_object());

}

 

  if(arg) return;

 

  add_exit("stairs","/wizards/irmeli/area3/ruum53.c");

  add_exit("east","/wizards/irmeli/area3/ruum51.c");

  set_not_out(1);



  short_desc = "Under the huge temple";

  long_desc = "You are now certain that you are right under the huge temple. There is\n"+

                "a stairs on the westernwall leading up to the temple. Small amount\n"+

                "light is coming from the top of the stairs.\n";

}



