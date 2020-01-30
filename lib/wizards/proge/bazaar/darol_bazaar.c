
/* Darol's Bazaar daemon. This is supposed to be some kind of item handler that people */
/* can use to trading eq. Each person can buy a shop if they like and can use it to */
/* trading eq.  In one's shop, person who owns the shop can put items to sale and to */
/* him or her items can be proposed at certain price as well.  --Darol */

inherit "room/room";

#define STALL_PRICE 5000
#define SAVE_DIR "/wizards/darol/bazaar/shops/"

reset(status arg)
{
  if(arg) return;

  /* Someone can set the exits, I have no idea whatsoever --Darol */
  //  add_exit("inn","/world/city/inn");
  //  add_exit("cs","/world/city/cs");
  short_desc = "Busy Bazaar";
  long_desc = "It seems that there's a long road in here that opens a way to very "+
                          "busy looking bazaar. There is also a sign that might explain what to do.\n";

  property = allocate(4);
  items = allocate(6);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  items[0] = "road";
  items[1] = "This road continues to the bazaar area. You can see many stalls there.\n";
  items[2] = "bazaar";
  items[3] = "This bazaar seems to be very busy all the time.\n";
  items[4] = "sign";
  items[5] = "Commands you can use in this bazaar:\n"+
                         "setup stall............... Set your own bazaar shop, this costs you "+ STALL_PRICE +".\n"+
                         "enter <name>'s bazaar......Enter a shop, Example: enter darol's bazaar\n";
  set_light(3);
}

init()
{
        ::init();
        add_action("setup_stall", "setup");
}

string myshopfile()
{
        string shop;
        shop = SAVE_DIR;
        shop += this_player()->query_real_name();
        shop += ".o";
        return shop;
}

int query_own_shop()
{
        if(file_size(myshopfile()) > 0) return 1;
        return 0;
}

status savemyshop()
{
        save_object(myshopfile());
        return 1;
}
status setup_stall(string str)
{
        if(str != "stall")
        {
                write("Setup what? Look at sign please.\n");
                return 1;
        }
        if(query_own_shop())
        {
                write("You already have a stall in the bazaar.\n");
                return 1;
        }
        if(this_player()->query_money() < STALL_PRICE)
        {
                write("You cannot afford to setup a stall.\n");
                return 1;
        }
        write("You pay "+ STALL_PRICE +" and setup a stall in the bazaar.\n");
        say(this_player()->query_name() +" setups a stall in the bazaar.\n",this_player());
        this_player()->add_money(-STALL_PRICE);
        savemyshop();
        return 1;
}
