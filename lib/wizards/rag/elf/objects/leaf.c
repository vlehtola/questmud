init() {
  add_action("eat", "eat");
}

short() { return "A green leaf"; }

long(str) {
    write("This is a green leaf from some herbbush. It might\n"+
        "have healing powers. Maybe you should eat it?\n");
    return;
}

id(str) { return str == "leaf"; }

get() {
    return 1;
}

query_weight() {
  return 1;
}

eat(str) {
        if(present(str) == this_object()) {
                write("You eat the leaf.\n");
                say(this_player()->query_name()+" eats a leaf.\n");
                cure();
                destruct(this_object());
                return 1;
        }
        return;
}

cure() {
        object tar;
        int hp,maxhp;
        int sp,maxsp;
        int ep,maxep;
        tar = this_player();
        hp = tar->query_hp();
        maxhp = tar->query_max_hp();
        sp = tar->query_sp();
        maxsp = tar->query_max_sp();
        ep = tar->query_ep();
        maxep = tar->query_max_ep();
        if(hp<maxhp) {
                tar->set_hp(hp+500);
                hp = tar->query_hp();
                if(hp>maxhp) tar->set_hp(maxhp);
        }
        if(sp<maxsp) {
                tar->set_sp(sp+500);
                sp = tar->query_sp();
                if(sp>maxsp) tar->set_sp(maxsp);
        }
        if(ep<maxep) {
                tar->set_ep(ep+200);
                ep = tar->query_ep();
                if(ep>maxep) tar->set_ep(maxep);
        }
        write("You feel refreshed and ready to continue adventuring!\n");
        say(tar->query_name()+" looks much better.\n");
}
