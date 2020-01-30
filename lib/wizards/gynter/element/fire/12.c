inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/fire/11");
  add_exit("south","/wizards/gynter/element/fire/13");
  /* setting desc */
  short_desc = "A large hallway";
  long_desc = "You are standing in a large hallway.\n"+
              "This is the hall of the everlasting battles. Every wall\n"+
              "has its battle to talk about and in ever wall there is a\n"+
              "new battle being displayed.\n";
}
