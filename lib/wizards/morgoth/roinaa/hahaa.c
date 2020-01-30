short() { return "Sword of DESTRUCTION"; }

long(str) {
    write("This sword is for immortals only.\n");
    return;
}

id(str) { return str == "sword"; }

get(str) {
    if (str == "sword") {
        write("ZAP!\n");
        this_player()->reduce_hp(100);
    
    }
    return 0;
}

