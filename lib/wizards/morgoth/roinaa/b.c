object ob;
 
reset(arg) {
  if(arg) return;
  ob = find_player("morgoth");
  if(!ob || ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
}
 
short() {
  write("Muumi\n");
}

idle() {
  return 60*6+6;
}
 
show_age() {
  write("Age: 666d 6h 6m 6s\n");
}
query_wizuvarjo() { return 1; }
 
remove_wizuvarjo() { destruct(this_object()); }
 
 query_plan() {
  if(this_player()->query_hp() <= 10) return 0;
  /* this_player()->reduce_hp(10); */
  return "piip!\n";
 
}
