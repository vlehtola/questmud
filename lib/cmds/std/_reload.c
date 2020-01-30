#define RELOAD_OB "/wizards/siki/reload_object"

cmd_reload(string str) {
int reload_time;
string wha, wit, fro;
object what, with, ob, from;
if(!str) { write("Usage: Reload <weapon> with <ammunition> from <inventory/quiver>\n"); return 1; }
if(sscanf(str, "%s with %s from %s", wha, wit, fro) != 3) { write("Usage: Reload <weapon> with <ammunition> from <inventory/quiver>\n"); return 1; }
what = present(wha, this_player());
if(!what) { write("You don't have such thing as '"+wha+"'.\n"); return 1; }
if(!what->is_shootable()) { write("You can't reload that.\n"); return 1; }
if(what->query_reload()) { write(what->short()+" is already reloaded!\n"); return 1; }
if(present("shoot_object", this_player())) { write("You can't reload the bow while shooting!\n"); return 1; }
from = present(fro, this_player());
if(fro == "inventory") {
with = present(wit, this_player());
} else if(fro == "quiver") {
with = present(wit, from);
}
if(!with) { write("There is not such thing.\n"); return 1; }
if(!with->query_arrow()) { write("Only arrows or bolts can be reloaded in something.\n"); return 1; }
if(what->query_missile_type() != with->query_missile_type()) { write("You can't load arrows in crossbows or bolts in bows.\n"); return 1; }
if(present("reload_object", this_player())) {
destruct(present("reload_object", this_player()));
write("You break previous reload.\n");
}
reload_time = what->query_reload_time();
reload_time -= get_str_bonus(this_player()->query_str());
reload_time -= get_dex_bonus(this_player()->query_dex());

write("You start to reloading your "+wha+" with "+wit+".\n");
say(this_player()->query_name()+" starts to reload the "+wha+".\n");
if(this_player()->query_attack()) {
write("It is much harder to consentrate reloading when fighting.\n");
	reload_time = reload_time*2;
}
reload_time=reload_time/3*2;
if(this_player()->query_wiz()) { write("Reload time is: "+reload_time+"\n"); }
ob = clone_object(RELOAD_OB);
move_object(ob, this_player());
ob->start_reload(what, with, reload_time);
return 1;
}

get_str_bonus(i) {
	switch(i) {
	case 0..20: return 1;
	case 21..40: return 2;
	case 41..50: return 3;
	case 51..80: return 4;
	case 81..100: return 5;
}
return 5;
}

get_dex_bonus(i) {
	switch(i) {
	case 0..40: return 1;
	case 41..80: return 2;
	case 81..100: return 3;
}
return 3;
}
