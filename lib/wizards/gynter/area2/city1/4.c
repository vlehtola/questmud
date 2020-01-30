inherit "room/room";
object demon,demon1,demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(3)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/paladin");
    move_object(demon, this_object());
  }
  if(!demon1 && random(3)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/paladin");
    move_object(demon1, this_object());
  }
  if(!demon2 && random(3)) {
    demon2 = clone_object("/wizards/gynter/area2/city1/mobs/paladin");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/area2/city1/3");
  add_exit("enter","/wizards/gynter/area2/city1/castle1");
  /* setting desc */
  short_desc = "The entrance to the Kings castle";
  long_desc = "The entrance to the Kings castle is made out of pearly white stone.\n"+
              "And the stone is polished until it almost's shines. The gates into the\n"+
              "castle are black as death, symbolising the fate that every king has to\n"+
              "meet in the same time as he meet's failure.\n";
}
