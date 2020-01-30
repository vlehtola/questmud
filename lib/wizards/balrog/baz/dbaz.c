inherit "room/room";

#define STALL_PRICE 5000
#define PATH "/wizards/balrog/baz/"

reset(status arg)
{
  if(arg) return;

  /* Someone can set the exits, I have no idea whatsoever --Darol */
  add_exit("test","/wizards/balrog/testroom");
  short_desc = "Busy Bazaar";
  long_desc = "It seems that there's a long road in here that opens a way to very "+
              "busy looking bazaar. There is also a sign that might explain what to do.\n";
  property = allocate(4);
  items = allocate(2);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  items[0] = "sign";
  items[1] = "Commands you can use in this bazaar:\n"+
             "setup stall............... Set your own bazaar shop, this costs you "+ STALL_PRICE +".\n"+
             "enter <name>'s bazaar......Enter a shop, Example: enter darol's bazaar\n";
  set_light(3);
}

init()
{
        ::init();
        add_action("setup_stall", "setup");
        add_action("goldie", "gold");
        add_action("poor", "poor");
}

string myc()
{
        return PATH+this_player()->query_real_name()+".b";
}

int has_shop()
{
        if(file_size(myc()) > 0) return 1;
        return 0;
}

status smyc()
{
        this_player()->save_object(myc());
        return 1;
}
status setup_stall(string str)
{
        if(str != "stall")
        {
                write("Setup what? Look at sign please.\n");
                return 1;
        }
        if(has_shop())
        {
                write("You already have a stall in the bazaar.\n");
                return 1;
        }
        smyc();
        return 1;
}
int goldie(string str)
{
         write("Giving "+STALL_PRICE+" gold\n");
         this_player()->add_money(STALL_PRICE);
         return 1;
}
int poor(string str)
{
         this_player()->reduce_money(STALL_PRICE);
         return 1;
}
