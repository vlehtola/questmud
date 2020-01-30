inherit "room/room";
reset(arg) {

  call_other("/wizards/gynter/darke/virtual/virtual_map", "XX", 0);
  call_other("/wizards/gynter/darke/city/guard/virtual_guard_map", "XX", 0);
  call_other("/wizards/gynter/darke/city/hall/virtual_hall_map", "XX", 0);
  call_other("/wizards/gynter/darke/city/tunnels/virtual_tunnel_map", "XX", 0);

if(arg) return;

  add_exit("out", "outmap: 215 125");
  add_exit("south","/wizards/gynter/darke/virtual/virtual_map: 34 6");

  short_desc = "Opening in the mountain";
  long_desc = "The massive mountain wall rises upwards so sharp, that it's impossible to\n"+
              "climb up and cross the mountain. A small crack is in the mountain wall,\n"+
              "leading inside the mountain wall. It's impossible to say what's behind\n"+
              "the crack, because of the darkness. The crack is big enough for you to\n"+
              "enter. A small footprints are leading in the crack, vanishing in the\n"+
              "darkness.\n";

    items = allocate(6);
    items[0] = "crack";
    items[1] = "It's big enough for even the biggest adventurer in the realm";
    items[2] = "footprint";
    items[3] = "A small footprint, left in the mud, are leading into the crack";
    items[4] = "mountain";
    items[5] = "The mountain is sharp, making the crossing impossible";
}
