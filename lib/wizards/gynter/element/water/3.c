inherit "room/room";
object demon;
int quest_done=0;

reset(arg) {
  /* Applying mobs */
  if(!quest_done) {
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/waterquest");
    move_object(demon, this_object());
  }
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("southwest","/wizards/gynter/element/water/7");
  /* setting desc */
  short_desc = "A vast room surrounded by pearls";
  long_desc = "You are standing in a vast room that has walls that are made out\n"+
              "of pearls. The floor and ceiling are made out of the skin from\n"+
              "races that lives on the dry land.\n";
}
init() {
  ::init();
  if(this_player()->query_npc()) return;
  if(this_player()->query_dex() < random(100)) {
    write("You are not agile enough and swallow some water!\n");
    this_player()->hit_with_spell(50);
  }
}

quest_completed() {quest_done++; return; }
