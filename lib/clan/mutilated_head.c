string killer,killed;

set_name(string killer_, string killed_) {
  if(!killer_ || !killed_) return;
  killer = capitalize(killer_);
  killed = capitalize(killed_);
}

query_killer() { return killer; }
query_killed() { return killed; }

get() { return 1; }

long() {
  write(
"The head has been cut off from "+killed+"'s shoulders after death.\n"+
"It's covered with blood and the face has a horrified look as if\n"+
"the victim knew what was coming. The eyes stare at nothingness\n"+
"and the mouth has stuck open as if to let out a scream.\n");
}

short() {
  return "The mutilated head of "+killed;
}

id(str) {
  return str == "head";
}

query_no_save() { return 1; }
