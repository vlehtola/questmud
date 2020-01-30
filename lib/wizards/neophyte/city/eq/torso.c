inherit "obj/armour";
int i;
void start() {
        if(i) {
        set_class(1);
        set_sub_type("scale mail");
        set_short("A shimmering scale mail");
        set_long("This mail is made from scales of ancient leviathan.\n"+
                 "The scales are shimmering like an ocean with all the\n"+
                 "blue colours. Backside of the mail is a picture\n"+
                 "presenting large ship.");
        clear_stats();
        set_stats("int", 8);
        set_stats("wis", 8);
        set_stats("spr", 15);
}
 else {
           set_class(7);
           set_sub_type("scale mail");
           set_short("A shimmering scale mail");
           set_long("This mail is made from scales of ancient leviathan.\n"+
                    "The scales are shimmering like a ocean with all the\n"+
                    "blue colours. Backside of the mail is a small wheel");
           clear_stats();
           set_stats("dex", 15);
           set_resists("poison", 5);
           set_resists("electric", 5);
           }
return ;
}

void init() {
  ::init();
  add_action("move", "move");
}

status move(string str) {
 if(str=="wheel") {
    if(i == 0) {
      i = 1;
      write("The wheel slowly rotates clockwise.\n");
    }
    else {
      i = 0;
      write ("The wheel slowly rotates counterwise .\n"); }
    }
    start();
    this_player()->update_stats();
    return 1;
}
