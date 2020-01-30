inherit "room/room";

reset(arg) {
  add_exit("south", "109");
  add_exit("northwest", "105");
  add_exit("northeast", "111");
  short_desc = "A snowy intersection";
  long_desc = "The two narrow tunnels leading to south and northwest join here and\n" +
              "continue in one bigger tunnel to northeast. This part of the tunnel\n" +
              "system is quite illuminated because of the hole located in the ceiling.\n" +
              "In addon to the light, some soft gusts of chilly wind can be felt\n" +
              "floating into the tunnels from the hole. Some icicles have formed in\n" +
              "the ceiling, which is about ten feet high.\n";

  items = allocate(2);
  items[0] = "hole";
  items[1] = "A small hole in the ceiling seems to penetrate through the whole mountain\n" +
             "above these tunnels. Some light and chilly wind is floating into the\n" +
             "tunnels through the hole. Also, it seems that small drops of water fall\n" +
             "down from the hole. The ground straight under the hole seems to be solid\n" +
             "frozen";
    if(!present("mink")) move_object(clone_object("/wizards/ahma/ice/mob/mink"), this_object());
}

init() {
  ::init();
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(200)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Mink") return;
    this_player()->hit_with_spell(random(31) + 1);
    
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}