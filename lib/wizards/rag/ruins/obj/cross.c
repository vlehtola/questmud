short() { return "A twisted golden cross"; }

long(str) {
	write(  "This cross was once the most valued cross in the world of Deleria\n"+
		"but now most of it's precious jewels have been stolen. An unholy\n"+
		"fire has burned away it's shine and twisted it into a shapeless\n"+
		"lump of dimmed gold.\n");
	return;
}

id(str) { return str == "cross" || str == "cross123"; }

get() {
    return 1;
}

query_weight() {
  return 180;
}