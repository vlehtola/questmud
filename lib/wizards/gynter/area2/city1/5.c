inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/1");
  add_exit("south","/wizards/gynter/area2/city1/b");
  /* setting desc */
  short_desc = "The gateway to the Courtyard";
  long_desc = "This is the gateway to the courtyard. Once there was an emerald\n"+
              "embedded gate here but now after years of missfortune the king has\n"+
              "been forced to sell of more and more of the emerald until there\n"+
              "was none left. And now there isn't even a gate.\n";
}
