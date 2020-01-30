inherit "room/room";
object demon;
int quest_done=0;

reset(arg) {
  /* Applying mobs */
  if (!quest_done) {
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/firequest");
    move_object(demon, this_object());
  }
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("southeast","/wizards/gynter/element/fire/14");
  /* setting desc */
  short_desc = "The fire pit";
  long_desc = "This is the room of one of the fire lords.\n"+
              "It is built from hot burning flames the same\n"+
              "color as newly fallen snow.\n";
}

quest_completed() { quest_done++; return; }
