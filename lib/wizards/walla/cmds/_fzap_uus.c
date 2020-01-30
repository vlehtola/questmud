#include <ansi.h>

#define COLOURS  "/cmds/std/_lite"
#define LEADER_D "/daemons/leader_d"

cmd_fzap(name) 
{
    object ob;

    if (!name)
      { write("Syntax : zapp <target>\n"); return 1; }

    ob = find_player(name);

    if (!ob) 
	{
         write("No such person.\n");
         return 1;
    	}

    tell_object	(ob, "You die..\n"+
            "\n"+
                    "You have a strange feeling.\n"+
                    "You can see your own dead body from above.\n"+
                    "\n"+
                    "Khaland tells you 'Type 'accept ress from khaland' if you wish to be resurrected\n"+
                    "It will cost you 920 bronze coins.'\n"
		);
    
    string temp_str;
    if(LEADER_D->test_leader(ob->query_real_name(), ob->query_race())) 
	temp_str = "{inform}"; 
         else 
	temp_str = "[inform]"; 

    temp_str = COLOURS->give_color(ob, "inform") + temp_str + OFF;

    tell_object(ob, temp_str+": "+ob->query_name()+" dies.\n");
    log_file("FAKE_ZAPS", this_player()->query_name() +
                ", " + extract(ctime(time()), 4, 15)+ " target: "+ob->query_name()+".\n",1);

    ob->reduce_hp(0);

    write("You fakezapped " + capitalize(name) + ".\n");
    return 1;
}
