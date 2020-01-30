inherit "obj/armour";

int state=0; // 0 == in belt, 1 == drawn
 
start() {
    set_name("belt");
    set_class(7);
    set_slot("belt");
    set_alias("hoovee");
    set_short("Belt of the Planes");
    set_long("Before you, you see a truly magnificent piece of equipment.\n"+
             "The belt is made of thick leather, and attached to it, is a \n"+
             "scabbard, in which you can sheathe the Sword of the Planes.\n"+
             "The scabbard is easily accessible in order to draw the sword\n"+
             "from it quickly.");
    set_resists("fire", 8);
    set_stats("str",5);
    set_stats("con",3);
    set_stats("hpr",4);
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

 write("You draw the Sword of the Planes from it's scabbard.\n");
 move_object(clone_object("/wizards/walla/northern/stuph/razi_sword"),
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

 write("You sheathe the Sword of the Planes into it's scabbard.\n");
 destruct(present("hc_walla_sword",this_player()));
 state=0;
 return 1;

}

