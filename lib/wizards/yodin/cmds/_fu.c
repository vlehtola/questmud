#include <ansi.h>

#define COLOURS  "/cmds/std/_lite"
#define LEADER_D "/daemons/leader_d"
cmd_fuck(name)
{
    object ob;
    string temp_str;

    if (!name)
      { write("Syntax : fuck <target>\n"); return 1; }

    ob = find_player(name);

    if (!ob)
        {
         write("No such person.\n");
         return 1;
        }

    tell_object (ob,
            "You are fucked by "+capitalize(this_player()->query_real_name())+
            "\nThat really "+BOLD+CYAN_F+"HURT!\n"+OFF+
            "The pain eases and allows you to move again.\n"+
           "  ___/~~=-,_\n"+
	   "     |~~  |       ~~=--,,_      _,,-=~| \n"+
	   "     |    |    /_         ~~=--/_    / \n"+
	   "     \    |   |__~~=--,_            / \n"+
	   "      \   |   /  ~~=-,_ ~~=-,__,,-=~ \n"+
	   "      \  |   /         ~=-,__,-=~ \n"+
	   "       \ |  / \n"+
	   "        \|_/ \n"+
	   "       < / >        _____   _   _   _____   _   _        __    __  _____   _   _  \n"+
	   "      _</_\>_      |  ___| | | | | /  ___| | | / /       \ \  / / /  _  \ | | | | \n"+
	   "    /       _ \    | |__   | | | | | |     | |/ /         \ \/ /  | | | | | | | | \n"+
	   "   /  _   /'_  \   |  __|  | | | | | |     | |\ \          \  /   | | | | | | | | \n"+
	   "  /  <O\   /O>  \  | |     | |_| | | |___  | | \ \         / /    | |_| | | |_| | \n"+
	   "  /  =��=,=��=  \  |_|     \_____/ \_____| |_|  \_\       /_/     \_____/ \_____/ \n"+
	   "  <    ::|::    > \n"+
	   "   \=--\_^_,--=/ \n"+
	   "      |    | \n");



    if(LEADER_D->test_leader(ob->query_real_name(), ob->query_race()))
        temp_str = "{inform}";
         else
        temp_str = "[inform]";

    temp_str = COLOURS->give_color(ob, "inform") + temp_str + OFF;

    tell_object(ob, temp_str+": "+ob->query_name()+" has been fucked by Yodin.\n");

    write("You fucked " + capitalize(name) + ".\n");
    return 1;
}
