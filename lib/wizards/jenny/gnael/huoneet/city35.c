inherit "room/room";
object monster,monster2;
reset(arg) {
        
         if (!present("leila")) {
         move_object("wizards/jenny/gnael/mosut/leila.c", this_object());
        }

         if (!present("gard")) {
         move_object("wizards/jenny/gnael/mosut/gard.c", this_object());
        }

        if(arg) return;


        add_exit("west","/wizards/jenny/gnael/huoneet/city36.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city47.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city34.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing here that leads to three different\n"+
              "directions. In west you can see the west gate leading\n"+
              "outside the city, in north you can see a big building\n"+
              "and some shops and in east you can see the central\n"+
              "square.\n";
              
        items = allocate(6);
        items[0] = "central square";
        items[1] = "Central square is located a bit east from here";
        items[2] = "gate";
        items[3] = "A big gate is located a bit west from here";
        items[4] = "building";
        items[5] = "A big building is located in north";

}
