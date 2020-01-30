inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/s_shark");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/s_shark");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/s_shark");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/water/11");
  add_exit("northwest","/wizards/gynter/element/water/6");
  /* setting desc */
  short_desc = "A vast ocean.";
  long_desc = "You are floating in a room filled with water. Strangely the\n"+
              "water is not affecting your movement in any way. The walls\n"+
              "are made out of some kind of underwater plant. As you try to\n"+
              "break down a wall you discover that they are as hard as steel.\n";
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enough and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}
