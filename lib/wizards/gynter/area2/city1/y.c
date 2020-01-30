inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/gate_guard");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/gate_guard");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/x");
  add_exit("out","/wizards/gynter/workroom");
  /* setting desc */
  short_desc = "The Southern Gate";
  long_desc = "This is the only entrence to Strakhad.\n"+
              "It is always guarded closely since the city is at\n"+
              "war with the magecity of Therheran.\n";
}
