inherit "room/room";
object monster,well;

reset(arg) {

  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/human_noble.c");
    move_object(monster, this_object());
   }

  if(!well) {
    well = clone_object("/wizards/jenny/gnael/rojut/well.c");
    move_object(well, this_object());
   }

        if(arg) return;

        add_exit("west","/wizards/jenny/gnael/huoneet/city33.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city37.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city30.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city32.c");

  short_desc = "The Central Square";
  long_desc = "You have arrived to the central square of the\n"+
              "city of Gnael. You can see the whole city\n"+
              "from here. In northwest and southeast you\n"+
              "see shops and other buildings, in northeast\n"+
              "you see the mayor's house which is the second\n"+
              "biggest building in Gnael. In southwest you\n"+
              "see a huge mansion rising towards the sky, it\n"+
              "is definitely the biggest building in Gnael.\n"+
              "There is also a sign by the well here.\n";

        items = allocate(10);
        items[0] = "shops";
        items[1] = "People are constantly running in shops of Gnael";
        items[2] = "buildings";
        items[3] = "Many different kind of buildings can be seen everywhere you look";
        items[4] = "house";
        items[5] = "The mayor's house is in northeast part of the city";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky in southwest";
        items[8] = "sign";
        items[9] = "Warning! Don't EVER swim or dive in this well!";

}

init() {
  ::init(); 
  add_action("dive", "dive"); 
}

dive(str) {
  if(str == "into well") {
    write("You dive into the well and find a secret exit inside the well!\n"); 
    say(this_player()->query_name()+" dives into the well and vanishes!\n");
    this_player()->move_player("well#/wizards/jenny/gnael/huoneet/well1.c");
     }
     return 1;


        }
