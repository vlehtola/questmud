
resolve(bonus) {
  object ob;
  ob = present("horde_summon", this_player());
  if(!ob) { write("You dont have horde.\n"); return 1; }
  ob->teleport_horde();
  return 1;
}
