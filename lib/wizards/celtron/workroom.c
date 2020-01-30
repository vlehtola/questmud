#define COLOR sprintf("%c",27)+"[1;31m"
#define OFF sprintf("%c",27)+"[0m"
/* #define COLOR "^[[1;36m" */

inherit "/room/room";
string invited;
int bar;
object sha;

reset(arg) {
  if(arg) return;
  short_desc = "Celtron's workroom";
  long_desc = "A weird room where "+COLOR+"Celtron"+OFF+" works 25h/day.\n";
  add_exit("inn", "/world/city/inn");
  add_exit("cs", "/world/city/cs");
  add_exit("post", "/world/city/post");
  add_exit("fig", "/guilds/fighter/fighter");
  add_exit("outmap", "virtual /room/out/outmap 100 115");
}

init() {
    ::init();
    if (invited != lower_case(this_player()->query_name()) &&
            this_player()->query_name() != "Celtron" && bar == 1) {
        write("You are not invited.\n");
        say(this_player()->query_name() + " tried to enter.\n");
        this_player()->move_player("X#world/city/inn");
        return 1;
    }
/*    sha = clone_object("/wizards/celtron/varjo"); */
    add_action("invite", "invite");
    add_action("barrier", "barrier");
}
barrier() {
  if(this_player()->query_name() != "Celtron") {
    this_player()->hit_with_spell(query_hp()-1,7);
    this_player()->set_stunned(100);
    say(this_player()->query_name()+" gets a shock!\n");
    return 1;
  }
  if(bar == 1) {
    write("You lower the barrier.\n");
    bar = 0;
  } else {
    write("You raise the barrier.\n");
    bar = 1;
  }
  return 1;
}

invite(str) {
    if(this_player()->query_name() != "Celtron") {
        this_player()->hit_with_spell(query_hp()-1,7);
	this_player()->set_stunned(100);
	say(this_player()->query_name()+" gets a shock!\n");
	return 1;
    } 
    if (!str) { write("Invite who?\n"); return 1; }
    invited = str;
    write("You allow " + capitalize(str) + " to enter.\n");
    return 1;
}





