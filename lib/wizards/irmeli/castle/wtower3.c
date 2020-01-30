inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("knight")) { 
    move_object(clone_object("/wizards/irmeli/castle/monsters/towerknight4.c"),
    this_object());
}

  add_exit("stairs", "/wizards/irmeli/castle/wroof.c");
  add_exit("down", "/wizards/irmeli/castle/wtower2.c");
 
 short_desc = "Inside of the west tower of castle Asgroth";
  long_desc = "You are standing in the spiral stairs which leads up. You can see the top of the tower.\n"+
              "There's a hole in the roof where the spiral stairs lead. The stairs goes through the\n"+
              "hole ending to the roof. The stairs are made of iron and it seems to be quite stable.\n"+
              "Few torches are burning on the walls of the tower. The tower looks quite gloomy\n"+
              "from the inside. Spiderwebs are hanging from the walls. It seems that the west\n"+
              "tower isn't in use anymore. There is a curtain on the wall.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(8);
   items[0] = "torches";
   items[1] = "Few torches are burning on the walls.";
   items[2] = "stairs";
   items[3] = "Stairs made of iron. Shaped as spiral.";
   items[4] = "spiderwebs";
   items[5] = "The spiderwebs are covering the walls.";
   items[6] = "curtain";
   items[7] = "It's made of silk. There's something behind it.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}

init() {
  ::init();
  add_action("pull", "pull");
}
pull(str) {
  if(str != "curtain") return;
write("As you pull the curtain it falls down to the ground.\n"+ 
      "A small balcony is revealed behind the curtain.\n");
    add_exit("balcony", "/wizards/irmeli/castle/wbalcony.c");
  return 1;
}
