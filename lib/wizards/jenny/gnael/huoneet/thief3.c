inherit "room/room";

reset(arg) { 

        add_exit("north","/wizards/jenny/gnael/huoneet/thief4.c");
        add_exit("northeast","/wizards/jenny/gnael/huoneet/thief1.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/thief2.c");
        add_exit("down","/wizards/jenny/gnael/huoneet/thief5.c");

  short_desc = "Inside a big building";
  long_desc = "You are inside a dark room. Everywhere you look\n"+
              "you see hostile eyes looking right back at you.\n"+
              "There is a small text on the wall that says\n"+
              "'Thiefs & Assassins only'. You don't feel very\n"+
              "welcomed here. There isn't much furniture in\n"+
              "here, only a big table and a few chairs in the middle\n"+
              "the room and some weapons are hanging on the walls.\n"+
              "A staircase leading downstairs is located in here\n";

        items = allocate(12);
        items[0] = "text";
        items[1] = "Thiefs & Assassins only";
        items[2] = "table";
        items[3] = "There are some papers on the table";
        items[4] = "papers";
        items[5] = "Someone says: 'Don't you look at my plans!'";
        items[6] = "chairs";
        items[7] = "Strong looking wooden chairs are surrounding the table";
        items[8] = "weapons";
        items[9] = "Swords,axes,polearms,bludgeons,daggers,bows..there seems to be everything";
        items[10] = "staircase";
        items[11] = "A staircase leading downstairs";

}
