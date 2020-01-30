init() {
  disable_exits();
}

disable_exits() {
  object ob;
  string str;
  int i;
  ob = environment(this_object());
  if(!ob) return;
  str = ob->query_dest_dir();
  i = 1;
  while(i<sizeof(str)) {
    add_action("stop",str[i]);
    i += 2;
  }
}

stop() {
  write("You cannot penetrate the bright red force field.\n");
  say(this_player()->query_name()+" tries to leave, but cannot penetrate the red force field.\n");
  return 1;
}

short() {
  return "A bright red force field is surrounding this area";
}

long() {
  write("The force field is translucent, everything beyond it seems\n"+
        "red. It seems very thin and fragile, yet it's magical\n"+
        "and can contain some weird and insidious capabilities.\n"+
        "One cannot leave this place by not trying to go through it.\n");
}

id(str) { return str == "field" || str == "force field"; }
query_force_field() { return 1; }

start(time) {
  call_out("remove",time);
}

remove() {
  say("The force field vanishes.\n");
  destruct(this_object());
}

