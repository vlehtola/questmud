inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/archmage");
    move_object(demon, this_object());
  }
  if(!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/archmage");
    move_object(demon1, this_object());
  }
  if(!demon2) {
    demon2 = clone_object("/wizards/gynter/area2/city2/mobs/grandmage");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/templej");
  /* setting desc */
  short_desc = "The holy ones chamber";
  long_desc = "This is the chambers of the Grand mage! In here the walls show\n"+
              "nothing but death, your death.\n";
}

init() {
  ::init();
  if(this_player()->query_quests("Therheran, Killed king"))
    add_exit("south","/wizards/gynter/area2/city2/templeo.c");
}
