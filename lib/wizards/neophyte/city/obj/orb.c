string desc;
status l;
int i;
reset(arg) {
  if(arg) return;
  desc = "A orb of everlasting sun.\nThe orb feels quite magical and when looked inside the orb everything looks much more brighter.\n";
  i = 3;
}

init() {
  add_action("turn_orb", "touch");
}

turn_orb(str) {
    if(str == "orb" && !l) {
	write("As you touch the orb it start to get brighter.\n");
	say(this_player()->query_name()+" does something with the orb and "+this_player()->query_pronoun()+" starts to look brighter.\n");
	l = 1;
	set_light(i);
	return 1;
}
else if(str == "orb" && l) {
	write("As you touch the orb it start to go dimmer.\n");
	say(this_player()->query_name()+" does something with the orb and "+this_player()->query_pronoun()+" starts to look dimmer.\n");
	l = 0;
	set_light(-i);
	return 1;
	}
write("Touch what?\n");
return 1;
}

short() {
  return "Orb of Everlasting sun";
}

id(str) {
  return str == "orb";
}

long() {
  write(desc);
}
query_long() { return desc; }
query_name() { return "orb"; }

drop() {
  return 0;
}
query_weight() { return 1000; }
query_value() { return 1; }

get() {
  return 1;
}