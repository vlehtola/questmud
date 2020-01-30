inherit "room/room";
object monster;

reset(arg) { 

         if (!present("geremod")) {
         move_object("wizards/jenny/gnael/mosut/geremod.c", this_object());
        }

        if(arg) return;


        add_exit("north","/wizards/jenny/gnael/huoneet/mansion14.c");
        add_exit("down","/wizards/jenny/gnael/huoneet/mansion16.c");

  short_desc = "The second floor of the mansion";
  long_desc = "The second floor of the mansion looks bit different,\n"+
              "you can't see any kind of valuable decorations here..\n"+
              "Actually this floor looks pretty poor. Some candles are\n"+
              "giving some light to the hallway. You hear a crying\n"+
              "voice coming from north, but you can't hear what the\n"+
              "person is crying for. There is a staircase leading down\n"+
              "here.\n";

        items = allocate(4);
        items[0] = "candles";
        items[1] = "A few candles are burning on the wall";
        items[2] = "staircase";
        items[3] = "A staircase leading to basements";
}
