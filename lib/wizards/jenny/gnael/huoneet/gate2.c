inherit "room/room";

reset(arg) {

        if(!present("kern")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/kern"), this_object());
        }
        if(!present("dwarf")) {
           move_object(clone_object("/wizards/jenny/gnael/mosut/glonk"), this_object());
        }
        if (!present("sign")) {
         move_object(clone_object("wizards/jenny/gnael/rojut/sign"), this_object());
        }

        if(arg) return;

        add_exit("north","out: 80 127");
        add_exit("south","/wizards/jenny/gnael/huoneet/city42.c");

  short_desc = "Northern gate";
  long_desc = "There is a huge gate in front of you,\n"+
              "people are coming and going from it\n"+
              "all the time. A small sign is on the\n"+
              "ground and some torches are burning near\n"+
              "the gate. Behind the gate lies the\n"+
              "large city of Gnael. A long road is starting\n"+
              "inside the city and it seems to lead\n"+
              "to the central square of the city.\n";
        }
