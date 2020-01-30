inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/city50.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city52.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city48.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, you are in a crossing\n"+
              "that leads to three different directions. Somewhat ahead,\n"+
              "you see a few shops and a big building is standing next\n"+
              "to you in the west and there is a small wooden door on the building.\n"+
              "Far south you can see a huge mansion rising towards the sky\n"+
              "and you can see the roof of mayor's house in the east.\n";
 
        items = allocate(12);
        items[0] = "crossing";
        items[1] = "The crossing leads to three different directions";
        items[2] = "shops";
        items[3] = "You can see a few shops in north";
        items[4] = "building";
        items[5] = "A big building is standing next to you";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky in south";
        items[8] = "roof";
        items[9] = "Far away in east you can see the roof of mayor's house";
        items[10] = "door";
        items[11] = "Only one small door in a big building like that, weird..";

}


init() {
  ::init(); 
  add_action("knock", "knock"); 
}

knock(str) {
  if(str == "door three times") {
    write("You knock the door three times and a man lets you in!\n"); 
    say(this_player()->query_name()+" knocks the door and leaves inside!\n");
    this_player()->move_player("building#/wizards/jenny/gnael/huoneet/thief1.c");
     }
     return 1;
 }
