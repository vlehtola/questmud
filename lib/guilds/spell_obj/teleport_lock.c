object ob;

start(arg, time) {
  ob = arg;
  if (ob->query_heavy_weight()) { return; }
/*  call_out("end",time); unlimited duration */
  return 1;
}

id(str) { return str == "teleport lock" || str == "beacon"; }

short() {
  return "A magical beacon";
}

long() {
  write("A magical beacon that has something to do with teleporting spells.\n");
}

query_heavy_weight() {
 return 1;
}

drop() {
  call_out("end", 0);
  return 0;
}

get() {
  return 1;
}

end() {
  write("Your teleport lock wears off.\n");
  destruct(this_object());
  return 1;
}
