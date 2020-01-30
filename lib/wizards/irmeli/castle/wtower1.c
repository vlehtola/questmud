inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("knight")) { 
    move_object(clone_object("/wizards/irmeli/castle/monsters/towerknight2.c"),
    this_object());
}


  add_exit("stairs", "/wizards/irmeli/castle/wtower2.c");
  add_exit("down", "/wizards/irmeli/castle/wtower.c");
 
 short_desc = "Inside of the west tower of castle Asgroth";
  long_desc = "The west tower is gloomy from inside. You are standing in the spiral stairs which\n"+
              "leads up and down, ending somewhere in the darkness. The stairs are made of iron\n"+
              "and they seem to be quite stable. Few torches are burning on the walls of the\n"+
              "tower. Spider webs are hanging from the walls. It seems that the west tower\n"+
              "isn't in use anymore.\n";

   set_not_out(1);
   set_light(4);

   items = allocate(6);
   items[0] = "torches";
   items[1] = "Few torches are burning on the walls.";
   items[2] = "stairs";
   items[3] = "Stairs made of iron. Shaped as spiral.";
   items[4] = "spiderwebs";
   items[5] = "The spiderwebs are covering the walls.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}


