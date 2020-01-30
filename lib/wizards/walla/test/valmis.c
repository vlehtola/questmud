inherit "obj/armour";
#include <ansi.h>

start() {
set_class(9);
  set_slot("neck");
    set_name("necklace");
    set_alias("amulet");
    set_short("Necklace of many wonders");
    set_long("You are holding in your hands a uniquely crafted item.\n" +
             "The necklace has been forged from many small pieces of \n" +
             "crystal, and vibrates when you hold it. It seems very \n" +
             "fragile, although its made of one of the toughest materials\n" +
             "found in this realm. You can see 5 small jewels of different\n" +
             "colours can bee seen on the crystal. The colours of the jewels are\n" +
             "white, yellow, blue, red and green.");

}
 
boost_blue() {
  write("The crystal vibrates in a blue light.\n");
  set_short("Necklace of many wonders <bright "+BLUE_F+"blue"+OFF+" glow>");
  set_long("You are holding in your hands a uniquely crafted item.\n" +
           "The necklace has been forged from many small pieces of \n" +
           "crystal, and vibrates when you hold it. It seems very \n" +
           "fragile, although its made of one of the toughest materials\n" +
           "found in this realm. You can see 5 small jewels of different\n" +
           "colours can bee seen on the crystal. The colours of the jewels are\n" +
           "white, yellow, blue, red and green.");
  return 0;
}
 
boost_green() {
  write("The crystal vibrates in a green light.\n");
  set_short("Necklace of many wonders <bright "+GREEN_F+"green"+OFF+" glow>");
  set_long("You are holding in your hands a uniquely crafted item.\n" +
           "The necklace has been forged from many small pieces of \n" +
           "crystal, and vibrates when you hold it. It seems very \n" +
           "fragile, although its made of one of the toughest materials\n" +
           "found in this realm. You can see 5 small jewels of different\n" +
           "colours can bee seen on the crystal. The colours of the jewels are\n" +
           "white, yellow, blue, red and green.");
  return 0;
}
 
boost_red() {
  write("The crystal vibrates in a red light.\n");
  set_short("Necklace of many wonders <bright "+RED_F+"red"+OFF+" glow>");
  set_long("You are holding in your hands a uniquely crafted item.\n" +
           "The necklace has been forged from many small pieces of \n" +
           "crystal, and vibrates when you hold it. It seems very \n" +
           "fragile, although its made of one of the toughest materials\n" +
           "found in this realm. You can see 5 small jewels of different\n" +
           "colours can bee seen on the crystal. The colours of the jewels are\n" +
           "white, yellow, blue, red and green.");
  return 0;
}
 
 
boost_yellow() {
  write("The crystal vibrates in a yellow light.\n");
  set_short("Necklace of many wonders <bright "+YELLOW_F+"yellow"+OFF+" glow>");
  set_long("You are holding in your hands a uniquely crafted item.\n" +
           "The necklace has been forged from many small pieces of \n" +
           "crystal, and vibrates when you hold it. It seems very \n" +
           "fragile, although its made of one of the toughest materials\n" +
           "found in this realm. You can see 5 small jewels of different\n" +
           "colours can bee seen on the crystal. The colours of the jewels are\n" +
           "white, yellow, blue, red and green.");
  return 0;
}
 
boost_white() {
  write("The crystal vibrates in a white light.\n");
  set_short("Necklace of many wonders <bright "+WHITE_F+"white"+OFF+" glow>");
  set_long("You are holding in your hands a uniquely crafted item.\n" +
           "The necklace has been forged from many small pieces of \n" +
           "crystal, and vibrates when you hold it. It seems very \n" +
           "fragile, although its made of one of the toughest materials\n" +
           "found in this realm. You can see 5 small jewels of different\n" +
           "colours can bee seen on the crystal. The colours of the jewels are\n" +
           "white, yellow, blue, red and green.");
  return 0;
}
 
 
init() {
::init();
add_action("boost_blue", "blue");
add_action("boost_green", "green");
add_action("boost_red", "red");
add_action("boost_yellow", "yellow");
add_action("boost_white", "white");
}
 
 
