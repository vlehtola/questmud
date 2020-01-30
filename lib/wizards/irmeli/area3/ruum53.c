inherit "room/room";

object monster;



reset(arg) {

  if(!present("mummy")) {

    move_object(clone_object("/wizards/irmeli/area3/mummy.c"),

    this_object());

}

 

  if(arg) return;

 

  add_exit("west","/wizards/irmeli/area3/ruum54.c");

  add_exit("east","/wizards/irmeli/area3/ruum57.c");

  add_exit("north","/wizards/irmeli/area3/ruum60.c");

  add_exit("down","/wizards/irmeli/area3/ruum52.c");

  set_not_out(1);



  short_desc = "Central hall in the huge temple";

  long_desc = "Welcome to the central hall in this huge and beatiful temple. This temple\n"+

                "has made hundreds years ago with old-fashion way. There is a big cross\n"+

                "on the wall remembering you from the suffer of jesus.\n";

}



