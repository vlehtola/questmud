inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/well11.c");

    short_desc = "Inside the well";
    long_desc = "You are walking in a gloomy looking dungeon\n"+
              "inside the city well. The place is very wet and there\n"+
              "are many spider webs everywhere, walls are made of some\n"+
              "unknown dark material and there are no visible light sources\n"+
              "anywhere near. You can hear some horrible screams coming\n"+
              "from somewhere near. The dungeon ends here, but there is a\n"+
              "statue of Mondasa placed in the dead end.\n";

 
        items = allocate(6);
        items[0] = "webs";
        items[1] = "Terrible looking spider webs are covering almost everything here";
        items[2] = "walls";
        items[3] = "These walls look abnormal, they surely are not from this world";
        items[4] = "statue";
        items[5] = "There is a small button on the statue";

}


init() {
  ::init(); 
  add_action("press", "press"); 
}

press(str) {
  if(str == "button") {
    write("You press the button and the wall moves aside revealing an exit\n"); 
    say(this_player()->query_name()+" presses the button and the wall moves aside revealing an exit\n");
    add_exit("south","/wizards/jenny/gnael/huoneet/well13.c");
    command("look",this_player());
     }
     return 1;
 }
