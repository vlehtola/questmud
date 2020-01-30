inherit "obj/weapon"; 
 
reset(arg) {
    ::reset(arg);
    set_name("camera");
    set_short("Nick's candide camera.\n");
    set_long("This is the new Sony RDS-6921 with a 21-mm zoom and an anti-roll bar on the\n" +               
"vertical side next to the monochrome LCD display.\n" +
"The name says it all, doesn't it ?\n");
    set_material(8);
    set_class(7);
    set_weapon_type("bludgeon");
    set_value(1000);
    set_weight(2);
 
}

