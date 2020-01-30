long() {
    write(short()+" given to married couples.\n");
}

reset(arg) {
    if (arg)
        return;
}

init() {
add_action("smell","smell");
}

int smell(string str) {
if(!((str == "flowers") || (str != "bouquet")) ) return 0;
write("You smell the flowers. Aahh, lovely.\n");
say(this_player()->query_name()+ " smells a bouquet a flowers.\n");
return 1;
}

query_weight() { return 5; }

short() { return "A lovely bouquet of flowers"; }

id(str) { return ((str == "bouquet") || (str == "flowers")); }

query_value() { return 21; }

get() { return 1; }

