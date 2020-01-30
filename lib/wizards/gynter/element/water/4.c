inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("southeast","/wizards/gynter/element/water/8");
  add_exit("northwest","/wizards/gynter/element/water/1");
  /* setting desc */
  short_desc = "A vast ocean.";
  long_desc = "You are floating in a room filled with water. The walls\n"+
              "are made out of some kind of underwater plant. Strangely the\n"+
              "water is not affecting your movement in any way.\n";
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enought and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}
