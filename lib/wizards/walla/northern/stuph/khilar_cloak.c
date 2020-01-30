inherit "obj/armour";
 
start() {
    set_name("cloak");
    set_class(7);
    set_slot("cloak");
    set_alias("hoovee");
    set_short("The cloak of castle North Face");
    set_long("This is the cloak of castle North Face. On it, is\n"+
             "embedded the symbol of the dwarves, an anvil and an axe. The\n"+
             "cloak is made of a warm fur, and looks quite thick. But it still\n"+
             "looks fragile enough to be ripped apart, if it tangles somewhere");
    set_resists("cold", 33);
    set_stats("str",8);
    set_stats("con",8);
    set_stats("hpr",8);
    set_weight(5);
    set_value(5000);
}

init() 
{
  ::init();
  add_action("rip","rip");
}
 

int rip(string str) 
{
 if(str!="cloak") return 0;
 
 write("You rip up the cloak, and only the emblem and the torn cloak is left.\n");
 move_object(clone_object("/wizards/walla/northern/stuph/rag"),
                this_player());
 move_object(clone_object("/wizards/walla/northern/stuph/holecloak"),
                this_player());
 destruct(this_object());

 return 1;
}

