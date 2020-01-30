short() { return "A sign is here"; }

long(str) {
    write("There is a sign.\n");
    write("It says: 'Welcome to Forlindon village'.\n");
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
