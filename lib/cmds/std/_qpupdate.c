status cmd_qpupdate() {
 call_other(find_object("/daemons/questlist"), "update_plaque", this_player());
write("Quest plaque updated.\n");
return 1;
}
