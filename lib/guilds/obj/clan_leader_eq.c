inherit "obj/armour";

start() {
  int i;
  string c;
  set_name("crown");
  set_short("The bloody crown of B'rook");
  set_long(
"This crown represents the ultimate power of it's wearer. It's covered by\n"+
"old, dry blood. A rumor tells that this crown gets it's powers from the\n"+
"blood of it's fallen wearers. The crown itself is a powerful gift from the\n"+
"chaotic gods to mortals of this realm.\n"+
"It can only be worn by B'rook himself, the ultimate leader.\n");
  set_slot("head");
  c = ({"str","dex","con","int","wis"});
  while(i<sizeof(c)) {
    set_stats(c[i], 10);
    i += 1;
  }
}
query_ac() {
  return 100;
}
armour_class() {
  return 100;
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

