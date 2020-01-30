#include "/sys/ansi.h"

int amount;

reset(arg) {
  if(arg) return;
}

short() {
  return "Brain Box";
}

id(str) {
  return str == "box";

}

long() {
  write("This box measures your brain capacity.\n"+
        "You should try to open it.\n");
}

get() {
	return 1;
}

query_weight() {
  return 1;
}

init() {

	add_action("open_box","open");
	add_action("query_idiot_amount","idiots");
}

open_box(string tmp) {
	
	if(!tmp) {
		write("Open what?\n");
		return 1;
	}
	if(tmp != "box") {
		write("Open what?\n");
		return 1;
	}
	
write("You are not the first one who tries to open this box you know?\n");

amount++;

if(interactive(find_player("astarel"))) {
	tell_object(find_player("astarel"), "Taman lootan on avannut "+amount+" idioottia\n");
	
}

return 1;
}
