inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/dark_mage");
    move_object(demon, this_object());
  }
  if(!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/dark_cleric");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/templen");
  /* setting desc */
  short_desc = "A small chamber";
  long_desc = "As you thread upon the floor in this chamber two shadows detaches\n"+
              "themselves from the wall and materializes infront of your eyes.\n"+
              "And you understand from where the grand mage gets his real power.\n";
}
