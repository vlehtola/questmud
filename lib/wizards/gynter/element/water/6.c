inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/m_shark");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("southeast","/wizards/gynter/element/water/10");
  add_exit("northwest","/wizards/gynter/element/water/2");
  /* setting desc */
  short_desc = "A vast ocean.";
  long_desc = "The walls are made out of some kind of underwater plant.\n"+
              "The ceiling and floor is made out of some mixture between\n"+
              "fast running water and still water.\n";
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enough and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}
