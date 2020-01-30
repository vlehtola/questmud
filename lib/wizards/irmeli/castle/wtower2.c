inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("knight")) { 
    move_object(clone_object("/wizards/irmeli/castle/monsters/towerknight3.c"),
    this_object());
}

  add_exit("stairs", "/wizards/irmeli/castle/wtower3.c");
  add_exit("down", "/wizards/irmeli/castle/wtower1.c");
 
 short_desc = "Inside of the west tower of castle Asgroth";
  long_desc = "You are standing in the spiral stairs which leads up and down. The top of the\n"+
              "tower can't be seen from here. The stairs are made of iron and they seem to\n"+
              "be quite stable. Few torches are burning on the walls of the tower. The tower\n"+
              "looks quite gloomy from the inside. Spider webs are hanging from the walls.\n"+
              "It seems that the west tower isn't in use anymore. There are no windows on\n"+
              "the walls.\n";

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


