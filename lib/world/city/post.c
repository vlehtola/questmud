inherit "room/room";

string messages;
int new_mail;

reset(arg) {
    if (arg)
	return;
    dest_dir = ({ "/world/city/mainstr6", "south" });
    short_desc = "The post office";
    long_desc = 
	"You are in the old post office. Where mail used to be sent and received.\n"+
	"Nowadays that is done with the 'mail' command.\nCommands:\n" +

	"read         Read from the mailbox.\n" +
	//"mail <name>  Mail to player 'name'.\n" +
	"from         List all headers.\n";
    no_castle_flag = 1;
    property = allocate(4);
	property[0] = "no_kill";
	property[1] = "no_skill";
	property[2] = "no_spell";
	property[3] = "no_summon";
	set_not_out(1);
    set_light(3);
}

init() {
  ::init();
  move_object(clone_object("obj/mail_reader"), this_player());
  add_action("exit", "south");
}

exit() {
    object ob;
    if (ob = present("mailread", this_player()))
	destruct(ob);
}

query_mail(silent) {
    string name;
    string new;

    name = lower_case(call_other(this_player(), "query_name"));
    if (!restore_object("room/post_dir/" + name) || messages == "") return 0;
    if (silent) return 1;
    new = "";
    if (new_mail) {
	new = " NEW";
        write("\nThere is" + new + " mail for you in the post office\n"+
             "   (n,e,e,e,n from inn).\n\n");
    }
    return 1;
}

