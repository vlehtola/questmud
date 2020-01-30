inherit "room/room";


object monster,monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/seagull");
    move_object(monster, this_object());
  if(!monster2) { 
    monster2 = clone_object("/wizards/veron/areat/golem/mobs/seagull");
    move_object(monster2, this_object());

}}


add_exit("south","/wizards/veron/areat/golem/torni2.c");





  short_desc = "Balcony";

  long_desc = "A small balcony high above the ground level. You can hear the \n"+
              "seagulls scream over the sea, which can be seen here. Huge \n"+
              "waves hit the shore with roaring sound. The sight is very \n"+
              "relaxing. A small wooden chair is placed on the balcony. A\n"+
              "metallic rail ensures the safety here. A bucket full of seeds\n"+
              "can be seen hanging from the rail. Bird excrement paints the\n"+
              "balcony white.\n";
		  
  items = allocate(6);
  items[0] = "bucket";
  items[1] = "A metallic bucket full of seeds. They're probably for the birds";
  items[2] = "chair";
  items[3] = "A small wooden chair. You would like to sit in the chair and just enjoy the view";
  items[4] = "rail";
  items[5] = "A metallic rail has been built around the balcony, preventing people from falling down";

 
		
  }