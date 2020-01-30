status cmd_awardtp(string str)
{
object ob;
string name, reason, plural;
int points;

// Check wiz
if(this_player()->query_wiz()<3)
{ write("Only admins can award TPs.\n"); return 1; }

// Syntax
if (!str)
{ write("Syntax: award <name> <points> <reason>\n"); return 1; }

sscanf(str,"%s %d %s",name,points,reason);

if (!name || !points || !reason)
{ write("Syntax: awardtp <name> <points> <reason>\n"); return 1;}

// Find the player (must be logged in)
ob = find_living(name);
if (!ob)
{ write("No such player logged in '"+name+"'.\n"); return 1; }

// Check that the points value is OK
if(!(points>0 && points<10))
{ write("Points > 0, < 10.\n"); return 1; }
if(points==1) plural=""; else plural="s";

// Check that the reason is OK
if(strlen(reason)<4)
{ write("Not long enough reason.\n"); return 1; }

// Messages
write("You award "+capitalize(name)+" "+points+
" taskpoint"+plural+" for '"+reason+"'.\n");
tell_object(ob, this_player()->query_name()+
" awards you with "+points+" taskpoints"+plural+" for '"+reason+"'.\n");

// Shout
shout(this_player()->query_name()+" awards "+capitalize(name)+" "+points+
      " taskpoints"+plural+" for '"+reason+"'.\n");

// Log it
log_file("AWARD_QP", "Awarded by: "+this_player()->query_name()+", To: "+capitalize(name)+
" Amount: "+ points+" Reason: "+reason+".\n");

// Add the TPs
ob->add_task_points(points);

return 1;
}

