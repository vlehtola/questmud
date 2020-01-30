inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("northeast","/wizards/gynter/element/water/2");
  add_exit("southwest","/wizards/gynter/element/water/9");
  /* setting desc */
  short_desc = "A vast ocean.";
  long_desc = "You are floating in a room filled with water. Strangely the\n"+
              "water is not affecting your movement in any way. The walls\n"+
              "are made out of some kind of underwater plant.\n";
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enough and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}
