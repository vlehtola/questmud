inherit "room/room";
object mob, mob1;
reset(arg) {
  /* Applying mobs */
  if(!mob) {
    mob = clone_object("/wizards/gynter/darke/mobs/gate_guards");
    move_object(mob, this_object());
  }
  if (!mob1) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/gate_guards");
    move_object(mob1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/virtual/virtual_map: 32 20");
  add_exit("south","/wizards/gynter/darke/city/Wcity1");
  add_exit("west","/wizards/gynter/darke/city/bcity1");
  add_exit("east","/wizards/gynter/darke/city/bcity2");
  /* setting desc */
  short_desc = "The Entrance to the City";
  long_desc = "The entrance to the city is a huge room carved into\n"+
              "the rocks. The room is so big that you cannot see the roof.\n"+
              "This IS the city of the dark elfs.\n";
}
