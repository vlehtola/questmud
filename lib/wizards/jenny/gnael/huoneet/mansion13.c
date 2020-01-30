inherit "room/room";

reset(arg) { 

        add_exit("west","/wizards/jenny/gnael/huoneet/mansion14.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/mansion12.c");
       
  short_desc = "The second floor of the mansion";
  long_desc = "The second floor of the mansion looks bit different,\n"+
              "you can't see any kind of valuable decorations here..\n"+
              "Actually this floor looks pretty poor. Some candles are\n"+
              "giving some light to the hallway. You hear a crying\n"+
              "voice somewhere, but you can't hear what the\n"+
              "person is crying for.\n";

        items = allocate(2);
        items[0] = "candles";
        items[1] = "A few candles are burning on the wall";
}
