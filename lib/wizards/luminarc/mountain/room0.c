inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/luminarc/mountain/entrance");
  add_exit("northeast","/wizards/luminarc/mountain/bot1");
  short_desc = "Spiral path leading to the top";
  long_desc="Some grash is still crowing on bottom of the mountain\n"+
            "small insects fly everywhere and beautiful flowers are\n"+
            "growing. small white coulds covers the sky making it hard\n"+
            "to see sun at all.\n";
  property = allocate(1);
  set_light(3);
}

