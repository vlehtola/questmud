inherit "room/room";

reset(arg) {

        if(!present("bernard")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/bernard"), this_object());
        }
        if(!present("lizardman")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/ezz_dufzt"), this_object());
        }
        if (!present("sign")) {
         move_object(clone_object("wizards/jenny/gnael/rojut/sign"), this_object());
        }

        if(arg) return;

        add_exit("west","out: 79 128");
        add_exit("east","/wizards/jenny/gnael/huoneet/city1.c");

  short_desc = "Western gate";
  long_desc = "There is a huge gate in front of you,\n"+
              "people are coming and going from it\n"+
              "all the time. A small sign is on the\n"+
              "ground and some torches are burning near\n"+
              "the gate. Behind the gate lies the\n"+
              "large city of Gnael, where you see many kind\n"+
              "of people inside from human beggars to\n"+
              "lizardman nobles.\n";
        }
