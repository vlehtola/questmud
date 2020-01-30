inherit "room/room";
object monster;
reset(arg) { 

        if (!present("man")) {
         move_object("wizards/jenny/gnael/mosut/man.c", this_object());
        }

        if(arg) return;

        add_exit("east","/wizards/jenny/gnael/huoneet/thief6.c");
        add_exit("up","/wizards/jenny/gnael/huoneet/thief3.c");

  short_desc = "In a basement";
  long_desc = "You are in a basement, there are no light sources\n"+
              "so it is difficult to see anything. The place is\n"+
              "very clean if you consider that it is a basement.\n"+
              "There are all kind of weapons stored in here and\n"+
              "many barrels are filled with arrows and spears and\n"+
              "other piece of equipment. The basement continues to\n"+
              "the east where you can see somekind of statue or something.\n";

        items = allocate(6);
        items[0] = "weapons";
        items[1] = "Many kind of weapons are stored in this basement";
        items[2] = "barrels";
        items[3] = "The barrels are full of arrows and spears";
        items[4] = "statue";
        items[5] = "There is an odd looking statue east from here";

}
