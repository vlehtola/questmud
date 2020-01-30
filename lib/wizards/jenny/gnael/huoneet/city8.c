inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/city7.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city9.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, some kids are\n"+
              "playing tag nearby and the city looks calm.\n"+
              "A huge mansion is rising towards the sky nearby\n"+
              "and there is a huge wall behind you. There\n"+
              "are some footprints leading towards the wall.\n";

 
        items = allocate(10);
        items[0] = "kids";
        items[1] = "Kids are giggling and playing tag nearby";
        items[2] = "mansion";
        items[3] = "A huge mansion is rising towards the sky nearby";
        items[4] = "wall";
        items[5] = "A huge city wall, there is a small hole in it";
        items[6] = "footprints";
        items[7] = "Some footprints are leading towards the wall";
        items[8] = "hole";
        items[9] = "There is a small hole on the wall";
}


init() {
  ::init(); 
  add_action("crawl", "crawl"); 
}

crawl(str) {
  if(str == "hole") {
    write("You crawl through a small hole!\n"); 
    say(this_player()->query_name()+" vanishes behind the wall!\n");
    this_player()->move_player("hole#/wizards/jenny/gnael/huoneet/hiddenhole.c");
     }
     return 1;
 }
