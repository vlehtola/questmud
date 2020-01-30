object tp;
int time;

id(str) { return str == "magic_bane"; }

start(object ob,int bonus) {
  tp = ob;
  time = 300;
  call_out("end_magicbane",time);
}

end_magicbane() {
  if(tp) { tell_object(tp, "You feel like your magic powers are rising.\n"); }
  destruct(this_object());
}

query_magic_bane() { return this_object(); }
