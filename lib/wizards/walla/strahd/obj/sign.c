short() { return "A sign on the road"; } 
 
long(str) {
    write("The sign is darkened, and covered with dust. As you take off the dust you see the script:\n");
    write("'Beware thiefs, I Strahd walk the land'.\n");
    return;
}
 
id(str) { return str == "sign"; }
 
get(str) {
    if (str == "sign") {
        write("You can't take the sign.\n");
        return 0;
    }
    return 0;
}
