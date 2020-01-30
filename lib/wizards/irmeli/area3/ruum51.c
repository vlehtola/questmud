inherit "room/room";  



reset(arg) {

  add_exit("west","/wizards/irmeli/area3/ruum52.c");

  add_exit("east","/wizards/irmeli/area3/ruum50.c");

  set_not_out(1);



  short_desc = "Small corridor under the ground";

  long_desc = "You are standing in the small corridor possibly under the huge temple.\n"+

                "Corridor is beaming a bit down to the darkness. Some raindrops is\n"+

                "dropping from the ceiling to the ground. Corridor is getting\n"+   

                "smaller with every step which you take into darkness.\n";

}





