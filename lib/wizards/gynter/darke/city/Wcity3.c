inherit "room/room";

object mob, mob1;
reset(arg) {


  /* Applying mobs */
  if(!mob && !random(3)) {
    mob = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob, this_object());
  }
  if(!mob1 && !random(3)) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Wcity2");
  add_exit("south","/wizards/gynter/darke/city/Wcity4");
  /* setting desc */
   add_exit("east","/wizards/gynter/darke/city/gcity6");
  add_exit("west","/wizards/gynter/darke/city/gcity5");
  short_desc = "The new walk to the city";
  long_desc = "As you walk down the road you notice that this\n"+
              "road is newly build. And down the road you see\n"+
              "part of the city. It looks like noumerous large\n"+
              "boulders with holes in them.\n";
}
