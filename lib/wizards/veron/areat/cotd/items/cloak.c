
inherit "obj/armour";

start() {
  set_class(7);
  set_slot("cloak");
  set_alias("cloak");
        set_short("The colorful raincloak of Justin");
        set_long("The raincloak is made of thick leather and then coated with tar\n"+
                 "to prevent it getting wet. It's dyed in bright colors and is quite\n"+
                 "heavy");
		 
          set_stats("str", -2);
	  set_stats("con", 12);
	  set_stats("dex", 1);
  
}
