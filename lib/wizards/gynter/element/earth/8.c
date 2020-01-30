inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/granit_giant");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/9");
  add_exit("south","/wizards/gynter/element/earth/1");
  add_exit("west","/wizards/gynter/element/earth/7");
  add_exit("north","/wizards/gynter/element/earth/4");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "Everything inhere is made out of some kind of stone.\n"+
              "And the most remarkable thing is that there are tunnels\n"+
              "leading in every direction out of here, and some are so small\n"+
              "only a baby would fit through them.\n";
  /* setting features */
  set_light(1);
}
