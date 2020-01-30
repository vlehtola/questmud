object ob;

reset(arg) {
  if(arg) return;
  ob = find_player("nalle");
  if(!ob || ob->query_wizuvarjo()) return;
  shadow(ob, 1);
  tell_object(ob, "wiz shadow start\n");
}

idle() {
  return 60*4+2+random(10);
}


show_age() {
  write("Age: Hottie-teen!\n");
}

query_wizuvarjo() { return 1; }

remove_wizuvarjo() { destruct(this_object()); }


