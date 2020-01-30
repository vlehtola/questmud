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
  write("You walk right into the brick wall and fall flat on your face.\n");
  say(this_player()->query_name()+" walks right into a brick wall, and falls flat on his face.\n");
  return 1;
}

short() {
  return "A brick wall surrounding the room";
}

long() {
  write("Before you, you see a huge brick wall, that a lemming has\n"+
        "built very rapidly. You can touch the brick wall, but it\n"+
        "doesn't seem to budge. Even the cement is already dry, and\n"+
        "you seem to be stuck here for a while.\n");
}

id(str) { return str == "wall" || str == "brick wall"; }
query_force_field() { return 1; }

start(time) {
  call_out("remove",time);
}

remove() {
  say("The brick wall collapses into a rubble.\n");
  destruct(this_object());
}

