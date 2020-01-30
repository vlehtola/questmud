inherit "obj/armour";
status intf, intc, inte;

void start() {
    if(!intf && !intc && !inte) {
    set_value(250);
    set_name("ring");
    set_short("Ring of Resistance");
    set_long("Width ring with a glowing jewel attached on top of it. The ring is decorated\n" + 
           "with shapes of flames, icicles and lightnings, and you can sense strong magic\n" + 
           "in it. The ring has been made to protect its wearer from elemental spells, such\n" + 
           "as fire, cold and lightning.\n" + 
           "The ring can be tuned with 'tune_ring to <element>'");
    set_slot("finger");
    set_resists("fire", 0);
    set_resists("cold", 0);
    set_resists("electric", 0);
  }
  
  if(intf) {
    set_value(250);
    set_name("ring");
    set_short("Ring of Resistance <reddish glow>");
    set_long("Width ring with a glowing jewel attached on top of it. The ring is decorated\n" + 
           "with shapes of flames, icicles and lightnings, and you can sense strong magic\n" + 
           "in it. The ring has been made to protect its wearer from elemental spells, such\n" + 
           "as fire, cold and lightning.\n" + 
           "The ring can be tuned with 'tune_ring to <element>'");
    set_slot("finger");
    set_resists("fire", 10+random(10));
    set_resists("cold", 0);
    set_resists("electric", 0);
  }
  
  if(intc) {
    set_value(250);
    set_name("ring");
    set_short("Ring of Resistance <bluish glow>");
    set_long("Width ring with a glowing jewel attached on top of it. The ring is decorated\n" + 
           "with shapes of flames, icicles and lightnings, and you can sense strong magic\n" + 
           "in it. The ring has been made to protect its wearer from elemental spells, such\n" + 
           "as fire, cold and lightning.\n" + 
           "The ring can be tuned with 'tune_ring to <element>'");
    set_slot("finger");
    set_resists("fire", 0);
    set_resists("cold", 10+random(10));
    set_resists("electric", 0);
  }
  
  if(inte) {
    set_value(750);
    set_name("ring");
    set_short("Ring of Resistance <yellowish glow>");
    set_long("Width ring with a glowing jewel attached on top of it. The ring is decorated\n" + 
           "with shapes of flames, icicles and lightnings, and you can sense strong magic\n" + 
           "in it. The ring has been made to protect its wearer from elemental spells, such\n" + 
           "as fire, cold and lightning.\n" + 
           "The ring can be tuned with 'tune_ring to <element>'");
    set_slot("finger");
    set_resists("fire", 0);
    set_resists("cold", 0);
    set_resists("electric", 10+random(10));
  }
  return;
}

void init() {
  ::init();
  add_action("tune_ring", "tune_ring");
}

status tune_ring(string str) {
  if(str == "to fire") {
    intf = 1; intc = 0; inte = 0;
    write("The ring starts to glow in red.\n"); }

  if(str == "to cold") {
    intf = 0; intc = 1; inte = 0;
    write("The ring starts to glow in blue.\n"); }
  
  if(str == "to electric") {
    intf = 0; intc = 0; inte = 1;
    write("The ring starts to glow in yellow.\n"); }
  
  if(str == "to fire" || str == "to cold" || str == "to electric") {
    start(); return 1; }
  else {
    write("No such tuning possibility.\n");
    return 1; }
}