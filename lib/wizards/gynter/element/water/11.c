inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("northeast","/wizards/gynter/element/water/7");
  add_exit("west","/wizards/gynter/element/water/10");
  /* setting desc */
  short_desc = "A vast ocean.";
  long_desc = "You are floating in a room filled with water. The walls\n"+
              "are made out of some kind of underwater plant.\n"+
              "And they are as hard as steel.\n";
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enough and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}
