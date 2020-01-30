inherit "obj/armour";

start() {
  int i;
  string c;
  set_name("helm");
  set_short("A bloody helm of the followers of B'rook");
  set_long(
"This helm represents the power of it's wearer. It's covered by old, dry blood.\n"+
"A rumor tells that this helm gets it's powers from the blood of it's fallen\n"+
"wearers. The helm itself is a gift from the chaotic gods to mortals of this realm.\n"+
"It can only be worn by the followers of B'rook, the ultimate leader.\n");

  set_slot("head");
  c = ({"str","dex","con","int","wis"});
  while(i<sizeof(c)) {
    set_stats(c[i], 5);
    i += 1;
  }
}
query_ac() {
  return 50;
}
armour_class() {
  return 50;
}
query_drop() {
  return 1;
}

drop() {
  return 1;
}

stop_wearing() {
  write(short()+" vanishes.\n");
  destruct(this_object());
}

query_no_save() {
    return 1;
}

