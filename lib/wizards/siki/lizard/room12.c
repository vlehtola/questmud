inherit "room/room";

reset(arg) {


  add_exit("east","/wizards/siki/lizard/room5");
  add_exit("south","/wizards/siki/lizard/room13");
  add_exit("north","/wizards/siki/lizard/room11");
  add_exit("enter","/wizards/siki/lizard/hut4");

  short_desc = "Outside of a tiny straw hut";
  long_desc = "A tiny hut made out of straws is located west from you.\n"+
              "The ground is tough and damp. Humidity of this place\n"+
              "makes you feel uncomfortable.\n";
}

