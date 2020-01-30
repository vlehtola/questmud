object user;

id(str) { return str == "first_aid_object"; }
drop() { return 1; }

start(ob) {
  user = ob;
  call_out("end_fa", 300);
}
end_fa() {
 if(user) {
 tell_object(user, "You feel you can be aided again.\n");
}
destruct(this_object());
return 1;
}