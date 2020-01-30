inherit "obj/armour";
init() {
  ::init();
  add_action("wear", "wear");
}
 
wear(str) {
  if(str != "helmet") return;
  write("You pull the torchholder, and the wall slides open.\n");
  command("wear helmet");
  return 1;
}

start() {
set_class(5);
  set_slot("head");
    set_name("helmet");
    set_alias("visor");
    set_short("A dark green beret with a golden eagle");
    set_long("This beret has belonged to a skilled fighter from the coast.\n"+
             "The beret is made out of strong cotton, and the golden eagle\n"+
             "shines in the sunlight.");
    set_value(5000);
    set_stats("dex",5);
    set_stats("str",3);
    set_stats("con",1);
    set_weight(3);
 
  

}

