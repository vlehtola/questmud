object aijys;

start(ob) {
  aijys = ob;
  shadow(aijys, 1);
  call_out("hiilia", random(20)+10);
  return 1;
}

hiilia() {
   write("The potion's effect makes you feel better.\n");
   say(call_other(this_player(),"query_name", 0) + " seems to regenerate amazingly fast.\n");
   this_player()->add_hp(45);
   this_player()->add_sp(50);
   call_out("hiilia2", 25);
   return 1;
}

hiilia2() {
   write("The potion's effect makes you feel better.\n");
   say(call_other(this_player(),"query_name", 0) + " seems to regenerate amazingly fast.\n");
   this_player()->add_hp(45);
   this_player()->add_sp(50);
   call_out("hiilia3", 25);
   return 1;
}

hiilia3() {
   write("The potion's effect makes you feel better.\n");
   say(call_other(this_player(),"query_name", 0) + " seems to regenerate amazingly fast.\n");
   this_player()->add_hp(45);
   this_player()->add_sp(50);
   call_out("hiilia4", 25);
   return 1;
}

hiilia4() {
   write("The potion's effect makes you feel a bit better.\n");
   say(call_other(this_player(),"query_name", 0) + " seems to regenerate amazingly fast.\n");
   this_player()->add_hp(30);
   this_player()->add_sp(45);
   aijys->update_stats();
   destruct(this_object());
   return 1;
}

death(arg) {
  aijys->death(arg);
  destruct(this_object());
  return 1;
}
