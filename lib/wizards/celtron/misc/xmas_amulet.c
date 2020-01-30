inherit "obj/armour";

start() {
  set_short("A red amulet with white carvings");
  set_long("This amulet is a gift from the above. It looks like it\n"+
	   "is pulsing with power. Maybe it should be kept nearby in\n"+
	   "case it would prove useful. The runes glow with dim light");
  set_name("amulet");
  set_slot("amulet");

  set_stats("ac", 10);
  set_resists("electric", 35);
}

wear(string str) {
  int lowest,i, tmp, tmp_i;
  string *statit;

// boost the lowest stat by 50%. ungettable eq, so not out of tune.
  statit = ({ "str", "dex", "con", "int", "wis", });
  for(i=0; i < sizeof(statit) ; i++) {
    tmp = call_other(this_player(), "query_"+statit[i], 0);
    if(!lowest || tmp < lowest) {
      lowest = tmp;
      tmp_i = i;
    }
  }
  stats = ([ ]);
  stats[statit[tmp_i]] = 50;
  set_stats("ac", 10);
  set_resists("electric", 35);

  tell_room(environment(this_player()), "The red amulet lets out a curious sound.\n");
  ::wear(str);
  return 1;
}

init() {
::init();
add_action("read", "read");
}

read(string str) {
  if(str != "runes") return 0;
  write("The runes say: 'Whom ever posesses me, he's weakness is his strongness!'\n");
  return 1;
}
