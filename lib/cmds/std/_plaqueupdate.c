status cmd_plaqueupdate() {
 call_other(find_object("/daemons/explist"), "update_plaque", this_player());
 call_other(find_object("/daemons/questlist"), "update_plaque", this_player());
  write("Plaque updated.\n");
  return 1;
}


