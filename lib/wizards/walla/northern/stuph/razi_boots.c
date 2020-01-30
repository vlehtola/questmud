inherit "obj/armour";
 
start() {
set_class(6);
  set_slot("feet");
    set_name("boots");
    set_alias("shoes");
    set_short("Boots of the king");
    set_long("These boots are made out of the leather of a griffon, a huge animal\n"+
             "that looks like a crossbread eagle and a dragon. The leather is very\n"+
             "thick and seems to effectively protect you against the elements");
    set_value(5000);
    set_resists("cold", 8);
    set_resists("fire", 8);
    set_resists("electric", 8);
    set_weight(500);
}
