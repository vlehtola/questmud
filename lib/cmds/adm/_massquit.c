/* by Nalle '03 */

status cmd_massquit(string str)
{
int i;

object *userlist;

if(!str || this_player()->query_wiz() != 5) return 0;

if(str != "do_it") return 0;

userlist=users();

for(i=0 ; i < sizeof(userlist);i++) 
	if(userlist[i]->query_wiz() != 5)
	{
	write("Quitting "+capitalize(userlist[i]->query_real_name())+"\n");
	userlist[i]->quit();
	}

return 1;
}

