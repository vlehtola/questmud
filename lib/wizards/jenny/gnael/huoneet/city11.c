inherit "room/room";
object monster,monster2;

reset(arg) { 
        
         if (!present("larf")) {
         move_object("wizards/jenny/gnael/mosut/larf_giant.c", this_object());
        }

         if (!present("garf")) {
         move_object("wizards/jenny/gnael/mosut/garf_giant.c", this_object());
        }

        if(arg) return;

        add_exit("west","/wizards/jenny/gnael/huoneet/city10.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city12.c");
        add_exit("mansion","/wizards/jenny/gnael/huoneet/mansion1.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street in the southwest part\n"+
              "of Gnael. A huge mansion is rising towards the sky\n"+
              "in front of you and a big door leading to the mansion is\n"+
              "open. Some voices can be heard from the mansion, but\n"+
              "everything seems calm. People are passing by all the\n"+
              "time and a small gust of wind is waving branches nearby.\n";

        items = allocate(6);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in front of you";
        items[2] = "door";
        items[3] = "A big iron door seems to be open";
        items[4] = "people";
        items[5] = "Loads of people are passing by all the time.";
}
