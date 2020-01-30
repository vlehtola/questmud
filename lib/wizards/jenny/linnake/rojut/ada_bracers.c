inherit "obj/armour";
  start() {

   set_class(15);
   set_sub_type("arm guards");
   set_name("bracers");
   set_short("Adamantium bracers with crystal decoration");
   set_long("Fine looking adamantium bracers with crystals\n"+
            "embedded on the bottom. These bracers look\n"+
            "very valuable and they glow magically. There\n"+
            "is a small text written inside the bracers\n"+
            "that say:'For your loyal services Captain'\n"+             
            "Even if you look closely you cant see any\n"+
            "marks of damage on them");
   set_stats("int", 8);
   set_stats("wis", 8);
   set_stats("spr", 20);
   set_stats("str", -4);
   set_stats("dex", -10);
 }
