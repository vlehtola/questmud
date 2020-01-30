short() { return "A partly rotten wooden sign"; }

long(str) {
    write("The sign is so rotten you can hardly tell what it reads:\n");
    write("'Tl.e El.ct?um mine o' Dura?g om'.\n");
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
