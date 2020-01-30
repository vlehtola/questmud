inherit "room/room";

object monster;



reset(arg) {

  if(!present("mummy")) {

    move_object(clone_object("/wizards/irmeli/area3/mummy.c"),

    this_object());

}

 

  if(arg) return;

 

  add_exit("east","/wizards/irmeli/area3/ruum59.c");

  add_exit("west","/wizards/irmeli/area3/ruum57.c");

  set_not_out(1);



  short_desc = "Low aisle deep in the huge temple";

  long_desc = "This aisle is lower than the earlier one probably because it's leading you\n"+

                "back under the ground. There are some paintings hanging from the wall\n"+

                "trying to make this aisle more domestic.\n";

}



