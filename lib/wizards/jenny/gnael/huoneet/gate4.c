inherit "room/room";

reset(arg) {

        if(!present("nadia")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/nadia"), this_object());
        }
        if(!present("giant")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/uglah"), this_object());
        }
        if (!present("sign")) {
         move_object(clone_object("wizards/jenny/gnael/rojut/sign"), this_object());
        }

        if(arg) return;

        add_exit("south","out: 80 129");
        add_exit("north","/wizards/jenny/gnael/huoneet/city14.c");

  short_desc = "Southern gate";
  long_desc = "There is a huge gate in front of you,\n"+
              "people are coming and going from it\n"+
              "all the time. A small sign is on the\n"+
              "ground and some torches are burning near\n"+
              "the gate. Behind the gate lies the\n"+
              "large city of Gnael. You see a large\n"+
              "mansion rising towards the sky near the\n"+
              "gate, but afterall the city looks peaceful\n"+
              "and calm.\n";
        }
