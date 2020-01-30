#include "/sys/ansi.h"

reset(arg) {
  if(arg) return;
}

short() {
  return "The Astarel Bonderos doll";
}

id(str) {
  return str == "doll";

}

long() {
  write("This doll looks like Astarel Bonderos, the famous actor.\n");
}

get() {
	return 1;
}

query_weight() {
  return 1;
}

init() {

	add_action("doll_bumb","bumb");
}

status doll_bumb() {
	
	
	tell_room(environment(this_player()),this_player()->query_name()+" bumbs the doll. BUMBS BUMBS BUMBS! Up and down\n"+
	                                                                   " she bumbs. Bumbs like doggies, bumbs like cats\n"+
	                                                                   " bumbs like villageidiot bumbs rats.\n");
return 1;
}
