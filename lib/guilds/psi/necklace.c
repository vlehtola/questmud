inherit "obj/armour";
status iw;
start() {
        set_slot("neck");
        set_name("necklace");
        set_short("A yellow necklace of Celuwien");
        set_long("The yellow necklace is made to Celuwing by one of the elder elf's\n"+
                 "The headbang feels quite sturdy and somehow it's seems to be\n"+
                 "perfectly mentaly balanced. They say when time comes one can\n"+
                 "yell the name of Celuwien and feel totaly safe");
        set_stats("int", 4);
        set_stats("wis", 5);
        set_stats("con", 5);
        set_stats("spr", 6);
        set_value(250);
        set_weight(650);
        iw = 0;
}
init() {
::init();
add_action("yell", "yell");
}

yell(string str) {
	object ob;
  if(str != "celuwien") return 0;
  if(!worn_by)return 0;
  if(worn_by->query_race() != "dark elf") {
	  write("You yell the name of Celuwien but nothing seems to happen.\n");
	  return 1;
  }
  if(iw) {
	  write("You yell the name of Celuwien but nothing seems to happen.\n");
	  return 1;
  }
  write("You yell the name of Celuwien and you feel safe.\n");
  write("You get somehow perfect will againt's stuns.\n");
  iw = 1;
  ob = clone_object("/guilds/psi/specials/iron_will_shadow");
  ob->start(worn_by, 10000);
  return 1;
}
wear(string str) {
  ::wear(str);
  if(!worn_by) return 0;
  if(this_player()->query_race() == "dark elf") {
    write("The necklace feels warm you to wear.\n");
    return 1;
}
  return 1;
}