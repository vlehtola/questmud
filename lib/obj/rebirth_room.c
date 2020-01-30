#define REBIRTH "/obj/rebirth"
inherit "/room/room";

reset(status arg) {
  if(arg) return;
  short_desc = "Beside the fountain of life";
  add_exit("south", "/wizards/celtron/maze/necro/6");
long_desc =
"The divine fountain of life emits a bright light allover the room.\n"+
"The beams reflect from the white marble of which the walls and ceiling\n"+
"are made. The fountain itself doesn't look so ordinary, yet it contains\n"+
"awesome powers.\n";
}

init() {
  ::init();
  add_action("do_rebirth", "drink");
}

do_rebirth(string arg) {
  int i;
  object *obje;

  if(arg != "fountain" && arg != "from fountain") return 0;
  say(this_player()->query_name()+" drinks from the fountain.\n");
  if(strlen(this_player()->query_total_string()) < 11) {
    write("You drink the water and feel refreshed. Still, you lack anything not ordinary.\n");
    return 1;
  }
  
  if(this_player()->query_rebirth() == REBIRTH->query_max_rebirth()) {
    write("You have already achieved the greatest level of existence.\n");
    return 1;
  }

  if(!REBIRTH->enough_exp(this_player())) {
    write("You drink the water and feel refreshed. Still, you lack anything not ordinary.\n");
    return 1;
  }

  write("You drink from the blue deeps of the fountain and feel comsumed by a raw force of heat and cold.\n");

  obje = all_inventory(this_player());
  while(i<sizeof(obje)) {
      if(obje[i] && obje[i]->short()) { destruct(obje[i]); }
      i++;
  }


  this_player()->reinc();
  this_player()->do_rebirth();
  move_object(this_player(),"/obj/race_selection");
  log_file("REBIRTH", ctime(time())+": "+this_player()->query_name()+" was reborn to level "+
  this_player()->query_rebirth()+"\n");
  return 1;
}
