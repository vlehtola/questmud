inherit "room/room";
object demon;
int quest_done=0;

reset(arg) {
  /* Applying mobs */
  if(!quest_done) {
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/earthquest");
    move_object(demon, this_object());
  }
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/15");
  add_exit("west","/wizards/gynter/element/earth/13");
  add_exit("north","/wizards/gynter/element/earth/11");
  /* setting desc */
  short_desc = "A small pond";
  long_desc = "In the middle of this small room there is a pond full of dust.\n"+
              "The water moves as if it is would be water. And yet it's dust.\n";
  /* setting features */
  set_light(1);
}

quest_completed() { quest_done++; return; }
