inherit "room/room";
object mob;
reset(arg) {
  /* Applying mobs */
  if(!mob) {
    mob = clone_object("/wizards/gynter/darke/mobs/big_guard");
    move_object(mob, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/darke/city/Ecity");
  /* setting desc */
  short_desc = "The Captains of the guards";
  long_desc = "This room usually holds one of the two captains.\n"+
              "When a guard goes on duty this is where they report in.\n"+
              "And when problems occur, this is where it ends.\n"+
              "Perhaps that is why there is blood on the walls?\n";
}
