inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/t_shark");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("southeast","/wizards/gynter/element/water/4");
  add_exit("out","/wizards/gynter/element/gateway");
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
