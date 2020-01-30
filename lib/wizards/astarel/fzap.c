#include <ansi.h>

#define COLOURS  "/cmds/std/_lite"
#define LEADER_D "/daemons/leader_d"
#define KHALAND "/world/monsters/cleric"

cmd_fzap(name) 
{
    object ob;
    string temp_str;

    if (!name)
      { write("Syntax : fzap <target>\n"); return 1; }

    ob = find_player(name);

    if (!ob) 
	{
         write("No such person.\n");
         return 1;
    	}

    tell_object	(ob, 
            "You are zapped by "+capitalize(this_player()->query_real_name())+
            "\nThat really "+BOLD+CYAN_F+"HURT!\n"+OFF+
            "The pain eases and allows you to move again.\n"+
            "\n"+
	    "You die.\n"+
            "\n"+
            "You have a strange feeling.\n"+
            "You can see your own dead body from above.\n"+
            "\n"+
            "Khaland tells you 'Type 'accept ress from khaland' if you wish to be resurrected\n"+
            "It will cost you "+KHALAND->query_ress_cost(ob)+" bronze coins.'\n"+
	    "\n");
    
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
