inherit "room/room";

reset(arg) {
        if(arg) return;

  add_exit("north","/wizards/grizzt/tower/inneralcove");
  add_exit("out","/wizards/grizzt/workroom");

  set_not_out(1);
  
  short_desc = "Inside the tower";
  long_desc = "This seems like the entrance into an old tower. The floor \n"+
              "looks like has not been used for some time. There is dust \n"+
              "everywhere and only visible signs of living are the numerous \n"+
              "footprints of rats. The walls seem to be made of huge boulders \n"+
              "with no plaster used to bind them together. The dust reveals the \n"+
              "original material of the floor, which seems to be somekind of stone \n"+
              "too. There is an opening towards the inner parts \n"+
              "of the tower leading northwards. \n";


  items = allocate(4);
  items[0] = "walls";
  items[1] = "The walls are made of huge boulders without any plaster.";
  items[2] = "floor";
  items[3] = "The floor is covered in dust. Some small rat footprints run across it.";
  
        set_sound(35+random(7),"The dust tickles your nose and you sneeze.\n");
        set_sound(40+random(3),"A rat scurries over the floor.\n");
  

}