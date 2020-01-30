inherit "room/room";
object demon;
int quest_done=0;

reset(arg) {
  /* Applying mobs */
  if(!quest_done) {
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/airquest");
    move_object(demon, this_object());
  }
}
  if(arg) return;
  /* Assigning exits */
  add_exit("northeast","/wizards/gynter/element/air/14");
  add_exit("northwest","/wizards/gynter/element/air/12");
  add_exit("portal","/wizards/gynter/element/air/1");
  /* setting desc */
  short_desc = "The Air Lords dungeon";
  long_desc = "As you enter the room the first thing you notice is that here\n"+
              "you are standing in a real room. You can see the walls and all.\n"+
              "But all walls are transparent. It is as if the air has stopped\n"+
              "moving and become solid where the walls are supposed to be.\n";
  set_not_out(3);
  set_light(3);
}

quest_completed() {quest_done++; return; }
