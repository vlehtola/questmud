/* THIS FILE IS NOT IN USE. /world/city/post.c is.  //Celtron */

inherit "room/room";

string messages;
int new_mail;

reset(arg) {
    if (arg)
	return;
    set_light(3);
    dest_dir = ({ "/world/city/mainstr4", "north" });
    short_desc = "The post office";
    long_desc = "You are in the post office. Commands:\n" +
	"read         Read from the mailbox.\n" +
	"mail <name>  Mail to player 'name'.\n" +
	"from         List all headers.\n";
    no_castle_flag = 1;
}

init() {
    ::init();
    move_object(clone_object("obj/mail_reader"), this_player());
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
    if (new_mail)
	new = " NEW";
        write("\nThere is" + new + " mail for you in the post office\n"+
        "   (n, e, e, n from inn).\n\n");
    }
    return 1;
}
