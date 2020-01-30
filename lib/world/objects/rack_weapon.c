inherit "/obj/weapon";

set_rack_type(string str) {
  if(str == "sword") str = "short sword";
  if(str == "axe") str = "hand axe";
  if(str == "mace") str = "mace";
  set_class(2);
  set_sub_type(str);
  value = 0;
}

drop() {
  call_out("destroy", 1);
}

destroy() {
  write("The weapon rusts and vanishes as you drop it.\n");
  destruct(this_object());
  return 1;
}

query_no_save() { return 1; }
