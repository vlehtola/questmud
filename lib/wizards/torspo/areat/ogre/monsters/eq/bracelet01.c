inherit "obj/armour";
status i;

void start() {
  if(i) {
    set_class(7);
    set_sub_type("arm guards");
    set_name("bracelets");
    set_alias("bracers");
    set_short("Pincer bracelets");
    set_long("The huge crab pincers which may be worn as bracelets. They have some runes\n"+
             "painted in them");
    set_weight(100);
    set_stats("str", 4);
    set_stats("dex", 4);
    set_stats("con", 4);
    set_stats("int", -5);
    set_stats("wis", -5);
    set_stats("spr", -1);
    return;
  }
  else {
    set_class(7);
    set_sub_type("arm guards");
    set_name("bracelets");
    set_alias("bracers");
    set_short("Pincer bracelets");
    set_long("The huge crab pincers which may be worn as bracelets. They have some runes\n"+
             "painted in them");
    set_weight(100);
    set_stats("str", -5);
    set_stats("dex", -5);
    set_stats("con", 1);
    set_stats("int", 6);
    set_stats("wis", 6);
    set_stats("spr", 10);
  }
  return;
}

void init() {
  ::init();
  add_action("runes", "read");
}

status runes(string str) {
 if(str=="runes") {
    if(i == 0) {
      i = 1;
      write("The runes start to glow in red.\n");
    }
    else {
      i = 0;
      write ("The runes start to glow in orange.\n"); }
    }
    start();
    return 1;
}


