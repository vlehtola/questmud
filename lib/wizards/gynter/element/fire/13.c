inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/fire/12");
  add_exit("south","/wizards/gynter/element/fire/14");
  /* setting desc */
  short_desc = "A large hallway";
  long_desc = "You are standing in a large hallway.\n"+
              "The walls are made out of burning fires, and in the fires\n"+
              "there are scenes from battles fought ages ago.\n";
}
