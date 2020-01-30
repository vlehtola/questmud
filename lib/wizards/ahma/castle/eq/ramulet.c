inherit "obj/armour";
status intf, intc, inte;

void start() {
    if(!intf && !intc && !inte) {
    set_value(1500);
    set_name("amulet");
    set_short("Amulet of Resistance");
    set_long("Golden, pentagon-shaped amulet is reflecting the light softly. In the upper\n" + 
             "part of the amulet is an illustration of a lightning, in the central part is a\n" + 
             "crude picture of a snowflake, and in the lower part there are some flames. The\n" + 
             "amulet has been made to protect its wearer from elemental spells, such as fire,\n" + 
             "cold and lightning.\n" + 
             "The amulet can be tuned with 'tune_amulet to <element>'");
    set_slot("neck");
    set_resists("fire", 0);
    set_resists("cold", 0);
    set_resists("electric", 0);
    say("HORO!\n");
  }
  
  if(intf) {
    set_value(1500);
    set_name("amulet");
    set_short("Amulet of Resistance <reddish glow>");
    set_long("A golden, pentagon-shaped amulet is reflecting the light softly. In the upper\n" + 
             "part of the amulet is an illustration of a lightning, in the central part is a\n" + 
             "crude picture of a snowflake, and in the lower part there are some flames. The\n" + 
             "amulet has been made to protect its wearer from elemental spells, such as fire,\n" + 
             "cold and lightning.\n" + 
             "The amulet can be tuned with 'tune_amulet to <element>'");
    set_slot("neck");
    set_resists("fire", 20+(random(30)));
    set_resists("cold", 0);
    set_resists("electric", 0);
  }
  
  if(intc) {
    set_value(1500);
    set_name("amulet");
    set_short("Amulet of Resistance <bluish glow>");
    set_long("Golden, pentagon-shaped amulet is reflecting the light softly. In the upper\n" + 
             "part of the amulet is an illustration of a lightning, in the central part is a\n" + 
             "crude picture of a snowflake, and in the lower part there are some flames. The\n" + 
             "amulet has been made to protect its wearer from elemental spells, such as fire,\n" + 
             "cold and lightning.\n" + 
             "The amulet can be tuned with 'tune_amulet to <element>'");
    set_slot("neck");
    set_resists("fire", 0);
    set_resists("cold", 20+(random(30)));
    set_resists("electric", 0);
  }
  
  if(inte) {
    set_value(1500);
    set_name("amulet");
    set_short("Amulet of Resistance <yellowish glow>");
    set_long("Golden, pentagon-shaped amulet is reflecting the light softly. In the upper\n" + 
             "part of the amulet is an illustration of a lightning, in the central part is a\n" + 
             "crude picture of a snowflake, and in the lower part there are some flames. The\n" + 
             "amulet has been made to protect its wearer from elemental spells, such as fire,\n" + 
             "cold and lightning.\n" + 
             "The amulet can be tuned with 'tune_amulet to <element>'");
    set_slot("neck");
    set_resists("fire", 0);
    set_resists("cold", 0);
    set_resists("electric", 20+(random(30)));
  }
  return;
}

void init() {
  ::init();
  add_action("tune_amulet", "tune_amulet");
}

status tune_amulet(string str) {
  if(str == "to fire") {
    intf = 1; intc = 0; inte = 0;
    write("The amulet starts to glow in red.\n"); }

  if(str == "to cold") {
    intf = 0; intc = 1; inte = 0;
    write("The amulet starts to glow in blue.\n"); }
  
  if(str == "to electric") {
    intf = 0; intc = 0; inte = 1;
    write("The amulet starts to glow in yellow.\n"); }
  
  if(str == "to fire" || str == "to cold" || str == "to electric") {
    start(); return 1; }
  else {
    write("No such tuning possibility.\n");
    return 1; }
}