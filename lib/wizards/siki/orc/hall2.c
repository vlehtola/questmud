inherit "room/room";

reset(arg) {

  add_exit("west","/wizards/siki/orc/hall3");
  add_exit("east","/wizards/siki/orc/hall1");
  set_not_out(1);
  set_light(0);

  short_desc = "Long hallway";
  long_desc =
"A dark and humid tunnel leading into the heart of the mountain.\n"+
"The cold stone walls are full of small holes and mining marks.\n"+
"Some ancient paintings of primitive orcs hunting innocent animals\n"+
"can still be seen on the stone walls. The ground is wet as water\n"+
"drips from the ceiling.\n";


 items = allocate(10);
 items[0] = "walls";
 items[1] = "Cold stone walls full of small holes and mining marks";
 items[2] = "holes";
 items[3] = "Small holes on the walls, probably formed by dripping water";
 items[4] = "ground";
 items[5] = "The ground is all wet and muddy. Old footprints are filled with water\n"+
            "and the forms aren't sharp";
 items[6] = "footprints";
 items[7] = "Footprints full of muddy water and broken forms. It is impossible to\n"+
            "say what has left them";
 items[8] = "paintings";
 items[9] = "Ancient wall paitings of primitive orcs hunting down small animals\n"+
            "and doing strange rituals";
}
