inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/12");
  add_exit("south","/wizards/gynter/element/earth/15");
  add_exit("west","/wizards/gynter/element/earth/11");
  add_exit("north","/wizards/gynter/element/earth/8");
  add_exit("up","/wizards/gynter/element/gateway");
  /* setting desc */
  short_desc = "Entrance to the land of stone";
  long_desc = "This is the entrance to the vast lands of stone.\n"+
              "Inhere your cries will not be heard. From every direction\n"+
              "you hear screams that comes from the present victims of\n"+
              "the stone elementals. And as it is said in the tales,\n"+
              "This is where the true warriors are born!\n";
  /* setting features */
  set_light(1);
}
