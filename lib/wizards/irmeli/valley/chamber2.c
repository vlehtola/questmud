inherit "room/room";

reset(arg) {
 if (arg) { return; }
 short_desc = "A dusty chamber";
 long_desc = "A dusty chamber deep inside a huge mountain. The walls and the\n"+
             "ceiling are covered with cobwebs. You must wade in here, because\n"+
             "the water is flowing high in the chamber. Around the chamber\n"+
             "can be heard the sound of the waterfall echoing.\n";

    add_exit("south", "/wizards/irmeli/valley/tunnel.c");

  items = allocate(4);
  items[0] = "water";
  items[1] = "The water level is high, covering the bottom of the chamber, totally. There is a huge hole in the eastern wall, under the water level";
  items[2] = "hole";
  items[3] = "A huge hole, made in the eastern wall, can be seen under the water level";
}

init() {
  ::init(); 
  add_action("dive", "dive"); 
}

dive(string str) {
  if(str == "into hole") {
    write("You exhale and prepare to dive.\n");
    call_out("do_dive", 0);
    return 1;
  }
}

void do_dive() {
  write("You take a deep breath and dive under the water level.\n"+ 
        "You swim through the hole and end up in a underwater chamber.\n");
  say(this_player()->query_name()+" dives under the water level.\n");
  move_object(this_player(),"/wizards/irmeli/valley/underwater.c");
  command("look",this_player());
}
