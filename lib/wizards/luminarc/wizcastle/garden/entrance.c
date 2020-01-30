inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("castle","/wizards/luminarc/wizcastle/upeast2");
  add_exit("north","/wizards/luminarc/wizcastle/garden/house");
  short_desc = "garden";
  long_desc="Garden of the castle is a huge area. Lot of different plants fill up\n"+
            "the view. Small insects are flying around bushes and birds with beautiful\n"+
            "voices fly up in the sky. The small path is leading to north where small\n"+
            "and ruined house is built in the middle of the garden. Another path is\n"+
            "leading south to the fields where plants are growing\n";
  property = allocate(1);
  set_light(3);
}

