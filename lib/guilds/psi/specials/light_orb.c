start(int i) {
  set_light(3);
  call_out("time_out", i);
}

short() { return "A orb of light"; }
long() { write("A orb of light"); }
query_long() { return "A orb of light"; }


get() { return 0; }
drop() { return 1; }

id(str) { if (str == "orb") { return 1; } }

time_out(i) {
	write("The orb vanishes\n");
	set_light(-3);
	destruct(this_object());
}

query_no_save() { return 1; }