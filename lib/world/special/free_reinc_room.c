inherit "room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Free reincarnation room";
  long_desc = "Free reincarnation room\n"+
                "Available commands:\n"+
                "\tfree_reinc\n"+
                "\testimate_worth\n";
  set_not_out(5);
  set_light(3);
  add_exit("cs","/world/city/cs");
  property = "no_summon";
}

init() {
  ::init();
  add_action("free_reinc","free_reinc");
  add_action("estimate_worth","estimate_worth");
}

free_reinc() {
  object *obje;
  int i;

  write("You accept the free reincarnation.\n");

  i = 0;
  obje = all_inventory(this_player());
  while(i<sizeof(obje)) {
      if(obje[i] && obje[i]->short()) { destruct(obje[i]); }
      i++;
  }

  this_player()->reinc();
  move_object(this_player(),"/obj/race_selection");
  return 1;
}

estimate_worth() {
  write("Total worth: "+this_player()->query_total_string()+"\n");
  return 1;
}
