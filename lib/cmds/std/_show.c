#define USAGE "Usage: show (item) to (player)\n"

status cmd_show(string str) {
        string tmp,tmp2;
        object ob,tgt;
        if(!str) { write(USAGE); return 1; }
        str = lower_case(str);
        if(sscanf(str,"%s to %s",tmp,tmp2) != 2) {
                write(USAGE);
                return 1;
        }
        ob = present((lower_case(tmp)),this_player());
        tgt = present((lower_case(tmp2)),environment(this_player()));
        if(!ob || !tgt) {
                write(USAGE);
                return 1;
        }
        say(this_player()->query_name()+" shows "+ob->short()+" to "+tgt->query_name()+".\n");
        write("You show "+ob->short()+" to "+tgt->query_name()+".\n");
        tell_object(tgt,ob->query_long()+"");
        return 1;
}

