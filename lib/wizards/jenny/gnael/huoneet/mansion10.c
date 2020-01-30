inherit "room/room";
object monster;

reset(arg) { 

  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/amanda.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("south","/wizards/jenny/gnael/huoneet/mansion9.c");
       
  short_desc = "A small room";
  long_desc = "You have entered a small, cosy looking room. There\n"+
              "is a beautiful brown carpet on the floor and some\n"+
              "weird looking paintings are hanged on the walls.\n"+
              "A fluffy looking bed with beautiful decorations is\n"+
              "placed in the corner and there is a small desk next\n"+
              "to the bed.\n";

        items = allocate(8);
        items[0] = "carpet";
        items[1] = "A beautiful brown carpet is filling the floor";
        items[2] = "paintings";
        items[3] = "Some weird looking paintings are hanged on the walls";
        items[4] = "bed";
        items[5] = "A very comfortable looking bed is in the corner of the room";
        items[6] = "desk";
        items[7] = "A small wooden desk is placed next to bed";
}
