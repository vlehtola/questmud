inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("knight")) { 
    move_object(clone_object("/wizards/irmeli/castle/monsters/towerknight1.c"),
    this_object());
}


  add_exit("stairs", "/wizards/irmeli/castle/wtower1.c");
  add_exit("out", "/wizards/irmeli/castle/yard20.c");
 
 short_desc = "Inside of the west tower of castle Asgroth";
  long_desc = "The west tower is gloomy from inside. The dusty floor is made of wood. There\n"+
              "are spiral stairs leading up to the darkness. The stairs are made of iron and\n"+
              "they seem to be quite stable. Few torches are burning on the walls of the tower.\n"+
              "Spider webs are hanging from the walls. It seems that the west tower isn't in\n"+
              "use anymore. There are no windows on the walls.\n";

   set_not_out(1);
   set_light(4);

   items = allocate(6);
   items[0] = "torches";
   items[1] = "Few torches are burning on the walls.";
   items[2] = "stairs";
   items[3] = "Stairs made of iron. Shaped as spiral.";
   items[4] = "spider webs";
   items[5] = "The spider webs are covering the walls.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}


