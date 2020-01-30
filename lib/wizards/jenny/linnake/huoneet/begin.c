inherit "room/room";

reset(arg) {

        add_exit("enter","/wizards/jenny/linnake/huoneet/entrance.c");
        add_exit("south","out: 97 70");
        add_exit("southeast","out: 97 70");
        add_exit("east","out: 97 70");
        add_exit("northeast","out: 97 70");

  short_desc = "Outside the castle of Roxen";
  long_desc = "In front of you, there is a huge castle. Moat is circling\n"+
              "around the castle and there is an open leaf bridge\n"+
              "leading inside the castle. Some happy looking guards\n"+
              "are greeting everyone who cames in or goes out.\n"+
              "You can see four mighty towers raising from each\n"+
              "corner of the castle. Some druids are camping near\n"+
              "the castle walls and you hear music coming from inside\n";
}
