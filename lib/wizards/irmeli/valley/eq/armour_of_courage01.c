inherit "obj/armour";
status i;

void start() {
  if(i) {
    set_class(9);
    set_sub_type("plate mail");
    set_name("armour");
    set_short("Armour of Courage <silver-plated>");
    set_long("A silver-plated armour is reinforced with steel pieces. The pieces of\n"+
             "steel are placed strategically to protect the parts which are vulnerable\n"+
             "to wound easily. The armour is thick enough to protect the wearer from\n"+
             "suprisingly hits. A huge bronze cross has been carved in the torso of\n"+
             "the armour");

    clear_stats();
    set_stats("str", 10);
    set_stats("con", 9);
    set_stats("dex", 8);
   
    return;
}
 else {
    set_class(9);
    set_sub_type("plate mail");
    set_name("armour");
    set_short("Armour of Courage <silver-plated>");
    set_long("A silver-plated armour is reinforced with steel pieces. The pieces of\n"+
             "steel are placed strategically to protect the parts which are vulnerable\n"+
             "to wound easily. The armour is thick enough to protect the wearer from\n"+
             "unexpected hits. A huge bronze cross has been carved in the torso of\n"+
             "the armour");

    clear_stats();
    set_stats("con", 5);

    set_resists("fire", 15);
    set_resists("cold", 15);
    set_resists("poison", 15);
    set_resists("electric", 15);

  }
  return;
}

void init() {
  ::init();
  add_action("cross", "push");
}

status cross(string str) {
 if(str=="cross") {
    if(i == 0) {
      i = 1;
      write("The bronze cross moves inwards the armour.\n");
      
    }
    else {
      i = 0;
      write ("The bronze cross moves outwards from the armour.\n"); }

    }
    start();
this_player()->update_stats();
    return 1;
}
