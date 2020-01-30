short() { return "The tower at Central Square"; } 
 
long(str) {
    write("The huge tower, made of granite and chalk stone erects itself out from mother Earth, like\n");
    write("a base pilar in the society.\n");
    return;
}
 
id(str) { return str == "tower"; }
 
get(str) {
    if (str == "tower") {
        write("Are you MAD trying to take a tower 10 times your size, you must be kidding!\n");
        return 0;
    }
    return 0;
}
