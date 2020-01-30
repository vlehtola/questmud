inherit "obj/armour";
status iw;
start() {
        set_class(7);
        set_sub_type("greathelm");
        set_name("headbang");
        set_short("A yellow headbang of Celuwien");
        set_long("The yellow headbang is made to Celuwing by one of the elder elf's\n"+
                 "The headbang feels quite sturdy and somehow it's seems to be\n"+
                 "perfectly mentaly balanced. They say when time comes one can\n"+
                 "yell the name of Celuwien and feel totaly safe.\n");
        set_stats("int", 4);
        set_stats("wis", 5);
        set_stats("con", 5);
        set_stats("spr", 6);
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
  if(!this_player()->query_race("dark elf"))
    write("The headbang feels somehow out of place.\n");
  return 0;
}