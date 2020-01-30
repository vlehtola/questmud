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
  add_exit("southeast","/wizards/gynter/element/water/6");
  add_exit("southwest","/wizards/gynter/element/water/5");
  /* setting desc */
  short_desc = "A shore.";

  long_desc="This is the only spot of dry lands that you can seem to find\n"+
              "When you start to make it back to the water you see some strange\n"+
              "letters floating on the water next to the shore..  ...pi.\n";
}

init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enough and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}
