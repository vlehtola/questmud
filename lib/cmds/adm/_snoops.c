/* SNOOPS - cmd by astarel 23.4.2004 */

status cmd_snoops() {

object *obs;
int i,j;

	if(this_player()->query_wiz() < 4) return 1;

	obs = users();
	
	for(i=0;i<sizeof(obs);i++) {
		
		for(j = 0;j<sizeof(obs);j++) {
			
			if(obs[i] == query_snoop(obs[j])) {
				write(capitalize(obs[i]->query_real_name())+" is snooping "+capitalize(obs[j]->query_real_name())+"\n");
			}
		}
		
	}
	
return 1;
}	