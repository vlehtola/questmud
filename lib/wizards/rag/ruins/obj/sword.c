short() { return "A rusty bronze long sword"; }

long(str) {
	write(  "The long sword is a basic sword. It's two-edged blade is long\n"+
		"and quite thin. This typical sword seems to be hundreds of years\n"+
		"old. It is rusty and you think that you couldn't use it in battle.\n");
	return;
}

id(str) { return str == "sword" || str == "sword123"; }

get() {
    return 1;
}

query_weight() {
  return 280;
}