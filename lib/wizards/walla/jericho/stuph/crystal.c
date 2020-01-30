inherit "obj/armour";
 
start() {
  set_class(10);
  set_slot("neck");
  set_name("necklace");
  set_short("Necklace of many wonders");
  set_long("You are holding in your hands a uniquely crafted item.\n" +
             "The necklace has been forged from many small pieces of \n" +
             "crystal, and vibrates when you hold it. It seems very \n" +
             "fragile, although its made of one of the toughest materials\n" +
             "found in this realm. You can see 5 small jewels of different\n" +
             "colours can bee seen on the jewel.");
 
  }
 

 
boost_str() {
  write("The crystal vibrates in a blue light.\n");
  set_stats("str", 30);
  worn_by->update_stats();
  return 0;
}
 
boost_dex() {
  write("The crystal vibrates in a green light.\n");
  set_stats("dex", 30);
  worn_by->update_stats(); 
  return 0;
}
 
boost_con() {
  write("The crystal vibrates in a red light.\n");
  set_stats("con", 30);
  worn_by->update_stats();
  return 0;
}

boost_int() {
  write("The crystal vibrates in a orange light.\n");
  set_stats("int", 30);
  worn_by->update_stats();
  return 0;
}

boost_wis() {
  write("The crystal vibrates in a yellow light.\n");
  set_stats("wis", 30);
  worn_by->update_stats();
  return 0;
} 
init() {
::init();
add_action("boost_str", "blue");
add_action("boost_con", "red");
add_action("boost_dex", "green");
add_action("boost_int", "orange");
add_action("boost_wis", "yellow");

}

