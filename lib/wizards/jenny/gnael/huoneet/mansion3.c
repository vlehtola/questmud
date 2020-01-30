inherit "room/room";
object monster;

reset(arg) { 

        add_exit("east","/wizards/jenny/gnael/huoneet/mansion4.c");
        add_exit("southeast","/wizards/jenny/gnael/huoneet/mansion1.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/mansion2.c");
        add_exit("garden","/wizards/jenny/gnael/huoneet/garden1.c");
       
  short_desc = "Inside a huge mansion";
  long_desc = "You are inside a huge mansion, everywhere you look\n"+
              "you can see many valuable looking paintings, vases\n"+
              "and other stuff. A huge red carpet is on the floor\n"+
              "leading to a staircase in north which seems to be leading\n"+
              "into the second floor of the mansion. There is a small door\n"+
              "ahead of you and you can see the garden when you look\n"+
              "through it.\n";

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
