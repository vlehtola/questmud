inherit "room/room";
object mob, mob1;
reset(arg) {

  /* Applying mobs */
  if(!mob && !random(4)) {
    mob = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob, this_object());
  }
  if(!mob1 && !random(4)) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Ecity");
  add_exit("south","/wizards/gynter/darke/city/Wcity2");
  add_exit("east","/wizards/gynter/darke/city/gcity2");
  add_exit("west","/wizards/gynter/darke/city/gcity1");
  /* setting desc */
  short_desc = "The new walk to the city";
  long_desc = "As you walk down the road you notice that this\n"+
              "road is newly build. And far, far down the road you\n"+
              "see part of the city. It looks like noumerous large\n"+
              "boulders with holes in them.\n";
}