inherit "room/room";

reset(arg) { 

        add_exit("west","/wizards/jenny/gnael/huoneet/mansion2.c");
        add_exit("northwest","/wizards/jenny/gnael/huoneet/mansion3.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/mansion4.c");
        add_exit("northeast","/wizards/jenny/gnael/huoneet/mansion5.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/mansion6.c");
        add_exit("out","/wizards/jenny/gnael/huoneet/city11.c");

  short_desc = "Inside a huge mansion";
  long_desc = "You are inside a huge mansion, everywhere you look\n"+
              "you can see many valuable looking paintings, vases\n"+
              "and other stuff. A huge red carpet is on the floor\n"+
              "leading to a staircase in north which seems to be leading\n"+
              "into the second floor of the mansion. In west you can\n"+
              "see a small door leading into a beautiful garden.\n";

        items = allocate(12);
        items[0] = "paintings";
        items[1] = "These paintings are extremely gorgeous";
        items[2] = "vases";
        items[3] = "These vases look very old and fragile";
        items[4] = "carpet";
        items[5] = "A huge red carpet leading to the staircase";
        items[6] = "staircase";
        items[7] = "Staircase leading to the second floor";
        items[8] = "door";
        items[9] = "A wooden door";
        items[10] = "garden";
        items[11] = "A beautiful looking garden";
}
