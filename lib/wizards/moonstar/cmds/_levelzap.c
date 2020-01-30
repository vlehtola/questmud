/* by Moonstar */

status cmd_levelzap(string str)
{
object ob;
string name, plural;
int explost;

// Check wiz
if(this_player()->query_wiz()<3)
{ write("Only admins can levelzap.\n"); return 1; }

// Syntax
if (!str)
{ write("Syntax: levelzap <name> <explost>\n"); return 1; }

sscanf(str,"%s %d %s",name,explost);

if (!name || !explost)
{ write("Syntax: levelzap <name> <explost>\n"); return 1;}

// Find the player (must be logged in)
ob = find_living(name);
if (!ob)
{ write("No such player logged in '"+name+"'.\n"); return 1; }

// Checks the explost
if(!(explost>1 && explost<500))
{ write("explost > 1, < 500.\n"); return 1; }
if(explost==1) plural=""; else plural="s";

// Messages
write("You levelzap "+capitalize(name)+" with explost worth of "+explost+"M.\n");
tell_object(ob, this_player()->query_name()+" zaps you. You feel like something leaves from your soul.\n");

// Shout
shout(
""+this_player()->query_name()+" grabs "+capitalize(name)+" from the ground and rips "+ob->query_objective()+" apart.\n");

// Log it
    log_file("NEW_ZAPS", this_player()->query_name() +
                ", " + extract(ctime(time()), 4, 15)+ " target: "+ob->query_name()+".\n",1);

// Lets levelzap.
ob->reduce_hp(66666);
ob->set_level(ob->query_level()-1);

return 1;
}


