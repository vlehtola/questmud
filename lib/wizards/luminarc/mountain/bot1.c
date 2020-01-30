inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("southwest","/wizards/luminarc/mountain/room0");
  add_exit("northeast","/wizards/luminarc/mountain/bot2");
  short_desc = "Spiral path leading to the top";
  long_desc="Some grash is still crowing on bottom of the mountain\n"+
            "small insects fly everywhere and beautiful flowers are\n"+
            "growing. small white coulds covers the sky making it hard\n"+
            "to see sun at all.\n";
  property = allocate(1);
  set_light(3);
}

