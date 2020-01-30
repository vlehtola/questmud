inherit "room/room";


   reset(arg) {
      if(arg) return;

  add_exit("north","/wizards/siki/troll/f01");
  add_exit("east","out: 148 51");
  add_exit("south","out: 148 51");
  add_exit("west","out: 148 51");

  short_desc = "Great forest";
  long_desc = "You are walking in a forest, where huge trees are towering high\n"+
              "above your head. There are very little undergrowth but some\n"+
              "large stones and bushes. A small path leads deeper in the dense\n"+
              "forest in the north.\n";
         

}
