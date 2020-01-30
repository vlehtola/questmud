inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/8");
  /* setting desc */
  short_desc = "A small magic shop";
  long_desc = "This was once a flourishing magicshop. There wasn't a potion,\n"+
              "scroll or wand that you couldn't buy inhere. But now it isn't\n"+
              "so great anymore. The terrible war against Strakhard has drained\n"+
              "all stores of all magical equipment.\n";
}
