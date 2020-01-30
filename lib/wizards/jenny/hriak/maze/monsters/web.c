object uhri;
int time;

start(ob) {
  uhri = ob;
  if(uhri->query_web()) {
    destruct(this_object());
    return 1;
  }
  time = random(20)+5;
  shadow(uhri,1);
  call_out("web_stop",time);
}

query_web() { return this_object(); }
move_player() {
  tell_object(uhri, "The web stops your movement.\n");
  return 1;
}

cast(str) {
  if(random(2) == 0) call_out("web_interrupt",1);
  uhri->cast(str);
  return 1;
}

web_interrupt() {
  if(uhri->query_spell()) {
    tell_object(uhri, "The web interrupts your concentration.\n");
    call_other(uhri->query_spell(), "interrupt_spell");
  }
  return 1;
}

web_stop() {
  tell_object(uhri, "You struggle out of the web.\n");
  say(uhri->query_name()+" struggles out of the web.\n");
  destruct(this_object());
}
