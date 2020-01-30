inherit "obj/armour";

int state=0; // 0 == in belt, 1 == drawn
 
start() {
    set_name("belt");
    set_class(7);
    set_slot("belt");
    set_alias("hoovee");
    set_short("Sword belt, v. 1.0 ");
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
  add_action("draw","draw");
  add_action("sheathe","sheathe");

}
 

int draw(string str) 
{
 if(str!="sword") return 0;

      if(state) 
	{
	 write("Hahaa, puusilm� eisiinoo en�� miekkaaa.\n");
	 return 1;
	}  

 write("You take sword from puusilm�.\n");
 move_object(clone_object("/wizards/walla/northern/test/sword_1"),
                this_player());
// init_command("wield sword");

 state++;
 return 1;
}

int sheathe(string str) 
{
 if(str!="sword") return 0;

 if(!state)
        {
         write("Hahaa, puusilm� miekka on jo siin.\n");
         return 1;
        }

 write("You put hc wallasword in belt.\n");
 destruct(present("hc_walla_sword",this_player()));
 state=0;
 return 1;
}
